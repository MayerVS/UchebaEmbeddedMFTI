#include <stdio.h>
#include <string.h>

int finput(FILE *f, char c[], int kord[])
{
	int len = 0, words = 0;
	while(fscanf(f, "%s", c+len) == 1)
	{
		len = strlen(c);
		kord[words] = len;
		words++;
		c[len++] = ' ';
	}
	c[--len] = '\0';
	return words;
}

void foutput(FILE *f, char c[], int kord_n, int kord_k)
{
	for(int i = kord_n; i < kord_k; i++)
		fputc(c[i], f);
}

void schet(int words, int kord[], int len[])
{
	len[0] = kord[0]+1;
	for(int i = 1; i < words; i++)
	{
		len[i] = kord[i] - kord[i-1] - 1;
	}
}

int maximum(int words, int len[])
{
	int max = len[0], maxi = 0;
	for (int i = 1; i < words; i++)
	{
		if (len[i] > max)
		{
			max = len[i];
			maxi = i;
		}
	}
	for (int i = 1; i < words; i++)
		if (len[i] == max && i != maxi)
			return -1;
	return maxi;
}

int main(int argc, char **argv)
{
	FILE *r, *w;
	int kord[1000], words, len[1000], max;
	char c[1000];
	
	r = fopen("input.txt", "r");
	w = fopen("output.txt", "w");
	
	words = finput(r, c, kord);
//	printf("text: %s\n", c);
	schet(words, kord, len);
//	printf("words: %d\nkord[0] = %d, kord[1] = %d, kord[2] = %d,\n", words, kord[0], kord[1], kord[2]);
//	printf("len[0] = %d, len[1] = %d, len[2] = %d,\n",len[0], len[1], len[2]);
	max = maximum(words, len);
//	printf("max: %d\n", max);
//	printf("kord: %d, %d\n", 0, kord[max]);
//	printf("nacalo: %c, konec: %c\n", c[0], c[kord[max]]);
	
	if (max == 0)
		foutput(w, c, 0, kord[max]);
	else if (max == -1)
		fputc(' ', w);
	else
		foutput(w, c, kord[max-1]+1, kord[max]);
	
	fclose(r);
	fclose(w);
	return 0;
}


