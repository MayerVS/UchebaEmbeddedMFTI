/*
 * task4.c
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

int funktion(int x)
{
	if(x>=2) return x*x+4*x+5;
	else if(x>=-2 && x < 2) return x*x;
	else return 4;
}



int main(int argc, char **argv)
{
	int a, b[10], i = 0, j = 0, minus = 0, f[100], fmax, stop = 1;
	char c;
	
	while (stop)
	{
		c=getchar();
		if (c>= '0' && c<= '9')
		{
			b[i] = c - 0x30;
			if (b[0] == 0) 
				stop = 0;
			i++;
		}
		else if (c == '-') minus = 1;
		else if (c == ' ')
		{
			a = 0;
			for(int k = 0; k<i; k++)
			{
				a = a*10 + b[k];
			}
			if (minus == 1) 
			{
				a*=-1;
				minus = 0;
			}
			f[j] = funktion(a);
			j++;
			i = 0;
		}
	}
	
	fmax = f[0];
	
	for(int i = 1; i<j; i++)
	{
		if (f[i]>fmax) fmax = f[i]; 
	}
	
	printf("%d\n",fmax);
	return 0;
}

