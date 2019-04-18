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

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        //freopen("data.out", "w", stdout);
    #endif // LOCAL

    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    if (x1 != x2 && y1 != y2 && abs(x1-x2) != abs(y1-y2))
        printf("-1\n");
    else if (x1 == x2 && y1 == y2)
        printf("-1\n");
    else {
        if (x1 == x2) {
            int d = abs(y2-y1);
            printf("%d %d %d %d\n", d+x1, y1, d+x2, y2);
        } else if (y1 == y2) {
            int d = abs(x2 - x1);
            printf("%d %d %d %d\n", x1, d+y1, x2, d+y2);
        }
        else {
            printf("%d %d %d %d\n", x1, y2, x2, y1);
        }
    }


    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
