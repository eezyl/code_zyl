//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/58/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    char hello[10] = "hello";
    char str[105];
    scanf("%s", str);

    int count = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] == hello[count])
            count++;

    if (count == 5)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
