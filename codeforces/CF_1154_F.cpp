//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1154/F
//   Date    :   2019/04/18
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

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    sort(nums.begin(), nums.end());
    nums.resize(k);
    // reverse(nums.begin(), nums.end());

    vector<int> purchase(k+1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x <= k)
            purchase[x] = std::max(purchase[x], y);
    }

    vector<int> prefix(k+1, 0);
    for (int i = 1; i <= k; i++) {
        prefix[i] = prefix[i-1] + nums[i-1];
    }

    vector<int> ans(k+1, 2147483647);
    ans[0] = 0;
    for (int i = 0; i <= k; i++) {
        if (ans[i] == 2147483647)
            continue;
        for (int j = 1; j+i <= k ; j++) {
            // ans[i+j] = std::min(ans[i+j], ans[i] + prefix[i+j-purchase[j]] - prefix[i]);
            ans[i+j] = std::min(ans[i+j], ans[i] + prefix[i+j] - prefix[i+purchase[j]]);
        }
    }
    printf("%d\n", ans[k]);

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
