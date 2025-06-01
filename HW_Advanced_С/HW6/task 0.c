#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  2
double DELAY = 0.1;
#define PLAYERS  2

enum { LEFT = 1, UP, RIGHT, DOWN, STOP_GAME = KEY_F(10), START_GAME = KEY_F(1)};
enum { MAX_TAIL_SIZE = 100, START_TAIL_SIZE = 3, MAX_FOOD_SIZE = 20, FOOD_EXPIRE_SECONDS = 10, SEED_NUMBER = 3, CONTROLS = 3 };


// Здесь храним коды управления змейкой
struct control_buttons
{
	int down;
	int up;
	int left;
	int right;
} control_buttons;

struct control_buttons default_controls[CONTROLS] = { {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT},
												{'s', 'w', 'a', 'd'}, 
												{'S', 'W', 'A', 'D'}
												};

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
	struct tail_t* tail;
	struct control_buttons controls;
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
	struct food init = { 0,0,0,0,0 };
	for (size_t i = 0; i < size; i++)
	{
		f[i] = init;
	}
}
/*
Обновить/разместить текущее зерно на поле
*/
void putFoodSeed(struct food* fp)
{
	int max_x = 0, max_y = 0;
	char spoint[2] = { 0 };
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
	for (size_t i = 0; i < number_seeds; i++)
	{
		putFoodSeed(&f[i]);
	}
}

void refreshFood(struct food f[], int nfood)
{
	for (size_t i = 0; i < nfood; i++)
	{
		if (f[i].put_time)
		{
			if (!f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS)
			{
				putFoodSeed(&f[i]);
			}
		}
	}
}
void initTail(struct tail_t t[], size_t size)
{
	struct tail_t init_t = { 0,0 };
	for (size_t i = 0; i < size; i++)
	{
		t[i] = init_t;
	}
}
void initHead(struct snake_t* head, int x, int y)
{
	head->x = x;
	head->y = y;
	head->direction = RIGHT;
}
//========================================================================
void initSnake(snake_t* head[], size_t size, int x, int y, int i)
{
	head[i] = (snake_t*)malloc(sizeof(snake_t));
	tail_t* tail = (tail_t*)malloc(MAX_TAIL_SIZE * sizeof(tail_t));
	initTail(tail, MAX_TAIL_SIZE);
	initHead(head[i], x, y);
	head[i]->tail = tail; // прикрепляем к голове хвост
	head[i]->tsize = size + 1;
	//~ head[i]->controls = default_controls[i];
	head[i]->controls = default_controls[i];
}

