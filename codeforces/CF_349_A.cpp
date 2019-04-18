//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/349/A
//   Date    :   2019/04/17 (upload date)
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

    int n;
    scanf("%d", &n);

    int num25 = 0;
    int num50 = 0;

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (num == 25)
            num25++;
        else if (num == 50) {
            if (num25 > 0)
                num25--;
            else {
                printf("NO\n");
                return 0;
            }
            num50++;
        }
        else {
            if (num50 > 0 && num25 > 0) {
                num50--;
                num25--;
            } else if (num25 >= 3) {
                num25-=3;
            } else {
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
