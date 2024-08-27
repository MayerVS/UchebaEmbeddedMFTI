#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include "temp_api.h"
#include "struct_api.h"

#define LARGE 550000

void test(void)
{
    printf("\nProgram testing mode started\n");

    int l = 3;
    int data[3][6] = {{2021, 12, 13, 14, 15, 15}, {2023, 9, 19, 10, 10, -28}, {2022, 05, 14, 15, 16, 18}};
    struct sensor s[3];
    AddStruct(s, data, l);
    printf("\nStructure added:");
    PrintStruct(s, l);

    int nData[6] = {2020, 10, 9, 4, 23, 20};
    AddElementStruct(s, nData, &l);
    printf("The structure is complementary:");
    PrintStruct(s, l);

    printf("Structure sorted by time:");
    SortStructTime(s, l);
    PrintStruct(s, l);

    printf("Structure sorted by temperature:");
    SortStructTemperature(s, l);
    PrintStruct(s, l);

    printf("Structure element 2 deleted:");
    DeleteElementStruct(s, 2, &l);
    PrintStruct(s, l);

    printf("\nStatistics for: 2020.10\n");
    PrintMinTForMounth(s, l, 2020, 10);
    PrintAverageTForMounth(s, l, 2020, 10);
    PrintMaxTForMounth(s, l, 2020, 10);

    printf("\nStatistics for: 2022\n");
    PrintMinTForYear(s, l, 2022);
    PrintAverageTForYear(s, l, 2022);
    PrintMaxTForYear(s, l, 2022);

    printf("\nStatistics for: 2025\n");
    PrintMinTForYear(s, l, 2025);
    PrintAverageTForYear(s, l, 2025);
    PrintMaxTForYear(s, l, 2025);

    printf("\nStatistics for: 2025.10\n");
    PrintMinTForMounth(s, l, 2025, 10);
    PrintAverageTForMounth(s, l, 2025, 10);
    PrintMaxTForMounth(s, l, 2025, 10);

    printf("\nProgram testing mode completed successfully\n\n");
}

void FilePars(char *FileName, struct sensor s[], int *l)
{
    FILE *f;
    printf("file: %s reading\n", FileName);
    if ((f = fopen(FileName, "r")) == 0)
    {
        printf("File name error");
        return;
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
                AddElementStruct(s, data, l);
            }
            else
            {
                printf("error: line %d\n", (*l) + 1);
            }
        }
    }
    printf("Reading completed");
    fclose(f);
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
    printf("argc = %d\n", argc);
    int rez = 0, l = 0, ij = 0;
    char StatYear, StatMounth;
    struct sensor s[LARGE];
    char StdFileName[] = "./temperature_data_examples/temperature_small.csv";
    while ((rez = getopt(argc, argv, "thsf:m:")) != -1)
    {
        printf("ij = %d, rez = %d\n", ++ij, rez);
        switch (rez)
        {
        case 't':
            test();
            break;
        case 'h':
            printf("_____HELP_____\n\n");
            printf("-t Testing all program functionality.\n");
            printf("-s Reading a standard file: temperature_small.csv.\n");
            printf("-f Input CSV file for processing.\n");
            printf("-m - Statistics for the entered month, format: MMYYYY.\n");
            printf("If the field is empty, display statistics for all months of all years.\n");
            break;

        case 's':
            FilePars(StdFileName, s, &l);
            if (l != 0)
                PrintStruct(s, l);
            break;

        case 'f':
            FilePars(optarg, s, &l);
            if (l != 0)
                PrintStruct(s, l);
            break;

        case 'm':
            printf("argument m = %s\n", optarg);
            int chislo = CharToInt(optarg);
            printf("argument m = %d\n", chislo);
            if (chislo == 0)
                printf("Statistika za vse vremia");
            else
            {
                StatMounth = chislo / 10000;
                StatYear = chislo % 10000;
                printf("\nStatistics for: %d.%d\n", StatMounth, StatYear);
                PrintMinTForMounth(s, l, StatYear, StatMounth);
                PrintAverageTForMounth(s, l, StatYear, StatMounth);
                PrintMaxTForMounth(s, l, StatYear, StatMounth);
            }
            break;

            char StatDay, StatMounth;

        default:
            printf("error, -h for help\n");
            break;
        }
        return 0;
    }
}
