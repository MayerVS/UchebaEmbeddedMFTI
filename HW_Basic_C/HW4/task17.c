//
//  main.c
//  Exercise4
//
//  Created by Владимир Майер on 16.06.2024.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int i;
    scanf("%d",&i);
    if (i > 2 && i < 6)
    {
        printf("spring");
    }
    else if (i > 5 && i < 9)
    {
        printf("summer");
    }
    else if (i > 8 && i < 12)
    {
        printf("autumn");
    }
    else
    {
        printf("winter");
    }
}

