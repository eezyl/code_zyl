//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/71/A
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
    int T;
    scanf("%d", &T);
    while (T--)
    {
        char str[103];
        scanf("%s", str);
        int count;
        char last_letter;
        char first_letter = str[0];
        for (count = 0; str[count] != '\0'; count++)
        {
            last_letter = str[count];
        }
        if (count > 10)
            printf("%c%d%c\n", first_letter, count-2, last_letter);
        else
            printf("%s\n", str);
    }
    return 0;
}
