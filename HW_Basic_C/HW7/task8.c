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

int PechatFact(int a, int b)
{

	if (a>b)
		{
		printf("%d ", a);
		PechatFact(a-1, b);
		}
	if (b>a)
	{
		printf("%d ", a);
		PechatFact(a+1, b);
	}
	if (a==b)
		printf("%d", a);
	return 1;
}

int main(int argc, char **argv)
{
	int a, b;
	scanf("%d %d", &a, &b);
	PechatFact(a, b);
	return 0;
}
