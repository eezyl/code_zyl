//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1157/B
//   Date    :   2019/04/26
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


using namespace std;

typedef long long LL;

const int INF = 1 << 25;

//#define LOCAL
const LL LL_INF = 1 << 61;
int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int n;
    scanf("%d", &n);
    char str[200005];
    scanf("%s", str);

    vector<int> digit(11);
    for (int i = 1; i <= 9; i++) {
        scanf("%d", &digit[i]);
    }
    int c = 0;
    while (c<n && str[c]-'0' >= digit[str[c]-'0']) {
        c++;
    }
    while (c<n && str[c]-'0' <= digit[str[c]-'0']) {
        str[c] = digit[str[c]-'0'] + '0';
        c++;
    }

    printf("%s\n", str);

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
