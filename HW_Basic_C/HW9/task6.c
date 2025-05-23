/*
 * task1.c
 * 
 * Copyright 2024 Владимир Майер <vladimirmajer@MacBook-Air-Vladimir.local>
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

#define SIZE 70

int is_two_same(int size, int a[])
{
	int numb[300], k = 0;
	for(int j = 0; j < size; j++)
	{
		for(int i = 0; i<k; i++)
		{
			if (a[j] == numb[i])
			{
//				printf("i = %d, j = %d, a[%d] = %d, numb[%d] = %d\n", i, j, j, a[j], i, numb[i]);
				return 1;
			}
		}
		numb[k++] = a[j];
	}
	return 0;
}

int main(int argc, char **argv)
{
	int max, a[SIZE];
	for(int i = 0; i<SIZE; i++)
		scanf("%d", &a[i]);
	max = is_two_same(SIZE, a);
	printf("%d", max);
	
}

