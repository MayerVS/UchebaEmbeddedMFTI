/*
 * task 3.c
 * 
 * Copyright 2025 Владимир Майер <vladimirmajer@MacBook-Air-Vladimir.local>
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

uint32_t LowBits(uint32_t a, uint32_t l)
{
	return((a << (32 - l)) >> (32 - l));
}


int main(int argc, char **argv)
{
	uint32_t a, l;
	scanf("%u", &a);
	scanf("%u", &l);
	a = LowBits(a, l);
	printf("%u", a);
	return 0;
}

