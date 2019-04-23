//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/208/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    char str[205];
    scanf("%s", str);
    bool useless[205] = {false};

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == 'W' && str[i+1] == 'U' && str[i+2] == 'B')
        {
            useless[i] = true;
            useless[i+1] = true;
            useless[i+2] = true;
            i = i + 2;
        }

        if (str[i+1] == '\0')
            useless[i+1] = true;
    }

    for (int i = 0; str[i]; i++)
    {
        if (useless[i] == false)
        {
            while (useless[i] == false)
            {
                printf("%c", str[i]);
                i++;
            }
            printf(" ");
            if (str[i] == '\0')
                break;
        }
    }
    printf("\n");
    return 0;
}
