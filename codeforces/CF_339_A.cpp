//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/339/A
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
    char* ptr;
    int a[5] = {0};

    for (ptr = strtok(str, "+"); ptr != NULL; ptr = strtok(NULL, "+"))
        a[atoi(ptr)]++;

    int firstFlag = 0;
    for (int i = 1; i <= 3; i++)
        for (int j = 0; j < a[i]; j++)
            if (firstFlag == 0)
            {
                printf("%d", i);
                firstFlag = 1;
            }
            else
                printf("+%d", i);
    printf("\n");

    return 0;
}
