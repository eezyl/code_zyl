//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1154/B
//   Date    :   2019/04/14
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


    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    sort(nums.begin(), nums.end());
    set<int> s;
    for (int i = 1; i < n; i++) if (nums[i] - nums[i-1] != 0)
        s.insert(nums[i] - nums[i-1]);
    if (n == 1)
        printf("0\n");
    else if (s.size() == 0)
        printf("0\n");
    else if (s.size() > 1)
        printf("-1\n");
    else if (s.size() == 1) {
        for (auto it: s)
            if (it%2)
                cout << it << endl;
            else
                cout << it/2 << endl;
    }
    /*
    else {
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) if (nums[i] - nums[i-1] != 0) {
            if (a == 0)
                a = nums[i] - nums[i-1];
            else if (a != nums[i] - nums[i-1])
                b = nums[i] - nums[i-1];
        }

    }
    */

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
