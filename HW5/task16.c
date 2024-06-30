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
#include <stdint.h>

int main(int argc, char **argv)
{
	int32_t a[2];
	scanf("%d", &a[0]);
	scanf("%d", &a[1]);
	while (a[0]!=0 && a[1]!=0)
	{
		if (a[0]>a[1])
		{
			a[0] = a[0]%a[1];
		}
		else
		{
			a[1] = a[1]%a[0];
		}
	}
	printf("%d",a[0]+a[1]);
	return 0;
}
