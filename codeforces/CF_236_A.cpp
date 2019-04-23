//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/236/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
    set<char> s;
    char str[105];
    scanf("%s", str);

    for (int i = 0; str[i]; i++)
        s.insert(str[i]);

    if (s.size() % 2 == 0)
        printf("CHAT WITH HER!\n");
    else
        printf("IGNORE HIM!\n");

    return 0;
}
