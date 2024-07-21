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

#define LENGHT 1000

int minimum(int arr[], int lenght)
{
	int min = arr[0];
	for(int i = 1; i<lenght; i++)
		if(arr[i] < min)
			min = arr[i];
	return min;
}

int perebor(int arr[], int lenght, int min)
{
	int min_l = min;
	while(1)
	{
	for(int i = 0; i < lenght; i++)
		if(arr[i] == min + 1)
			min++;
	if(min_l == min)
		return ++min;
	min_l = min;
	}
}

int Input(int arr[], int lenght)
{
	int i = 0;
	do
	{
		scanf("%d", &arr[i]);
	} while(arr[i++] != 0);
	return --i;
}

void Output(int arr[], int lenght)
{
	for(int i = 0; i < lenght; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(int argc, char **argv)
{
	int arr[LENGHT], lenght, min;
	lenght = Input(arr, LENGHT);
//	Output(arr, lenght);
	min = minimum(arr, lenght);
	printf("%d", perebor(arr, lenght, min));
	return 0;
}

