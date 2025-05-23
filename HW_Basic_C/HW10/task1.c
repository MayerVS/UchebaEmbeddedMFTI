#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *r, *w;
	char c[100];
	int len = 0;
	r = fopen("input.txt", "r");
	w = fopen("output.txt", "w");
	while(fscanf(r, "%s", c+len) == 1)
	{
		len = strlen(c);
		c[len++] = ' ';
	}
	c[--len] = '\0';
	for(int i = 0; i < 3; i++)
	{
		fprintf(w ,"%s", c);
		if(i != 2)
			fprintf(w ,", ");
	}
	fprintf(w ," %d", len);
	fclose(r);
	fclose(w);
	return 0;
}

