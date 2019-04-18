//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/519/A
//   Date    :   2019/04/18 (upload date)
//
//********************************************************

//#define LOCAL

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

typedef long long LL;

const int INF = 1 << 25;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        //freopen("data.out", "w", stdout);
    #endif // LOCAL

    char str[20];
    int black = 0;
    int white = 0;
    for (int i = 0; i < 8; i++) {
        scanf("%s", str);
        for (int j = 0; j < 9; j++) {
             switch (str[j]) {
             case 'q':
                black += 9;
                break;
             case 'r':
                black += 5;
                break;
             case 'b':
                black += 3;
                break;
             case 'n':
                black += 3;
                break;
             case 'p':
                black += 1;
                break;

             case 'Q':
                white += 9;
                break;
             case 'R':
                white += 5;
                break;
             case 'B':
                white += 3;
                break;
             case 'N':
                white += 3;
                break;
             case 'P':
                white += 1;
                break;
             }
        }
    }

    if (white > black)
        printf("White\n");
    else if (black > white)
        printf("Black\n");
    else
        printf("Draw\n");

    //printf("%d\n", ans);

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
