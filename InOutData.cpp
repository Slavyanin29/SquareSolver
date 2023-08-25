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

        case COMPL: ComplPrint (roots);
                    break;

        case MANY_SOL: printf ("Any number is a solution\n");
                       break;

        default: printf ("# Error!!! Solutions = %d", NumbOfSolutions);

    }

    printf ("# Thanks for using this program!     ^   ^ \n");
    printf ("#                                   (='I'=)\n");
}

void ComplPrint (double roots[])
{
    printf ("# The answer is a complex number.\n# Press Enter to leave the program. Press any other button to see the answer.\n");

    int ch = getchar();

    if ((ch = getchar()) != '\n')
    {
            if (IsZero(roots[0]))
            {
                printf ("x1 = %lg * i\n", roots[1]);
                printf ("x2 = - %lg * i\n", roots[1]);
            }
            else
            {
                printf ("x1 = %lg - %lg * i\n", roots[0], roots[1]);
                printf ("x2 = %lg + %lg * i\n", roots[0], roots[1]);
            }
    }
}
