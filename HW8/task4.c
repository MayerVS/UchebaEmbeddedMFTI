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


int SrednDMax(int arr[], int lenght)
{
	int maxmax = -2147483648, maxmin = -2147483648;
	for(int i = lenght; i > 0; i--)
	{
		if (arr[i-1]>=maxmax)
		{
			maxmin = maxmax;
			maxmax = arr[i-1];
			//printf("maxmin = %d ;maxmax = %d; chislo = %d\n", maxmin, maxmax, arr[i-1]);
		}
		if (arr[i-1]>=maxmin && arr[i-1]!=maxmax)
		{
			maxmin = arr[i-1];
			//printf("maxmin = %d ;maxmax = %d; chislo = %d\n", maxmin, maxmax, arr[i-1]);
		}
	}
	return maxmax+maxmin;
}

int main(int argc, char **argv)
{
	int arr[LENGHT];
	Input(arr, LENGHT);
	printf("%d", SrednDMax(arr, LENGHT));
	return 0;
}

