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
