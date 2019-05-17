//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1166/D
//   Date    :   2019/05/17
//
//********************************************************

//#define LOCAL
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;

const int INF = (1<<31)-1;
const LL LL_INF = (1ll << 63)-1;

int main()
{
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int q;
    scanf("%d", &q);
    for (int t = 0; t < q; t++) {
        LL a, b, m;
        scanf("%I64d %I64d %I64d", &a, &b, &m);
        if (a == b) {
            printf("1 %I64d\n", a);
            continue;
        }
        LL least = a+1;
        LL largest = a+m;
        vector<LL> ans;
        ans.push_back(a);
        while (1) {
            if (least > b) {
                printf("-1\n");
                break;
            }
            ans.push_back(least);
            if (least <= b && b <= largest) {
                LL diff = b - least;
                ans.back() = b;
                for (int i = ans.size()-2; i > 0; i--) {
                    ans[i] += (diff+1)/2;
                    diff -= (diff+1)/2;
                    if (diff == 0)
                        break;
                }
                printf("%d ", ans.size());
                for (int i = 0; i < ans.size(); i++)
                    printf("%I64d ", ans[i]);
                printf("\n");
                break;
            }
            least *= 2;
            largest *= 2;
        }
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
