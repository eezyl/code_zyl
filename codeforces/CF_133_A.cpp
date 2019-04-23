//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/133/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    char str[200];
    scanf("%s", str);

    for (int i = 0; str[i]; i++)
        if (str[i] == 'H' || str[i] == 'Q' || str[i] == '9')
        {
            printf("YES\n");
            return 0;
        }
    printf("NO\n");

    return 0;
}
