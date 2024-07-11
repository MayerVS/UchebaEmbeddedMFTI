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

#define LENGHT 10

void Input(int arr[], int lenght)
{
	for(int i = 0; i < lenght; i++)
		scanf("%d", &arr[i]);
}

void Output(int arr[], int lenght)
{
	for(int i = 0; i < lenght; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int *MinMax(int arr[], int lenght)
{
	int min = arr[lenght-1], nummin = lenght, max = arr[lenght-1], nummax = lenght;
	for(int i = lenght-1; i > 0; i--)
	{
		if (arr[i-1]>=max)
		{
			max = arr[i-1];
			nummax = i;
		}
		if (arr[i-1]<=min)
		{
			min = arr[i-1];
			nummin = i;
		}
	}
	static int otveti[4];
	otveti[0] = nummax;
	otveti[1] = max;
	otveti[2] = nummin;
	otveti[3] = min;
	return otveti;
}

int main(int argc, char **argv)
{
	int arr[LENGHT], otveti[4], *otve;
	Input(arr, LENGHT);
	otve = MinMax(arr, LENGHT);
	for(int i = 0; i<4; i++)
	{
		otveti[i] = *(otve+i);
	}
	Output(otveti, 4);
	return 0;
}

