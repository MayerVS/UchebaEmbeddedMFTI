//
//  main.c
//  Exercise4
//
//  Created by Владимир Майер on 16.06.2024.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int X1, Y1, X2, Y2;
    double x0, k;
    scanf("%d", &X1);
    scanf("%d", &Y1);
    scanf("%d", &X2);
    scanf("%d", &Y2);
    
    k = (double)(Y2-Y1)/(X2-X1);
    x0 = Y2 - X2*k;
    printf("%.2f %.2f", k, x0);
    return 0;
}

