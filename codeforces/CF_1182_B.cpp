//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1182/B
//   Date    :   2019/06/11
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

LL gcd (LL a, LL b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int h, w;
    int sum = 0;
    scanf("%d %d", &h, &w);
    vector<string> str(h);
    for (int i = 0; i < h; ++i)
        cin >> str[i];
    
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            if (str[i][j] == '*')
                sum++;
            
    int x = -1, y = -1;
    for (int i = 1; i < h-1; ++i)
        for (int j = 1; j < w-1; ++j)
            if (str[i][j] == '*' && str[i-1][j] == '*' && str[i+1][j] == '*' && str[i][j-1] == '*' && str[i][j+1] == '*') {
                x = i;
                y = j;
            }
    //printf("%d %d\n", x, y);
    if (x == -1 && y == -1) {
        printf("NO\n");
        return 0;
    }
    int ans = 1;
    int a = x, b = y;
    while (a-1>=0 && str[--a][b] == '*') {
        ans++;
    }
    a = x, b = y;
    while (a+1<h && str[++a][b] == '*') {
        ans++;
    }
    a = x, b = y;
    while (b-1>= 0&& str[a][--b] == '*') {
        ans++;
    }
    a = x, b = y;
    while (b+1<w && str[a][++b] == '*') {
        ans++;
    }
    
    if (ans == sum)
        printf("YES\n");
    else
        printf("NO\n");

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
