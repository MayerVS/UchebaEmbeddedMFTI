#include <stdio.h>
#include <string.h>



int main(int argc, char **argv)
{

    size_t Nsize = 0;
    char N[10000] = {0};
    char check[1000] = {0}; 
    int Schet = 0; 
 
    scanf("%s",N);
    Nsize = strlen(N);
    if (Nsize < 3)
    {
		printf("0");
		return 0;
	}
	
	for (size_t i=0; i<=Nsize-3; i++)
    {
        for (size_t j=i+1; j<=Nsize-2; j++)
        {
            for (size_t k=j+1; k<=Nsize-1; k++)
            {
				int a =0;
                a = (N[i]-'0')*100+(N[j]-'0')*10+(N[k]-'0')*1; 
                if (a>=100) check[a]=1;
            }
        } 
    }

    for (int i=1; i<1000; i++)
    {
        Schet += check[i];
    }

    printf("%d\n",Schet);
   

    return 0;
}
