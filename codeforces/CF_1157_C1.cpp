//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1157/C1
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
int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int n;
    scanf("%d", &n);
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    vector<char> ans;

    int head = 0;
    int tail = n-1;
    int baseline = -1;
    while (head <= tail) {
        //cout << baseline << endl;
        if (nums[head] > baseline && nums[tail] > baseline) {
            if (nums[head] > baseline && nums[head] < nums[tail]) {
                baseline = nums[head];
                head++;
                ans.push_back('L');
            } else if (nums[tail] > baseline && nums[tail] < nums[head]) {
                baseline = nums[tail];
                tail--;
                ans.push_back('R');
            } else if (head == tail) {
                ans.push_back('R');
                break;
            }
        } else if (nums[head] > baseline) {
            baseline = nums[head];
            head++;
            ans.push_back('L');
        } else if (nums[tail] > baseline) {
            baseline = nums[tail];
            tail--;
            ans.push_back('R');
        } else if (nums[tail] <= baseline && nums[head] <= baseline)
            break;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        printf("%c", ans[i]);
    printf("\n");

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
