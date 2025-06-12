#include <stdio.h>
#include <unistd.h>
#include <math.h>

#include "f.h"
#include "func.h"

void help(void)
{
    printf("\n_____HELP_____\n\n");

    printf("Loaded functions.\n");
    printf("f1(x) = 0,6x + 3\n");
    printf("f2(x) = (x - 2)^3 - 1\n");
    printf("f3(x) = 3/x\n\n");

    printf("-x The abscissas of the intersection points of the curves are printed.\n");
    printf("-e The number of iterations required for the approximate solution of the equations in finding the points of intersection is printed.\n");
    printf("-s Finding the area of the figure between functions f1, f2 and f3.\n");
    printf("-t Testing root and integral functions.\n\n");
}

double (*funcSelect(void))(double)
{
    printf("Loaded functions.\n");
    printf("f1(x) = 0,6x + 3\n");
    printf("f2(x) = (x - 2)^3 - 1\n");
    printf("f3(x) = 3/x\n\n");
    printf("To test for function f1, enter 1, for function f2, enter 2, for function f3, enter 3.\n");
    
    int enter;
    scanf("%d", &enter);
    
    switch (enter) {
        case 1: return f1;
        case 2: return f2;
        case 3: return f3;
        default: return NULL;
    }
}

int main(int argc, char *argv[])
{
    int rez = 0, stepcount = 0, enter = 0;
    int *pstepcount = &stepcount;
    double (*cur_f)(double);
    double S = 0, a = 0, b = 0;
    while ((rez = getopt(argc, argv, "xesht")) != -1)
    {
        switch (rez)
        {
        case 'x':
            printf("\nFind root for f1 and f2.\n");
            printf("%5.4f. \n", root(f1, f2, 3, 4, 0.0001, pstepcount));
            printf("\nFind root for f2 and f3.\n");
            printf("%5.4f; %5.4f. \n", root(f2, f3, -1, 0, 0.0001, pstepcount), root(f2, f3, 3, 4, 0.0001, pstepcount));
            printf("\nFind root for f1 and f3.\n");
            printf("%5.4f; %5.4f. \n\n", root(f1, f3, -6, -5, 0.0001, pstepcount), root(f1, f3, 0, 1, 0.0001, pstepcount));
            break;
        case 'e':
            printf("\nFind root for f1 and f2.\n");
            printf("Find root %5.4f for %d steps.\n", root(f1, f2, 3, 4, 0.0001, pstepcount), stepcount);
            printf("\nFind root for f2 and f3.\n");
            printf("Find root %5.4f for %d steps;\n", root(f2, f3, -1, 0, 0.0001, pstepcount), stepcount);
            printf("Find root %5.4f for %d steps.\n", root(f2, f3, 3, 4, 0.0001, pstepcount), stepcount);
            printf("\nFind root for f1 and f3.\n");
            printf("Find root %5.4f for %d steps;\n", root(f1, f3, -6, -5, 0.0001, pstepcount), stepcount);
            printf("Find root %5.4f for %d steps.\n\n", root(f1, f3, 0, 1, 0.0001, pstepcount), stepcount);
            break;
        case 's':
            printf("\nFinding the area of the figure between functions f1, f2 and f3.\n\n");

            a = root(f1, f3, -7, -5, 0.0001, pstepcount);
            b = root(f1, f2, 3, 4, 0.0001, pstepcount);
            S += integral(f1, a, b, 100000);
            printf("Find S = %5.3f for f1 betwen %5.4f and %6.5f. S_summ = %5.3f.\n", integral(f1, a, b, 100000), a, b, S);

            a = root(f2, f0, 2, 4, 0.0001, pstepcount);
            b = root(f1, f2, 3, 4, 0.0001, pstepcount);
            S -= integral(f2, a, b, 100000);
            printf("Find S = %5.4f for f2 betwen %6.5f and %6.5f. S_summ = %5.3f.\n", integral(f2, a, b, 100000), a, b, S);

            a = root(f2, f3, -1, 0, 0.0001, pstepcount);
            b = root(f2, f0, 2, 4, 0.0001, pstepcount);
            S -= integral(f2, a, b, 100000);
            printf("Find S = %5.4f for f2 betwen %5.4f and %6.5f. S_summ = %5.3f.\n", -integral(f2, a, b, 100000), a, b, S);

            a = root(f1, f3, -7, -5, 0.0001, pstepcount);
            b = root(f2, f3, -1, 0, 0.0001, pstepcount);
            S -= integral(f3, a, b, 100000);
            printf("Find S = %5.4f for f3 betwen %5.4f and %5.4f. S_summ = %5.3f.\n\n", -integral(f3, a, b, 100000), a, b, S);
            break;
        case 't':
            printf("To test the root function, enter 1. To test the integral function, enter 2\n");
            scanf("%d", &enter);
            switch (enter)
            {
            case 1:
                cur_f = funcSelect();
                printf("enter x_min: ");
                scanf("%lf", &a);
                printf("enter x_max: ");
                scanf("%lf", &b);
                printf("Find root %5.4f betwen %5.4f and %5.4f for %d steps.\n", root(cur_f, f0, a, b, 0.0001, pstepcount), a, b, stepcount);
                break;
            case 2:
                cur_f = funcSelect();
                printf("enter x_min: ");
                scanf("%lf", &a);
                printf("enter x_max: ");
                scanf("%lf", &b);
                printf("Find integral S = %5.3f betwen %5.4f and %5.4f.\n", integral(cur_f, a, b, 10000), a, b);

                break;
            default:
                printf("Error, start again");
                break;
            }
            break;
        case 'h':
            help();
            break;
        default:
            help();
            break;
        }
    }
    if (optind == 1)
        help();
}
