//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1167/B
//   Date    :   2019/05/15
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
    int a, b, c, d;
    vector<int> num(6);
    num[0] = 4;
    num[1] = 8;
    num[2] = 15;
    num[3] = 16;
    num[4] = 23;
    num[5] = 42;
    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d", &a);
    printf("? 2 3\n");
    fflush(stdout);
    scanf("%d", &b);

    printf("? 4 5\n");
    fflush(stdout);
    scanf("%d", &c);
    printf("? 5 6\n");
    fflush(stdout);
    scanf("%d", &d);

    do {
        if (a == num[0]*num[1] && b == num[1]*num[2] &&
            c == num[3]*num[4] && d == num[4]*num[5]) {
            printf("! ");
            for (int i = 0; i < 6; i++)
            printf("%d ", num[i]);
            printf("\n");
            fflush(stdout);
            break;
        }
    } while (next_permutation(num.begin(), num.end()));


#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
