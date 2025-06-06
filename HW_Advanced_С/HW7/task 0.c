#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
char word[20];
struct list *next;
};

void add_to_list(char word[], struct list **p)
{
	if(*p == NULL)
	{
		*p = malloc(sizeof(struct list));
		strcpy((*p)->word, word);
		(*p)->next = NULL;
	}
	else
	{
		(*p)->next = malloc(sizeof(struct list));
		strcpy((*p)->next->word, word);
		(*p)->next->next = NULL;
	}

	*p = (*p)->next;
}

void swap_elements(struct list **p)
{
	char copy[20];
	strcpy(copy, (*p)->word);
	strcpy((*p)->word, (*p)->next->word);
	strcpy((*p)->next->word, copy);
}

void print_list(struct list *p)
{
	while(p)
	{
		printf("%s", p->word);
		printf(" ");
		p = p->next;
	}
	
}

void delete_list(struct list **p)
{
	struct list *del = *p;
	*p = (*p)->next;
	free(del);
}

int main(int argc, char **argv)
{
	struct list *first = malloc(sizeof(struct list)), *current = first;
	int flag = 1, i = 0;
	char word[20], c = ' ';
	
	while(c != '.')
	{
		c = getchar();
		if(c != ' ')
			word[i] = c;
		i++;
		if(c == ' ' || c == '.')
		{
			word[i-1] = '\0';
			add_to_list(word , &current);
			i = 0;
		}
	}

	delete_list(&first);
	current = first;
	
	while(flag)
	{
		flag = 0;
		while(current->next)
		{
			if(strcmp(current->word, current->next->word) > 0)
			{
				swap_elements(&current);
				flag = 1;
			}		
			current = current->next;	
		}
		current = first;
	}
	
	
	print_list(first);
	
	while(first)
		delete_list(&first);
	
	return 0;
}

