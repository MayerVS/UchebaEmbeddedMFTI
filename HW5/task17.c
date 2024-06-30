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
	uint32_t j = 0, a[1000], dublikati, summ , umn, k, chiclo[10], z = 0, d;
 for(int i = 10; i<1000000; i++)
 {
	 
	 summ = 0;
	 umn = 1;
	 dublikati = i;
	 k = 0;
	 while (dublikati > 0) 
		{
			chiclo[k] = dublikati%10;
			dublikati/=10;
			k++;
		}
	for(int z = 0; z<k; z++)
	{
		summ+=chiclo[z];
		umn*=chiclo[z];
	}
	if(summ == umn) 
	{
		a[j] = i;
		j++;
	}
 }
 
 scanf("%d",&d);
 while(1)
 {
	 if(d<a[z]) break;
	 z++;
 }
 for (int g = 0; g<z; g++)
 {
	 printf("%d ",a[g]);
 }
}


