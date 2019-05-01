//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1156/A
//   Date    :   2019/05/01
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
#include <bitset>


using namespace std;

typedef long long LL;

const int INF = 1 << 25;
const LL LL_INF = 1ll << 61;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int n;
    int ans = 0;
    scanf("%d", &n);
    vector<int> shape(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &shape[i]);
    for (int i = 1; i < n; i++) {
        if (shape[i] == shape[i-1]) {
            printf("Infinite\n");
            return 0;
        } else if (shape[i] == 2 && shape[i-1] == 3) {
            printf("Infinite\n");
            return 0;
        } else if (shape[i] == 3 && shape[i-1] == 2) {
            printf("Infinite\n");
            return 0;
        } else if (shape[i] == 2 && shape[i-1] == 1) {
            ans += 3;
        } else if (shape[i] == 1 && shape[i-1] == 2) {
            ans += 3;
        } else if (shape[i] == 3 && shape[i-1] == 1) {
            ans += 4;
        } else if (shape[i] == 1 && shape[i-1] == 3) {
            ans += 4;
        }
    }
    printf("Finite\n");
    printf("%d\n", ans);
    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
