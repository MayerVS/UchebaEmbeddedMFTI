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

void Input(int arr[], int lenght)
{
	for(int i = 0; i < lenght; i++)
		scanf("%d", &arr[i]);
}

float Srednie(int arr[], int lenght)
{
	int summ = 0;
	float srednie;
	for(int i = 0; i < lenght; i++)
		summ+=arr[i];
	return srednie = (float)summ/lenght;
}

int main(int argc, char **argv)
{
	int arr[LENGHT];
	Input(arr, LENGHT);
	printf("%.3f", Srednie(arr, LENGHT));
	return 0;
}

