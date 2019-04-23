//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/131/A
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
    char str[105];
    scanf("%s", str);
    int len = strlen(str);
    int upper_num = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            upper_num++;

    if (str[0] >= 'a' && str[0] <= 'z' && upper_num == len-1)
    {
        printf("%c", toupper(str[0]));
        for (int i = 1; str[i]; i++)
            printf("%c", tolower(str[i]));
    }
    else if (upper_num == len)
    {
        for (int i = 0; str[i]; i++)
            printf("%c", tolower(str[i]));
    }
    else
        printf("%s", str);

    printf("\n");
    return 0;
}
