//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1154/E
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

    int n, maxk;
    scanf("%d %d", &n, &maxk);
    string ans(n, '0');
    vector<int> nums(n);
    vector<int> pos(n+1);
    vector<int> to_left(n+1, -5);
    vector<int> to_right(n+1, -5);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        pos[nums[i]] = i;
    }

    int flag = 1;
    for (int i = n; i > 0; i--) {
        if (pos[i] != -1) {
            int p = pos[i];

            int p1 = p-1;
            for (int k = 0; k < maxk; k++) {
                while(p1 >= 0 && to_left[p1] != -5)
                    p1 = to_left[p1];
                if (p1 < 0) {
                    break;
                } else if (nums[p1] != 0) {
                    ans[p1] = flag ? '1' : '2';
                    pos[nums[p1]] = -1;
                    nums[p1] = 0;
                } else if (nums[p1] == 0)
                    k--;
                p1--;
            }

            int p2 = p+1;
            for (int k = 0; k < maxk; k++) {
                while(p2 < n && to_right[p2] != -5)
                    p2 = to_right[p2];
                if (p2 >= n) {
                    break;
                } else if (nums[p2] != 0) {
                    ans[p2] = flag ? '1' : '2';
                    pos[nums[p2]] = -1;
                    nums[p2] = 0;
                } else if (nums[p2] == 0)
                    k--;
                p2++;
            }

            ans[p] = flag ? '1' : '2';
            nums[p] = 0;
            pos[i] = -1;
            to_left[p2-1] = p1;
            to_right[p1+1] = p2;
            flag = !flag;
        }
    }
    cout << ans << endl;

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
