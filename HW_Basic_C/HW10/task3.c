#include <stdio.h>
#include <string.h>


int main(int argc, char **argv)
{
	FILE *r, *w;
	int lastCNomber;
	char lastC, c;
	r = fopen("input.txt", "r");
	w = fopen("output.txt", "w");
	
	if(fseek(r, -2, SEEK_END) != 0)  // для мака и линукса -1 для винды -2  
	{
		printf("error");
		return 0;
	}
	
	lastC = fgetc(r);
	lastCNomber = ftell(r);
	
	if(fseek(r, 0, SEEK_SET) != 0)
	{
		printf("error");
		return 0;
	}
	
	for(int i = 0; i < lastCNomber - 1; i++)
	{
		c = fgetc(r);
		if (c == lastC)
		{
			fprintf(w, "%d ", i);
		}
	}
	fclose(r);
	fclose(w);
	return 0;
}
