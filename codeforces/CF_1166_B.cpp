//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1166/B
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

    int k;
    scanf("%d", &k);
    char vowel[] = {'a', 'e', 'i', 'o', 'u'};
    int sq = sqrt(k);
    for (int i = sq; i>= 0; i++) {
        if (k % i == 0) {
            if (k / i < 5 || i < 5) {
                printf("-1\n");
                break;
            }
            else {
                for (int j = 0; j < i; j++) {
                    for (int m = 0; m < k/i; m++)
                        printf("%c", vowel[(j+m)%5]);
                    //printf("\n");
                }
                printf("\n");
                break;
            }
        }
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
