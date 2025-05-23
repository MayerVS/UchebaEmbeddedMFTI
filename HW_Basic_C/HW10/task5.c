
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char s[1000];
	int len = 0;
	FILE *w, *r;
	r = fopen("input.txt", "r");
	w = fopen("output.txt", "w");
	
	while(fscanf(r, "%s", s+len) == 1)
	{
		len = strlen(s);
		s[len++] = ' ';
	}
	s[--len] = '\0';
	
	printf("%s\n", s);
	
	for(int i = 0; i < len; i++)
	{
		if(s[i] == 'A' || s[i] == 'a')
			s[i] += 0x1;		
		else if(s[i] == 'B' || s[i] == 'b')
			s[i] -= 0x1;
	}
	
	fprintf(w, "%s", s);
	printf("%s", s);
		
	fclose(r);
	fclose(w);
	return 0;
}
