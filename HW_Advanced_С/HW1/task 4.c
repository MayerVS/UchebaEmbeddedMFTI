/*
 * task 4.c
 * 
 * Copyright 2025 Владимир Майер <vladimirmajer@MacBook-Air-Vladimir.local>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdint.h>

uint16_t aSize(uint32_t a)
{
	uint16_t Size = 0;
	for(int i = 0; i < 32; i++)
	{
		if((a >> i) & 1)
			Size = i+1;
	}
	return Size;
}

uint32_t MaxKBit(uint32_t a, uint32_t K, uint16_t Size)
{
	uint32_t Max = 0;
	if (Size <= K)
	{
		Max = a;
	}
	else
	{
		for(int i = 0; i < (Size - K + 1); i++)
		{
			uint32_t localMax = (a & ((0xFFFFFFFF >> (32 - K)) << (Size - K - i))) >> (Size - K - i);
			//printf("%u %u %u %u %u\n", a, K, Size, i, localMax);
			if (Max < localMax)
				Max = localMax;
		}
	}
	return Max;
}


int main(int argc, char **argv)
{
	uint32_t a, K;
	scanf("%u", &a);
	scanf("%u", &K);
	a = MaxKBit(a, K, aSize(a));
	printf("%u", a);
	return 0;
}

