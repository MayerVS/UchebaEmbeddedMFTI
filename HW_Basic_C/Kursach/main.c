#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "temp_api.h"
#include "struct_api.h"

int test(struct sensor *s, int *l, int *lmax)
{
    printf("\nProgram testing mode started\n");
    int data[3][6] = {{2021, 12, 13, 14, 15, 15}, {2023, 9, 19, 10, 10, -28}, {2022, 05, 14, 15, 16, 18}};
    AddStruct(s, data, 3, l, lmax);
    printf("\nStructure added:");
    PrintStruct(s, *l);

    int nData[6] = {2020, 10, 9, 4, 23, 20};
    if (AddElementStruct(s, nData, l, lmax) == 0)
        return 0;
    printf("The structure is complementary:");
    PrintStruct(s, *l);

    printf("Structure sorted by time:");
    SortStructTime(s, *l);
    PrintStruct(s, *l);

    printf("Structure sorted by temperature:");
    SortStructTemperature(s, *l);
    PrintStruct(s, *l);

    printf("Structure element 2 deleted:");
    DeleteElementStruct(s, 2, l);
    PrintStruct(s, *l);

    printf("\nStatistics for: 2020.10\n");
    PrintMinTForMounth(s, *l, 2020, 10);
    PrintAverageTForMounth(s, *l, 2020, 10);
    PrintMaxTForMounth(s, *l, 2020, 10);

    printf("\nStatistics for: 2022\n");
    PrintMinTForYear(s, *l, 2022);
    PrintAverageTForYear(s, *l, 2022);
    PrintMaxTForYear(s, *l, 2022);

    printf("\nStatistics for: 2025\n");
    PrintMinTForYear(s, *l, 2025);
    PrintAverageTForYear(s, *l, 2025);
    PrintMaxTForYear(s, *l, 2025);

    printf("\nStatistics for: 2025.10\n");
    PrintMinTForMounth(s, *l, 2025, 10);
    PrintAverageTForMounth(s, *l, 2025, 10);
    PrintMaxTForMounth(s, *l, 2025, 10);

    printf("\nProgram testing mode completed successfully\n\n");
    return 1;
}

int FilePars(char *FileName, struct sensor *s, int *l, int *lmax)
{
    FILE *f;
    printf("file: %s reading\n", FileName);
    if ((f = fopen(FileName, "r")) == 0)
    {
        printf("File name error");
        return 0;
    }
    else
    {
        int year, month, day, hour, minute, t, j;
        while ((j = fscanf(f, "%d; %d; %d; %d; %d; %d;", &year, &month, &day, &hour, &minute, &t)) != EOF)
        {
            if (j != 6) // убедимся, что нужно читать
            {
                printf("error: line %d\n", (*l) + 1);
                int c = 0;
                while (c != EOF && c != '\n')
                    c = fgetc(f);
            }
            else if (year >= 0 && year <= 9999 && month >= 0 && month <= 12 && day >= 0 && day <= 31 && hour >= 0 && hour <= 24 &&
                     minute >= 0 && minute <= 60 && t >= -99 && t <= 99)
            {
                int data[] = {year, month, day, hour, minute, t};
                if (AddElementStruct(s, data, l, lmax) == 0)
                    return 0;
            }
            else
            {
                printf("error: line %d\n", (*l) + 1);
            }
        }
    }
    printf("Reading completed");
    fclose(f);
    return 1;
}

int CharToInt(char *FileName)
{
    char a;
    int i = 0, chislo = 0;
    while ((a = *(FileName + i)) != '\0')
    {
        a = *(FileName + i);
        chislo = chislo * 10 + (a - 0x30);
        i++;
    }
    return chislo;
}

int main(int argc, char *argv[])
{
    int rez = 0, l = 0, ij = 0, lmax = 100000;
    int StatYear, StatMounth;
    struct sensor *s;
    if ((s = malloc(sizeof(struct sensor) * lmax)) == NULL)
    {
        printf("Failed to allocate memory\n");
        return 0;
    }
    char StdFileNameSmall[] = "./temperature_data_examples/temperature_small.csv";
    char StdFileNameBig[] = "./temperature_data_examples/temperature_big.csv";
    while ((rez = getopt(argc, argv, "thsbf:m::")) != -1)
    {
        switch (rez)
        {
        case 't':
            if (test(s, &l, &lmax) == 0)
                return 0;
            break;
        case 'h':
            printf("_____HELP_____\n\n");
            printf("-t Testing all program functionality.\n");
            printf("-s Reading a standard CSV file: temperature_small.csv.\n");
            printf("-b Reading a standard CSV file: temperature_big.csv.\n");
            printf("-f Input CSV file for processing.\n");
            printf("-m - Statistics for the entered month, format: MMYYYY.\n");
            printf("If the field is empty, display statistics for all months of all years.\n");
            break;

        case 's':
            if (FilePars(StdFileNameSmall, s, &l, &lmax) == 0)
                return 0;
            if (l != 0)
                PrintStruct(s, l);
            break;

        case 'b':
            if (FilePars(StdFileNameBig, s, &l, &lmax) == 0)
                return 0;
            if (l != 0)
                PrintStruct(s, l);
            break;

        case 'f':
            if (FilePars(optarg, s, &l, &lmax) == 0)
                return 0;
            if (l != 0)
                PrintStruct(s, l);
            break;

        case 'm':
            if (optarg == NULL)
            {
                //printf("lmax = %d, l = %d\n", lmax, l);
                SortStructTime(s, l);
                int MonthMax = 0, YearMax = (s + l - 1)->year, MonthMin = (s)->month, YearMin = (s)->year;
                //printf("MonthMin = %d, YearMin = %d, MonthMax = %d, YearMax = %d\n", MonthMin, YearMin, MonthMax, YearMax);
                for (int i = YearMin; i <= YearMax; i++)
                {
                    if (i == YearMax)
                        MonthMax = (s + l - 1)->month;
                    for (int j = MonthMin; j <= MonthMax; j++)
                    {
                        printf("\nStatistics for: %d.%d\n", i, j);
                        PrintMinTForMounth(s, l, i, j);
                        PrintAverageTForMounth(s, l, i, j);
                        PrintMaxTForMounth(s, l, i, j);
                    }

                    printf("\nStatistics for: %d\n", i);
                    PrintMinTForYear(s, l, i);
                    PrintAverageTForYear(s, l, i);
                    PrintMaxTForYear(s, l, i);

                    if (i == YearMin)
                        MonthMin = 0;
                }
            }
            else
            {
                int chislo = CharToInt(optarg);
                StatMounth = chislo / 10000;
                StatYear = chislo % 10000;
                printf("\nStatistics for: %d.%d\n", StatMounth, StatYear);
                PrintMinTForMounth(s, l, StatYear, StatMounth);
                PrintAverageTForMounth(s, l, StatYear, StatMounth);
                PrintMaxTForMounth(s, l, StatYear, StatMounth);
            }
            break;

        default:
            printf("error, -h for help\n");
            break;
        }
    }
}
