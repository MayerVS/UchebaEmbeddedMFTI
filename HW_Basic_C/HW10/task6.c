
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char s[1000];
	int len = 0, flag = 0;
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
	
	for(int i = 0; i < len/2; i++)
	{
		if(s[i] != s[len-1-i])
		{
			flag++;
			break;
		}
	}
	
	(flag == 0) ? fprintf(w, "YES") : fprintf(w, "NO");
		
	fclose(r);
	fclose(w);
	return 0;
}
