//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1154/D
//   Date    :   2019/04/17
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


    int n, b, a;
    scanf("%d %d %d", &n, &b, &a);
    int max_a = a;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            if (a > 0) {
                ans++;
                a--;
            } else if (b > 0) {
                ans++;
                b--;
            } else
                break;
        } else {
            if (a == max_a) {
                a--;
                ans++;
            }
            else if (b > 0) {
                b--;
                a = std::min(max_a, a+1);
                ans++;
            } else if (a > 0) {
                a--;
                ans++;
            } else
                break;
        }
        // printf("%d %d\n", b, a);
    }
    printf("%d\n", ans);

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
