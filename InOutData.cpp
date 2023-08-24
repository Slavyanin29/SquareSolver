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