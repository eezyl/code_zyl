//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1157/F
//   Date    :   2019/04/29
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

const int INF = 1 << 30;
const LL LL_INF = 1 << 62;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> count(200005, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        count[a[i]]++;
    }

    vector<int> best_ans;
    vector<int> cur_ans;
    cur_ans.reserve(200005);
    for (int i = 1; i <= 200000; i++) if (count[i]) {
        int l = i;
        int r = i+1;
        cur_ans.clear();
        while (count[r] >= 2)
            r++;
        for (int j = l; j < r; j++) {
            if (j == l) {
                for (int k = 0; k < count[j]; k++)
                    cur_ans.push_back(j);
            } else
                for (int k = 0; k < count[j]-1; k++)
                    cur_ans.push_back(j);
        }
        if (count[r] == 1)
            cur_ans.push_back(r);
        for (int j = r-1; j > l; j--) {
            cur_ans.push_back(j);
        }
        if (best_ans.size()<cur_ans.size())
            best_ans = cur_ans;
        i = r-1;
    }

    cout << best_ans.size() << endl;
    for (int i = 0; i < best_ans.size(); i++)
        printf("%d ", best_ans[i]);
    printf("\n");


    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
