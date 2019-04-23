//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/96/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char str[110];
    scanf("%s", str);

    int flag = 1;
    int len = strlen(str);
    for (int i = 0; i < len && flag; i++)
    {
        char ch = str[i];
        for (int j = i+1; j <= i+6; j++)
            if (str[j] != ch)
                break;
            else if (j == i+6)
                flag = 0;
    }

    if (flag == 1)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}
