//
//  main.c
//  Exercise4
//
//  Created by Владимир Майер on 16.06.2024.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int a, a1, a2, a3, summ_a;
    scanf("%d", &a);
    a1 = a%10;
    a2=(a/10)%10;
    a3=a/100;
    summ_a=a1+a2+a3;
    printf("%d", summ_a);
    return 0;
}
