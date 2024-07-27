
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char s1[100], s2[100];
	int s1Len, s2Len, flag1, flag2;
	FILE *w, *r;
	r = fopen("input.txt", "r");
	w = fopen("output.txt", "w");
	
	fscanf(r, "%s %s", s1, s2);
	
	s1Len = strlen(s1);
	s2Len = strlen(s2);
	
	for(int i = 0; i < s1Len; i++)
	{
		flag1 = 0;
		flag2 = 0;
		
		for(int k = 0; k < s1Len; k++)
			if(s1[i] == s1[k] && i != k)
				flag1++;
				
		if (flag1 == 0)
			for(int j = 0; j < s2Len; j++)
				if(s1[i] == s2[j])
					flag2++;
					
		if (flag1 == 0 && flag2 == 1)	
			fprintf(w, "%c ", s1[i]);
			
	}
	
	fclose(r);
	fclose(w);
	return 0;
}

