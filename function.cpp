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
