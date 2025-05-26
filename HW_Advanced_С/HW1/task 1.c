#include <stdio.h>
#include <stdint.h>


int main (void)
{
	char c;
	uint32_t shift = 0;

	while(((c = getchar()) >= '0') && (c <= '9'))
	{
		shift *= 10;
		shift += ((uint32_t)c - 48);
	}
	
	do
	{
		if(c >= 'a' && c <= 'z') 
		{
			c -= 'a';
			putchar(((c + shift)%('z'-'a' + 1)) + 'a');
		}
		else if (c >= 'A' && c <= 'Z')
		{
			c -= 'A';
			putchar(((c + shift)%('z'-'a' + 1)) + 'A');
		}
		else
			putchar(c);
	} 
	while((c = getchar()) != EOF);
	
}
