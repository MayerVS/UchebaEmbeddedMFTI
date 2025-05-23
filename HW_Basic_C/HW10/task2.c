#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *r, *w;
	int len;
	r = fopen("input.txt", "r");
	w = fopen("output.txt", "w");
	fscanf(r, "%d", &len);
	for(int i = 0; i < len; i++)
	{
		if(i % 2 == 0)
		{
		fputc('A' + i/2, w);
		}
		else
		{
		fputc('2' + ((i-1) % 8), w);
		}
	}
	fclose(r);
	fclose(w);
	return 0;
}
