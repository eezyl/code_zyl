//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/474/A
//   Date    :   2019/04/18 (upload date)
//
//********************************************************

//#define LOCAL

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <vector>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL


    string line1 = "qwertyuiop";
    string line2 = "asdfghjkl;";
    string line3 = "zxcvbnm,./";

    char ch;
    scanf("%c", &ch);
    char str[150];
    scanf("%s", str);

    for (int i = 0; str[i]; i++)
    {
        for (int j = 0; j < 10; j++)
            if (line1[j] == str[i])
            {
                str[i] = ch == 'R' ? line1[j-1] : line1[j+1];
                break;
            }
            else if (line2[j] == str[i])
            {
                str[i] = ch == 'R' ? line2[j-1] : line2[j+1];
                break;
            }
            else if (line3[j] == str[i])
            {
                str[i] = ch == 'R' ? line3[j-1] : line3[j+1];
                break;
            }
    }
    printf("%s\n", str);



    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
