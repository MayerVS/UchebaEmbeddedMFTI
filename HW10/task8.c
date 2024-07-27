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
	int i = 0, k = 0, flag = 0, cifr[1000] = {0};
	char c[1000], s;
	
	r = fopen("input.txt", "r");
	w = fopen("output.txt", "w");
	
	while((s = fgetc(r)) != EOF)
	{
		if(s >= '0' && s <= '9')
		{
			c[i++] = s;
			flag = 1;
		}
		if(flag == 1 && (s < '0' || s > '9'))
		{
			for(int j = 0; j < i; j++)
			{
				cifr[k] = cifr[k] * 10 + (c[j] - 0x30);
			}
			k++; 
			i = 0;
			flag = 0;
		}
	}
	
	sort(cifr, k);
	foutput(w, cifr, k);
		
	fclose(r);
	fclose(w);
	return 0;
}
