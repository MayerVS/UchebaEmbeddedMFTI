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

#define LENGHT 5

void sort_array(int size, int a[])
{
	int b, sort = 0;
	for(int j = size-1; j>0; j--)
	{
		for(int i = size-1; i>0; i--)
		{
			if(a[i]<a[i-1])
			{
				b = a[i];
				a[i] = a[i-1];
				a[i-1] = b;
				sort++;
			}
		}
		if (sort == 0)
			return;
	}
	printf("Sorting complate\n");
}

void sort_even_odd(int n, int a[])
{
	int iChet = 0, b;
	for (int i = 0; i < n; i++)
	{
		if(a[i] % 2 == 0 && i == iChet)
		{
			iChet = i + 1;
			printf("1 a0 = %d; a1 = %d; a2 = %d; a3 = %d; a4 = %d\n; i = %d; ichet = %d\n", a[0], a[1], a[2], a[3], a[4], i, iChet);
		}
		else if(a[i] % 2 == 0 && i > iChet)
		{
			b = a[i];
			printf("2 a0 = %d; a1 = %d; a2 = %d; a3 = %d; a4 = %d\n; i = %d; ichet = %d\n", a[0], a[1], a[2], a[3], a[4], i, iChet);
			for (int j = i-1; j >= iChet; j--)
			{
				printf("3 a0 = %d; a1 = %d; a2 = %d; a3 = %d; a4 = %d\n; j = %d; ichet = %d\n", a[0], a[1], a[2], a[3], a[4], j, iChet);
				a[j+1] = a[j];
			}
			a[iChet++] = b;
		}
	}
	printf("Sorting complate\n");
}

void Scanf(int *a, int size)
{
	int *q = a;
	for(int i = size; i>0; i--)
		scanf("%d", q++);
	printf("Scan complete\n");
}

void Printf(int *a, int size)
{
	for(int i = size; i>0; i--)
		printf("%d ", *(a++));
	printf("\nPrint complete\n");
}

int main(int argc, char **argv)
{
	printf("Enter five numbers\n");
	int a[LENGHT];
	Scanf(a, LENGHT);
	sort_even_odd(LENGHT, a);
	Printf(a, LENGHT);
}
