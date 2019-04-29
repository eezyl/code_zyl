//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1152/B
//   Date    :   2019/04/24
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

bool isPerfect(int n, vector<int>& perf_nums) {
    for (int i = 0; i < perf_nums.size(); i++)
        if (n == perf_nums[i])
            return true;
    return false;
}

//#define LOCAL
const LL LL_INF = 1 << 61;
int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int n = 31;
    int c = 1;
    vector<int> perf_nums(n);
    for (int i = 0; i < n; i++) {
        perf_nums[i] = c;
        c = c*2+1;
    }
    int x;
    scanf("%d", &x);
    vector<int> ans;
    while (!isPerfect(x, perf_nums)) {
        int max_not0 = -1;
        for (int i = 1 << 30, k = 30; i != 0; i >>= 1, k--) {
            //cout << int(x&i) << " "<<int(x&(i*2)) << endl;
            if ( ( (x&i) == 0) && ((x&(i*2)) != 0)) {
                max_not0 = k;
                break;
            }
        }
        //printf("%d\n", max_not0);
        ans.push_back(max_not0+1);
        for (int i = 1, k = 0; k <= max_not0; i <<= 1, k++)
            x = x^i;
        if (isPerfect(x, perf_nums))
            break;
        ans.push_back(-1);
        x = x+1;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        if (i%2==0)
            cout << ans[i] << " ";
    cout << endl;

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
