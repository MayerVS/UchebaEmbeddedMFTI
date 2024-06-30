//
//  main.c
//  Exercise4
//
//  Created by Владимир Майер on 16.06.2024.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int num1;
    int num2;
    scanf("%d", &num1);
    scanf("%d", &num2);
    if (num1 < num2)
    {
        printf("%d %d", num1, num2);
    }
    else
    {
        printf("%d %d", num2, num1);
    }
    return 0;
}
