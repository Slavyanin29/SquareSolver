#include <stdio.h>
#include <math.h>
//#define NDEBUG
//#include <assert.h>

enum InfEquation
{
    nTests = 6, //Number of Tests
    MA = 2, //Maximum Answers
    NOP = 3 //Number of Parameters
};

enum NumberOfRoots
{
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    MANY_SOL = 3
};

struct TestData
{
    double a, b, c;
    double x1, x2;
};

int IsZero (double x);
int SquareSolver (double coeffs[], double roots[]);
void InputCoeffs (double coeffs[], int NOP);
void PrintRoots (double roots[], int NumbOfSolutions);
int TestOne (const TestData* allData);
void TestAll ();

int main()
{

    printf ("# This program solves square equation: a*x^2+b*x+c=0\n");
    printf ("# Enter a, b, c: \n");

    double coeffs[NOP] = {}, roots[MA] = {};

    TestAll();

    InputCoeffs(coeffs, NOP);

    printf ("# Answer:\n");

    int NumbOfSolutions = SquareSolver (coeffs, roots);

    PrintRoots(roots, NumbOfSolutions);

}

void InputCoeffs (double coeffs[], int NOP)
{
    int i=0;

    while (i<NOP)
    {
        if (scanf("%lg", &coeffs[i])!=1)
        {
            printf("# Wrong input!!! Try again...\n");
            rewind(stdin);
            i=0;
        }
        else
            i++;
    }
}

int IsZero (double x)
{
    return (fabs (x) < 1e-6);
}

int SquareSolver (double coeffs[], double roots[])
{

    double a = coeffs[0], b = coeffs[1], c = coeffs[2];

    if (IsZero (a))
    {
        if (IsZero (b))
        {
            return (IsZero (c))? MANY_SOL : ZERO;
        }
        else
        {
            roots[0] = roots[1] = (IsZero (c))? 0 : -(c / b);
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
        else if (IsZero (D))
        {
            roots[0] = roots[1] = (IsZero (b))? 0 : -b / (2 * a);
            return ONE;
        }
        else
        {
            double d = sqrt (D);
            roots[0] = (IsZero (-b - d))? 0 : (-b - d) / (2 * a);
            roots[1] = (IsZero (-b + d))? 0 : (-b + d) / (2 * a);
            return TWO;
        }
    }
}

void PrintRoots (double roots[], int NumbOfSolutions)
{
    switch (NumbOfSolutions)
    {

        case ZERO: printf ("No solutions");
                   break;

        case ONE: printf ("x = %lg\n", roots[0]);
                  break;

        case TWO: printf ("x1 = %lg\n", roots[0]);
                  printf ("x2 = %lg\n", roots[1]);
                  break;

        case MANY_SOL: printf ("Any number is a solution\n");
                       break;

        default: printf ("# Error!!! Solutions = %d", NumbOfSolutions);

    }
}

int TestOne (const TestData* allData)
{
    double rootst[MA] = {}, coeffst[NOP] = {};
    coeffst[0] = allData -> a;
    coeffst[1] = allData -> b;
    coeffst[2] = allData -> c;

    SquareSolver (coeffst, rootst);

    return ( (IsZero (rootst[0] - (allData -> x1)) && IsZero (rootst[1] - (allData -> x2))) || (IsZero (rootst[1] - (allData -> x1)) && IsZero (rootst[0] - (allData -> x2)) ) );
}

void TestAll()
{
    TestData allData[nTests] = {{ 0, 0, 0, 0, 0},
                                { 1, 0, -4, -2, 2},
                                { 1, 2, 1, -1, -1},
                                { 6, -24, 0, 0, 4},
                                { 1, -24, 0, 0, 24},
                                { 0.1, 0, -10, 10, -10}};

    int nOk = 0;

    for (int i = 0; i < nTests; i++)
        nOk += TestOne(&allData[i]);

    (nOk == nTests)? printf("# Test - Ok.\n") : printf("# Error...\n");

}
