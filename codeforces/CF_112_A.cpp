//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/112/A
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
    char str1[105], str2[105];
    scanf("%s", str1);
    scanf("%s", str2);

    for (int i = 0; i < strlen(str1); i++)
        str1[i] = tolower(str1[i]);
    for (int i = 0; i < strlen(str2); i++)
        str2[i] = tolower(str2[i]);

    printf("%d\n", strcmp(str1, str2));

    return 0;
}