/*
Движение головы с учетом текущего направления движения
*/
void go(struct snake_t* head)
{
	char ch = '@';
	mvprintw(head->y, head->x, " "); // очищаем один символ
	switch (head->direction)
	{
	case LEFT:
		mvprintw(head->y, --(head->x), "%c", ch);
		break;
	case RIGHT:
		mvprintw(head->y, ++(head->x), "%c", ch);
		break;
	case UP:
		mvprintw(--(head->y), head->x, "%c", ch);
		break;
	case DOWN:
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

/*
Движение хвоста с учетом движения головы
*/
void goTail(struct snake_t* head)
{
	char ch = '*';
	mvprintw(head->tail[head->tsize - 1].y, head->tail[head->tsize - 1].x, " ");
	for (size_t i = head->tsize - 1; i > 0; i--)
	{
		head->tail[i] = head->tail[i - 1];
		if (head->tail[i].y || head->tail[i].x)
			mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
	}
	head->tail[0].x = head->x;
	head->tail[0].y = head->y;
}

//========================================================================
//Проверка того, является ли какое-то из зерен съеденным,
_Bool haveEat(struct snake_t* head, struct food f[])
{
	for (size_t i = 0; i < SEED_NUMBER; i++)
	{
		if (head->x == f[i].x && head->y == f[i].y)
			return 1;
	}
	return 0;
}

/*
Увеличение хвоста на 1 элемент
*/

void addTail(struct snake_t* head)
{
	(head->tsize)++;
	int i = head->tsize;
	head->tail[i - 1] = head->tail[i - 2];
}
//========================================================================
int checkDirection(snake_t* snake, int32_t key)
{

	if (key == snake->controls.down)
	{
		if (snake->direction != UP)
			return changeDirection(snake, DOWN);
		return 0;
	}
	else if (key == snake->controls.up)
	{
		if (snake->direction != DOWN)
			return changeDirection(snake, UP);
		return 0;
	}
	else if (key == snake->controls.right)
	{
		if (snake->direction != LEFT)
			return changeDirection(snake, RIGHT);
		return 0;
	}
	else if (key == snake->controls.left)
	{
		if (snake->direction != RIGHT)
			return changeDirection(snake, LEFT);
		return 0;
	}
	return 0;

}

int isCrush(snake_t* sneak[], snake_t* head)
{
	int max_x = 0, max_y = 0;
	getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
	// Выход за карту
	if (head->x <= 0 || head->x >= max_x - 1 || head->y <= 0 || head->y >= max_y - 1)
		return 1;
	for (int j = 0; j < PLAYERS; j++)
	{
		for (size_t i = 1; i < sneak[j]->tsize; i++)
			if(sneak[j]->tail[i].x == head->x && sneak[j]->tail[i].y == head->y)
				return 1;
		for (int k = j+1; k < PLAYERS; k++)
			if(sneak[j]->x == sneak[k]->x && sneak[j]->y == sneak[k]->y)
				return 2;
	}
	return 0;
}

void repairSeed(struct food f[], size_t nfood, struct snake_t* head)
{
	for (size_t i = 0; i < head->tsize; i++)
		for (size_t j = 0; j < nfood; j++)
		{
			if(head->tail[i].x == f[j].x && head->tail[i].y == f[j].y)
				refreshFood(food, SEED_NUMBER);
		}
	for (size_t i = 0; i < nfood; i++)
		for (size_t j = i + 1; j < nfood; j++)
		{
			if(f[i].x == f[j].x && f[i].y == f[j].y)
				refreshFood(food, SEED_NUMBER);
		}
}
//========================================================================

//Вынести тело цикла while из int main() в отдельную функцию update
//и посмотреть, как изменится профилирование
void update(struct snake_t* head[], int* key_pressed)
{
	*key_pressed = getch(); // Считываем клавишу
	for (int i = 0; i < PLAYERS; i++)
	{

		clock_t begin = clock();
		go(head[i]);
		goTail(head[i]);
		checkDirection(head[i], *key_pressed);
		refreshFood(food, SEED_NUMBER);// Обновляем еду
		if (haveEat(head[i], food))
		{
			addTail(head[i]);
		}
		refresh();//Обновление экрана, вывели кадр анимации
		while ((double)(clock() - begin) / CLOCKS_PER_SEC < DELAY)
		{
		}
		
		int flag = isCrush(head ,head[i]);
		if(flag == 1)
		{

			for (int j = head[i]->tsize - 1; j >= 0; j--)
			{
				mvprintw(head[i]->tail[j].y, head[i]->tail[j].x, " ");
			}

			free(head[i]->tail);
			free(head[i]);
			initSnake(head, START_TAIL_SIZE, 10 + i * 10, 10 + i * 10, i);
		}
		if(flag == 2)
		{
			for (int j = 0; j < PLAYERS; j++)
			{
				for (int k = head[j]->tsize - 1; k >= 0; k--)
				{
					mvprintw(head[j]->tail[k].y, head[j]->tail[k].x, " ");
				}
				
				free(head[j]->tail);
				free(head[j]);
				initSnake(head, START_TAIL_SIZE, 10 + j * 10, 10 + j * 10, j);
			}
		}
		
		repairSeed(food, SEED_NUMBER, head[i]);
	}
}
//========================================================================





int main()
{
	//========================================================================   
	snake_t* snakes[PLAYERS];
	for (int i = 0; i < PLAYERS; i++)
		initSnake(snakes, START_TAIL_SIZE, 10 + i * 10, 10 + i * 10, i);
	//========================================================================

	initscr();
	keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
	raw();                // Откдючаем line buffering
	noecho();            // Отключаем echo() режим при вызове getch
	curs_set(FALSE);    //Отключаем курсор
	mvprintw(1, 0, "Press 'F10' for EXIT");
	mvprintw(2, 0, "Press 'F0' for START");
	mvprintw(3, 0, "Control 1: wasd");
	mvprintw(4, 0, "Control 2: arrows");
	mvprintw(5, 0, "You can't crash into the end of the map and the opponent.");
	timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
	int key_pressed = 0;
	while (!(key_pressed == START_GAME || key_pressed == STOP_GAME))
	{
		key_pressed = getch(); // Считываем клавишу
		clock_t begin = clock();
		while ((double)(clock() - begin) / CLOCKS_PER_SEC < DELAY)
		{
		}
	}
	mvprintw(1, 0, "                                                          ");
	mvprintw(2, 0, "                                                          ");
	mvprintw(3, 0, "                                                          ");
	mvprintw(4, 0, "                                                          ");
	mvprintw(5, 0, "                                                          ");
	
	initFood(food, MAX_FOOD_SIZE);
	putFood(food, SEED_NUMBER);// Кладем зерна
	while (key_pressed != STOP_GAME)
	{
		update(snakes, &key_pressed);
	}
	for (int i = 0; i < PLAYERS; i++)
	{
		//printExit(snakes[i]);
		free(snakes[i]->tail);
		free(snakes[i]);
	}
	endwin(); // Завершаем режим curses mod
	return 0;
}
