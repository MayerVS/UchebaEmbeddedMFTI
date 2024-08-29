#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int rez=0;
    // opterr=0;//Можно отключить вывод сообщений об ошибках, для этого надо где-то в
    //программе перед вызовом функции вставить opterr=0
    while ( (rez = getopt(argc,argv,"thsf:m:")) != -1)
    {
        switch (rez)
        {
            case 't': printf("found argument \"1\".\n"); break;
            case 'f': printf("found argument \"2 = %s\".\n",optarg); break;
            case 'm': printf("found argument \"3 = %s\".\n",optarg); break;
            case 's': printf("found argument \"4\"\n"); break;
            case 'h': printf("found argument \"5\"\n"); break;
            case '?': printf("Error found !\n");break;
        }
    }
}