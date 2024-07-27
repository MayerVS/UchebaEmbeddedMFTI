#include <stdio.h>
#include <string.h>


int main(int argc, char **argv)
{
	FILE *r, *w;
	int I = 0, i = 0;
	char c;
	
	r = fopen("input.txt", "r");
	w = fopen("output.txt", "w");
	
	while((c = fgetc(r)) != '\n')
	{
		if (c >= 'A' && c <= 'Z')
			I++;
		else if(c >= 'a' && c <= 'z')
			i++;
	}
	
	fprintf(w, "%d %d", i, I);
	
	fclose(r);
	fclose(w);
	return 0;
}

