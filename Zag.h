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
    COMPL = 3,
    MANY_SOL = 4,
};

struct TestData
{
    double a, b, c;
    double x1, x2;
};

int IsZero (double x);
int SquareSolver (double coeffs[], double roots[]);
void InputCoeffs (double coeffs[], int NOP);
void ComplPrint (double roots[]);
void PrintRoots (double roots[], int NumbOfSolutions);
int TestOne (const TestData* allData);
void TestAll ();
