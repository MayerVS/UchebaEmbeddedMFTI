//
//  main.c
//  Exercise4
//
//  Created by Владимир Майер on 16.06.2024.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int a[3], j = 0;
    double x0, k;
    
    for (int i = 0; i<3; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i<2; i++)
    {
        if (a[i]>=a[i+1]) j=1;
    }
    
    if (j==0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    
}

