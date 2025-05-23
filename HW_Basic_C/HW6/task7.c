/*
 * task7.c
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

int perevod(int a, int b)
{
	int ost[20], j = 0, chislo = 0;
	while(a/b>=1)
	{
	ost[j] = a%b;
//	printf("%d", ost[j]);
	a = a / b;
	j++;
	}
	ost[j] = a%b;
//	printf("%d", ost[j]);
	for(int i = j; i>= 0; i--)
		chislo = chislo*10+ost[i]; 
	return chislo;
}

int main(int argc, char **argv)
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", perevod(a, b));
	return 0;
}

