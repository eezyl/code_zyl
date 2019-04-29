//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1157/E
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

int solve(int k, int n, vector<int>& count, vector<int>& pos) {
    //cout << count[k] << endl;
    if (count[k] > 0) {
        count[k]--;
        return k;
    } else if (pos[k] != -1 && k != pos[k]) {
        k = pos[k];
    } else {
        k = (k+1)%n;
    }
    //cout << k << endl;
    pos[k] = solve(k, n, count, pos);
    return pos[k];
}

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> b(n);
    vector<int> count(n, 0);
    vector<int> pos(n, -1);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        count[b[i]]++;
    }

    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        int k = (n-a[i])%n;
        //cout << a[i] << k << endl;
        ans[i] = (solve(k, n, count, pos) + a[i] )%n;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
