#pragma once

#include <stdint.h>

struct sensor
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hourse;
    uint8_t minute;
    int8_t t;
};

void AddElementStruct(struct sensor [], int[], int*);
void DeleteElementStruct(struct sensor [], int, int*);
void AddStruct(struct sensor [], int[][6], int);
void SortStructTemperature(struct sensor [], int);
void SortStructTime(struct sensor [], int);
void PrintStruct(struct sensor [], int);