//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/282/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int x = 0;
    char str[5];

    while (n--)
    {
        scanf("%s", str);
        if (str[1] == '+')
            x++;
        else
            x--;
    }

    printf("%d\n", x);
    return 0;
}
