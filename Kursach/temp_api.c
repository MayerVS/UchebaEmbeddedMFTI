#include <stdio.h>
#include "temp_api.h"


void PrintMinTForMounth(struct sensor info[], int n, int y, int m)
{
    int min = 99, schet = 0;
    for(int i = 0; i < n; i++)
    {
        if (info[i].month == m && info[i].year == y)
            schet++;
        if (info[i].t < min && info[i].month == m && info[i].year == y) 
            min = info[i].t;
    }
    if(schet == 0)
        printf("No information available for this month\n");
    else
        printf("Minimum temperature for mounth: %dC\n", min);
}

void PrintAverageTForMounth(struct sensor info[], int n, int y, int m)
{
   int avarge = 0, j = 0;
    for(int i = 0; i < n; i++)
    {
        if (info[i].month == m && info[i].year == y)
        {
            j++;
            avarge += info[i].t;  
        }
    }
    avarge /= j;
    if(j == 0)
        printf("No information available for this month\n");
    else
        printf("Avarge temperature for mounth: %dC\n", avarge);
}

void PrintMaxTForMounth(struct sensor info[], int n, int y, int m)
{
    int max = -99, schet = 0;
    for(int i = 0; i < n; i++)
    {
        if (info[i].month == m && info[i].year == y)
            schet++;
        if (info[i].t > max && info[i].month == m && info[i].year == y) 
            max = info[i].t;
    }
    if(schet == 0)
        printf("No information available for this month\n");
    else
        printf("Maximum temperature for mounth: %dC\n", max);
}

void PrintMinTForYear(struct sensor info[], int n, int y)
{
     int min = 99, schet = 0;
    for(int i = 0; i < n; i++)
    {
        if (info[i].year == y) 
            schet++;
        if (info[i].t < min && info[i].year == y) 
            min = info[i].t;
    }
    if(schet == 0)
        printf("No information available for this year\n");
    else
        printf("Minimum temperature for year: %dC\n", min);
}

void PrintAverageTForYear(struct sensor info[], int n, int y)
{
    int avarge = 0, schet = 0;
    for(int i = 0; i < n; i++)
        if (info[i].year == y)
        {
            schet++;
            avarge += info[i].t;  
        }
    avarge /= schet;
    if(schet == 0)
        printf("No information available for this year\n");
    else
        printf("Avarge temperature for year: %dC\n", avarge);
}

void PrintMaxTForYear(struct sensor info[], int n, int y)
{
    int max = -99, schet = 0;
    for(int i = 0; i < n; i++)
    {
        if (info[i].year == y) 
            schet++;
        if (info[i].t > max && info[i].year == y) 
            max = info[i].t;
    }
    if(schet == 0)
        printf("No information available for this year\n");
    else
        printf("Maximum temperature for year: %dC\n", max);
}
