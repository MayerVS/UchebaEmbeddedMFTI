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

void swap_negmax_last(int size, int a[])
{
	int flag = 0, min, imin, b;
	for(int i = 0; i<size; i++)
	{
		if(flag == 0 && a[i] < 0)
		{
			min = a[i];
			imin = i;
			flag++;
		}
		if(flag == 1 && a[i] > min && a[i] < 0)
		{
			min = a[i];
			imin = i;
		}
	}
	if(flag == 1)
	{
		b = a[imin];
		a[imin] = a[size-1];
		a[size-1] = b;
	}
}

int main(int argc, char **argv)
{
	int arr[LENGHT];
	Input(arr, LENGHT);
	swap_negmax_last(LENGHT, arr);
	Output(arr, LENGHT);
	return 0;
}

