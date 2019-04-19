//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1151/B
//   Date    :   2019/04/19
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

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int m, n;
    scanf("%d %d", &m, &n);
    vector<vector<int> > nums(m+1, vector<int>(n+1));
    vector<int> ans(m+1, 1);
    int result = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &nums[i][j]);
        }
        result ^= nums[i][1];
    }
    int indx = n;
    int row = m;
    while (result == 0 && row != 0) {
        for (int i = indx; i > 0; i--)
            if (nums[row][i] != nums[row][1]) {
                ans[row] = i;
                result = 1;
                break;
            }
        if (result == 0)
            ans[row] = n;
        row-=1;
    }
    if (result != 0) {
        printf("TAK\n");
        for (int i = 1; i <= m; i++)
            printf("%d ", ans[i]);
    } else
        printf("NIE");
    printf("\n");
    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
