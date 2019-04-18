//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/550/A
//   Date    :   2019/04/18 (upload date)
//
//********************************************************

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
#include <bitset>
#include <unordered_map>
using namespace std;

typedef long long LL;

const int INF = 1 << 25;

//#define LOCAL

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        //freopen("data.out", "w", stdout);
    #endif // LOCAL

    char str[100005];
    scanf("%s", str);
    int n = strlen(str);

    /*
    int flagAB = 0;
    int flagBA = 0;
    int repeat = 0;
    int medium_char = -1;
    for (int i = 0; i < n-1; i++) {
        if (i < n-2 && str[i] == 'A' && str[i+1] == 'B' && str[i+2] == 'A') {
            repeat++;
            i += 2;
        }
        else if (i < n-2 && str[i] == 'B' && str[i+1] == 'A' && str[i+2] == 'B') {
            repeat++;
            i +=2 ;
        }
        else if (str[i] == 'A' && str[i+1] == 'B') {
            flagAB++;
        }
        else if (str[i] == 'B' && str[i+1] == 'A') {
            flagBA++;
        }

    }
    if (flagAB == 0 && repeat != 0) {
        flagAB++;
        repeat--;
    }
    if (flagBA == 0 && repeat != 0) {
        flagBA++;
        repeat--;
    }

    if (flagAB == 0 || flagBA == 0)
        printf("NO\n");
    else
        printf("YES\n");
*/

    int i = 0;
    int flag = false;
    for (; i < n-1; i++)
        if (str[i] == 'A' && str[i+1] == 'B') {
        i += 2;
        break;
    }

    for (; i < n-1; i++)
        if (str[i] == 'B' && str[i+1] == 'A') {
        flag = true;
        break;
    }

    i = 0;
    for (; i < n-1; i++)
        if (str[i] == 'B' && str[i+1] == 'A') {
        i += 2;
        break;
    }

    for (; i < n-1; i++)
        if (str[i] == 'A' && str[i+1] == 'B') {
        flag = true;
        break;
    }

    if (flag)
        puts("YES\n");
    else
        puts("NO\n");

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
