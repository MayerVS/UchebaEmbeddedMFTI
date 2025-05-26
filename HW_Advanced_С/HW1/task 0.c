#include <stdio.h>
#include <stdint.h>


int main (void)
{
	uint32_t size = 0,  counter = 1;
	int64_t N = 0, max = ((int64_t)1 << 63);
	scanf("%d", &size);
	for(uint64_t i = 0; i < size; i++)
	{
		scanf("%lld", &N);
		if(N > max)
		{
			max = N;
			counter = 1;
		}
		else
		{
			if(!(N^max)) 
				counter++;
				//printf("%d %lld %lld\n", counter, max, N);
		}
	}
	printf("%d", counter);
}
