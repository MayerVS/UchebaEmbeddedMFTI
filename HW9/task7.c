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

int compression(int a[], int b[], int N)
{
	int schet_odin = 1, schet = 0;
	if (a[0] == 1)
		b[schet++] = 0;
	for(int i = 1; i < N; i++)
	{
		if (a[i-1] == a[i])
		{
			schet_odin++;
		}
		else
		{
			b[schet++] = schet_odin;
			schet_odin = 1;
		}
	}
	b[schet++] = schet_odin;
	return schet;
}

int main(int argc, char **argv)
{
	
}


