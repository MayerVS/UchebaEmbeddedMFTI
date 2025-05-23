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

void print_digit(char s[])
{
	int numb[10] = {0}, i = 0;
	while(s[i] != '.')
	{
//		printf("%c\n", s[i]);
		if(s[i] >= '0' && s[i] <= '9')
		{
			numb[s[i]-'0']++;
		}
		i++;
	}
	for(int i = 0; i<10; i++)
		if(numb[i]!=0)
			printf("%d %d\n", i, numb[i]);
}

int main(int argc, char **argv)
{
	char s[] = "Hello123 world77.";
	print_digit(s);
}

