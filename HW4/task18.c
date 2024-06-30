//
//  main.c
//  Exercise4
//
//  Created by Владимир Майер on 16.06.2024.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int a1, a2;
    scanf("%d%d",&a1, &a2);
    if (a1 > a2)
    {
        printf("Above");
    }
    else if (a1 < a2)
    {
        printf("Less");
    }
    else
    {
        printf("Equal");
    }
}

