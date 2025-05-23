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

void Output(int *arr, int lenght)
{
	for(int i = 0; i < lenght; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int *Invers(int arr[], int lenght)
{
	static int invers[LENGHT];
	
	for(int i = lenght/2-1; i>=0 ;i--)
	{
		invers[lenght/2 - 1 - i] = arr[i];
		//printf("i = %d; arr[i] = %d; inv_id = %d; invers[inv_id] = %d\n", i, arr[i], lenght/2 - 1 - i, invers[lenght/2 - 1 - i]);
	}
	for(int i = lenght-1; i>=lenght/2 ;i--)
	{
		invers[lenght + lenght/2 - 1 - i] = arr[i];
		//printf("i = %d; arr[i] = %d; inv_id = %d; invers[inv_id] = %d\n", i, arr[i], lenght + lenght/2 - 1 - i, invers[lenght + lenght/2 - 1 - i]);
	}
	return invers;
}

int main(int argc, char **argv)
{
	int arr[LENGHT], *uinvers;
	Input(arr, LENGHT);
	uinvers = Invers(arr, LENGHT);
	Output(uinvers, LENGHT);
	return 0;
}


