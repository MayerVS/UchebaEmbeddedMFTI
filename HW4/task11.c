//
//  main.c
//  Exercise4
//
//  Created by Владимир Майер on 16.06.2024.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    
    int num[5];
    int j = 0; // Номер наибольшего числа
    int k = 0; // Номер наименьшиго числа
    for(int i = 0; i<(sizeof(num)/4); i++)
    {
        scanf("%d", &num[i]);
    }
    
    
    for(int i = 1; i<(sizeof(num)/4); i++)
    {
        if (num[j]>num[i]) j = i; // Вычисляем наибольшие число
        if (num[k]<num[i]) k = i; // Вычисляем наименьшее число
    }
    
    int sum = num[j] + num[k];
    
    printf("%d \n", sum);
    
    return 0;
}
