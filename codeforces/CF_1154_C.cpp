//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1154/C
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


    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int n1 = a / 3;
    n1 = std::min(n1, b/2);
    n1 = std::min(n1, c/2);
    long long ans = 0;
    ans += n1*7;
    a -= n1*3;
    b -= n1*2;
    c -= n1*2;
    int arr[7] = {0, 1, 2, 0, 2, 1, 0};
    long long best = 0;
    for (int i = 0; i < 7; i++) {
        long long sum = 0;
        int a1 = a;
        int b1 = b;
        int c1 = c;
        for (int j = 0; j < 7; j++) {
            int num = arr[(i+j)%7];

            if (num == 0) {
                if (a1 == 0)
                    break;
                a1--;
                sum++;
            }
            else if (num == 1) {
                if (b1 == 0)
                    break;
                b1--;
                sum++;
            }
            else if (num == 2) {
                if (c1 == 0)
                    break;
                c1--;
                sum++;
            }
        }
        best = std::max(best, sum);
    }
    printf("%d\n", ans + best);

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
