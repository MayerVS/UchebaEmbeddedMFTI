//
//  main.c
//  Exercise4
//
//  Created by Владимир Майер on 16.06.2024.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int a[3], na[3], j = 0;
    for (int i = 0; i<3; i++)
    {
        scanf("%d",&a[i]);
    }
   
    for (int i = 1; i<3; i++)
    {
        if (a[j]<a[i]) j = i;
    }
    
    na[0] = a[j];
    
    for (int i = 0; i<3; i++)
    {
        if (i != j)
        {
            na[i+1] = a[i];
        }
        else
        {
            for (int k = i+1; k<3; k++)
            {
                na[k] = a[k];
            }
                i = 3;
        }
    }
    
    if (na[0]<na[1]+na[2])
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    
}

