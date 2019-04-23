//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/263/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    int x_1, y_1;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            int num;
            scanf("%d", &num);
            if (num == 1)
            {
                x_1 = i;
                y_1 = j;
            }
        }

    printf("%d\n", abs(x_1 - 2) + abs(y_1 - 2));
    return 0;
}
