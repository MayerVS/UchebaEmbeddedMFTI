/*
 * task2.c
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

int is_prime(int n, int delitel)
{
	static int flag = 0;
	if (n == 1 || flag == 1) return flag = 1;
	if(delitel <= n/2)
	{
		if (n%delitel == 0) 
			return flag = 1;
		else 
			is_prime(n, delitel+1);
	}
	return flag;
}

int main(int argc, char **argv)
{
	int a;
	scanf("%d", &a);
	is_prime(a, 2) == 1 ? printf("NO") : printf("YES");
	return 0;
}
