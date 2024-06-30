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
    for(int i = 0; i<(sizeof(num)/4); i++)
    {
        scanf("%d", &num[i]);
    }
    
    
    for(int i = 1; i<(sizeof(num)/4); i++)
    {
        if (num[j]<num[i]) j = i;
    }
    
    printf("%d \n", num[j]);
    
    return 0;
}
