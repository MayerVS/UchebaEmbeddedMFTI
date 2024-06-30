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

int main(int argc, char **argv)
{
	int a, b[10], i = 0, j = 0;
	scanf("%d", &a);
		while (a > 0) 
		{
			b[i++] = a%10;
			a/=10;
		}
		for (i-=1; i>=1; i--) 
		{
			for (j = i-1; j>=0; j--) 
			{
				if (b[i] == b[j]) 
				{
					printf("YES");
					return 0;
				}
			}
		}	
	printf("NO");
	return 0;
}

