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
    int sum = number1+number2+number3;
    int mult = number1*number2*number3;
    printf("%d+%d+%d=%d \n", number1, number2, number3, sum);
    printf("%d*%d*%d=%d \n", number1, number2, number3, mult);
    return 0;
}
