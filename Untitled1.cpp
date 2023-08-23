#include <stdio.h>
#include <math.h>

int Not_Zero (double x);
int SquareSolver (double a, double b, double c, double* x1, double* x2);

enum NumberOfRoots
{
    ZERO,
    ONE,
    TWO,
    MANY_SOL
};


int main()
    {

    printf ("# This program solves square equation: a*x^2+b*x+c=0\n");
    printf ("# Enter a, b, c: \n");

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    if (scanf("%lg", &a)==1 && scanf("%lg", &b)==1 && scanf("%lg", &c)==1)
    {
        printf ("# Answer:\n");

        int NumbOfSolutions = SquareSolver (a, b, c, &x1, &x2);

        switch (NumbOfSolutions)
        {

        case ZERO: printf ("No solutions");
                   break;

        case ONE: printf ("x = %lg\n", x1);
                  break;

        case TWO: printf ("x1 = %lg\n", x1);
                  printf ("x2 = %lg\n", x2);
                  break;

        case MANY_SOL: printf ("Any number is a solution\n");
                       break;

        default: printf ("Error!!! Solutions = %d", NumbOfSolutions);
                 return 0;
        }
    }
    else
    {
        printf("Wrong input!!! Repeat the program...\n");
    }
}

int Not_Zero (double x)
    {
        return (fabs (x) < 1e-6);
    }

int SquareSolver (double a, double b, double c, double* x1, double* x2)
    {

    if (Not_Zero (a))
        {
        if (Not_Zero (b))
            {
            return (Not_Zero (c)) ? MANY_SOL : ZERO;
            }
        else
            {
            *x1 = *x2 = (Not_Zero (c)) ? 0 : - (c / b);
            return ONE;
            }
        }
    else
        {
        double D = b * b - 4 * a * c;

        if (D < 0)
            {
            return ZERO;
            }
        else if (Not_Zero (D))
            {
            *x1 = *x2 = (Not_Zero (b))? 0: -b / (2 * a);
            return ONE;
            }
        else
            {
            double d = sqrt (D);
            *x1 = (-b - d) / (2 * a);
            *x2 = (-b + d) / (2 * a);
            return TWO;
            }
        }
    }
