#include <stdio.h>
#include <math.h>
#include <ctype.h>
//#include <complex.h>
#include "Zag.h"
#include "InOutData.cpp"
#include "function.cpp"
#include "Tests.cpp"
//#define NDEBUG
//#include <assert.h>

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
