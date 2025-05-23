#include <stdio.h>
#include <stdlib.h>

#include "struct_api.h"

/*struct sensor
{
    uint16_t years;
    uint8_t month;
    uint8_t day;
    uint8_t hourse;
    uint8_t minutes;
    int8_t t;
};*/

int AddElementStruct(struct sensor *info, int d[], int *l, int *lmax)
{
    if (*l >= *lmax)
    {
        printf("Diaaa lmax = %d; l = %d\n", *lmax, *l);
        if ((info = realloc(info, (*lmax) * 2)) == NULL)
        {
            printf("Failed to allocate memory");
            return 0;
        }
        (*lmax) *= 2;
    }

    int n = *l;
    (info + n)->year = d[0];
    (info + n)->month = d[1];
    (info + n)->day = d[2];
    (info + n)->hourse = d[3];
    (info + n)->minute = d[4];
    (info + n)->t = d[5];
    (*l)++;
    return 1;
}

void DeleteElementStruct(struct sensor *info, int n, int *l)
{
    for (int i = n; i < (*l) - 1; i++)
    {
        *(info + i) = *(info + i + 1);
    }
    (*l)--;
}

void AddStruct(struct sensor *info, int d[][6], int DataSize, int *l, int *lmax)
{
    while ((*l) < DataSize)
        AddElementStruct(info, d[*l], l, lmax);
}

void SortStructTime(struct sensor *info, int l)
{
    int time1, time2, schet = 0;
    struct sensor buffer;
    for (int i = 0; i < l - 1; i++)
    {
        for (int j = 0; j < l - 1 - i; j++)
        {
            time1 = (info + j)->minute + (info + j)->hourse * 60 + (info + j)->day * 60 * 24 + (info + j)->month * 60 * 24 * 31 + (info + j)->year * 60 * 24 * 31 * 12;
            time2 = (info + j + 1)->minute + (info + j + 1)->hourse * 60 + (info + j + 1)->day * 60 * 24 + (info + j + 1)->month * 60 * 24 * 31 + (info + j + 1)->year * 60 * 24 * 31 * 12;
            if (time1 > time2)
            {
                buffer = *(info + j);
                *(info + j) = *(info + j + 1);
                *(info + j + 1) = buffer;
                schet++;
            }
        }
        if (schet == 0)
            return;
        schet = 0;
    }
}

void SortStructTemperature(struct sensor *info, int l)
{
    struct sensor buffer;
    int schet = 0;
    for (int i = 0; i < l - 1; i++)
    {
        for (int j = 0; j < l - 1 - i; j++)
        {
            if ((info + j)->t < (info + j)->t)
            {
                buffer = *(info + j);
                *(info + j) = *(info + j + 1);
                *(info + j + 1) = buffer;
                schet++;
            }
        }
        if (schet == 0)
            return;
        schet = 0;
    }
}

void PrintStruct(struct sensor *info, int l)
{
    printf("\n--------------------\n");
    for (int i = 0; i < l; i++)
    {
        printf("temperature %3d °C, date: %4d:%2d:%2d:%2d:%2d;\n", (info + i)->t, (info + i)->year, (info + i)->month, (info + i)->day, (info + i)->hourse, (info + i)->minute);
    }
    printf("--------------------\n\n");
}