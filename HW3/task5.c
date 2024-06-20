//
//  main.c
//  Exercise4
//
//  Created by Владимир Майер on 16.06.2024.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int number1;
    int number2;
    int number3;
    scanf("%d", &number1);
    scanf("%d", &number2);
    scanf("%d", &number3);
    float srar = (float)(number1+number2+number3)/3;
    printf("%.2f \n", srar);
    return 0;
}
