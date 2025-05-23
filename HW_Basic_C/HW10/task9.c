#include <stdio.h>
#include <string.h>

void sort(int a[], int len)
{
	int mem;
	for(int j = 0; j < len - 1; j++)
	{
		for(int i = 0; i < len - 1 - j; i++)
		{
			if(a[i] > a[i+1])
			{
				mem = a[i];
				a[i] = a[i+1];
				a[i+1] = mem;
			}
		}
	}
}

void output(int a[], int len)
{
	for(int j = 0; j < len; j++)
	{
		printf("%d ", a[j]);
	}	
}

void foutput(FILE *f, int a[], int len)
{
	for(int j = 0; j < len; j++)
	{
		fprintf(f, "%d ", a[j]);
	}	
}

int main(int argc, char **argv)
{
	FILE *r, *w;
	int i = 0, k = 0, flag = 0;
	char c[1000], p[100];
	
	r = fopen("input.txt", "r");
	w = fopen("output.txt", "w");
	
	while((c[i] = fgetc(r)) != EOF)
	{
		printf("%s, i = %d\n", c, i);
		if(c[i] == ' ')
			i--;
		else
		{
			for(int j = 0; j < k; j++)
				if(c[i] == p[j])
					flag = 1;
			if (flag == 1)
			{
				i--;
				flag = 0;
			}
			else
			{
				p[k++] = c[i];
				printf("p[%d] = %c, k = %d\n",k-1,p[k-1], k);
			}
		}
		i++;
	}
	c[i] = '\0';
	fprintf(w, "%s", c);
	printf("%s", c);
		
	fclose(r);
	fclose(w);
	return 0;
}

