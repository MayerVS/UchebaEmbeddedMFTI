#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  2
#define CONTROLS 3

enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10), START_GAME = KEY_F(1)};

enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=10, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10,SEED_NUMBER=3};
// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
}control_buttons;


struct control_buttons default_controls[] = {
	{KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT},
	{'S', 'W', 'A', 'D'},
	{'s', 'w', 'a', 'd'}};
	

/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons controls[CONTROLS];
} snake_t;
/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;
/*
 Еда — это массив точек, состоящий из координат x,y, времени,
 когда данная точка была установлена, и поля, сигнализирующего,
 была ли данная точка съедена.
 */
struct food
{
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];
void initFood(struct food f[], size_t size)
{
    struct food init = {0,0,0,0,0};
    for(size_t i=0; i<size; i++)
    {
        f[i] = init;
    }
}
/*
 Обновить/разместить текущее зерно на поле
 */
void putFoodSeed(struct food *fp)
{
    int max_x=0, max_y=0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % (max_x - 1);
    fp->y = rand() % (max_y - 2) + 1; //Не занимаем верхнюю строку
    fp->put_time = time(NULL);
    fp->point = '$';
    fp->enable = 1;
    spoint[0] = fp->point;
    mvprintw(fp->y, fp->x, "%s", spoint);
}
/*
 Разместить еду на поле
 */
void putFood(struct food f[], size_t number_seeds)
{
    for(size_t i=0; i<number_seeds; i++)
    {
        putFoodSeed(&f[i]);
    }
}
void refreshFood(struct food f[], int nfood)
{
    for(size_t i=0; i<nfood; i++)
    {
        if( f[i].put_time )
        {
            if( !f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS )
            {
                putFoodSeed(&f[i]);
            }
        }
    }
}
void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t={0,0};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}
void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}
void initSnake(snake_t *head, size_t size, int x, int y)
{
tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size+1;
    for(int i = 0; i < CONTROLS; i++)
	{
		head->controls[i] = default_controls[i];
	}
}
/*
 Движение головы с учетом текущего направления движения
 */
void go(struct snake_t *head, uint16_t* stopGameFlag)
{
    char ch = '@';
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ
    switch (head->direction)
    {
        case LEFT:
            if(head->x <= 0) 
                *stopGameFlag = 0;
            mvprintw(head->y, --(head->x), "%c", ch);
        break;
        case RIGHT:
			if(head->x >= max_x-1)
				*stopGameFlag = 0;
            mvprintw(head->y, ++(head->x), "%c", ch);
        break;
        case UP:
			if(head->y <= 0) 
                *stopGameFlag = 0;
            mvprintw(--(head->y), head->x, "%c", ch);
        break;
        case DOWN:
			if(head->y >= max_y -1) 
				*stopGameFlag = 0;
            mvprintw(++(head->y), head->x, "%c", ch);
        break;
        default:
        break;
    }
    refresh();
}
int changeDirection(struct snake_t* snake, int32_t dir)
{
		if (dir == DOWN)
		{
			snake->direction = DOWN;
			return 1;
		}
		else if (dir == UP)
		{
			snake->direction = UP;
			return 1;
		}
		else if (dir == RIGHT)
		{	
			snake->direction = RIGHT;
			return 1;
		}
		else if (dir == LEFT)
		{
			snake->direction = LEFT;
			return 1;
	}
	return 0;
}

int checkDirection(snake_t* snake, int32_t key)
{
	for(int i = 0; i < CONTROLS; i++)
	{
		if (key == snake->controls[i].down)
		{
			if(snake->direction != UP)
				return changeDirection(snake, DOWN);
			return 0;
		}
		else if (key == snake->controls[i].up)
		{
			if(snake->direction != DOWN)
				return changeDirection(snake, UP);
			return 0;
		}
		else if (key == snake->controls[i].right)
		{	
			if(snake->direction != LEFT)
				return changeDirection(snake, RIGHT);
			return 0;
		}
		else if (key == snake->controls[i].left)
		{
			if(snake->direction != RIGHT)
				return changeDirection(snake, LEFT);
			return 0;
		}
	}
	return 0;
}

/*
 Движение хвоста с учетом движения головы
 */
void goTail(struct snake_t *head, uint16_t* stopGameFlag)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    for(size_t i = head->tsize-1; i>0; i--)
    {
    
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
        {
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
            if(head->tail[i].x == head->x && head->tail[i].y == head->y)
				*stopGameFlag = 0;
        }
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
    refresh();
}
int main()
{
	clock_t last_time = 0;
	uint16_t stopGameFlag = 1;
	snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
    initSnake(snake,START_TAIL_SIZE,10,10);

    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    mvprintw(0, 1,"Use arrows for control. Press 'F10' for EXIT. Press 'F1' for start");
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    initFood(food, MAX_FOOD_SIZE);
    putFood(food, SEED_NUMBER);// Кладем зерна
    int key_pressed=0;
    while(key_pressed != STOP_GAME && key_pressed != START_GAME)
    {
		 key_pressed = getch(); // Считываем клавишу
		 last_time = clock();
		 while(clock() - last_time < (clock_t)(0.1f*CLOCKS_PER_SEC))
		 {
		 }
	}
	mvprintw(0, 1,"                                                                          ");
    while( key_pressed != STOP_GAME && stopGameFlag )
    {
        key_pressed = getch(); // Считываем клавишу
        go(snake, &stopGameFlag);
        goTail(snake, &stopGameFlag);
        
        last_time = clock();
		while(clock() - last_time < (clock_t)(0.1f*CLOCKS_PER_SEC))
		{
		}
		checkDirection(snake, key_pressed);
        refreshFood(food, SEED_NUMBER);// Обновляем еду
    }
    free(snake->tail);
    free(snake);
    endwin(); // Завершаем режим curses mod
    return 0;
}
