//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/266/B
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    int n, t;
    char str[100];
    scanf("%d%d", &n, &t);
    scanf("%s", str);

    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j < n-1; j++)
            if (str[j] == 'B' && str[j+1] == 'G')
            {
                swap(str[j], str[j+1]);
                j++;
            }
    }

    printf("%s\n", str);

    return 0;
}
