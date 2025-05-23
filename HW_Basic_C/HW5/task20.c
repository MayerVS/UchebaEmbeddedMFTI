/*
 * task14.c
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
	int a, b[10000], i, min = 1, dubla, dubli;
	scanf("%d", &a);
	for(i = 1; i<a; i++)
	{
		dubli = i;
		dubla = a;
		while (dubli!=0 && dubla!=0)
		{
		if (dubli>dubla)
		{
			dubli = dubli%dubla;
		}
		else
		{
			dubla = dubla%dubli;
		}
		}
		b[i-1] = dubla + dubli;
	}
	i-=1;
		for(int j = 0; j<i; j++)
		{
		if (b[j]>min) min = b[j];
		}
		(min == 1 && a != 1) ? printf("YES") : printf("NO");
	return 0;
}
