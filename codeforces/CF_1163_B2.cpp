//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1163/B2
//   Date    :   2019/05/09
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

bool isOK(map<int, int>& m, int k)
{
    if (m.size() >= 3)
        return false;
    if (m.size() == 1)
        if (m.begin()->second!=1 && m.begin()->first!=1)
            return false;
        else
            return true;
    // size == 2
    if (m.count(1)) {
        if (m[1] == k-2 || m[1] == 1)
            return true;
        else
            return false;
    }
    int d1 = m.begin()->first;
    if (m.count(d1+1) && m[d1+1] == 1)
        return true;

    return false;
}

int main()
{
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    vector<int> record(100005, 0);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        record[nums[i]]++;
    }
/*
    if (n <= 2) {
        printf("%d\n", n);
        return 0;
    }
*/
    for (int i = 100003; i >= 0; i--) {
        if (record[i] != 0) {
            auto it = m.find(record[i]);
            if (it == m.end())
                m[record[i]] = 1;
            else
                it->second++;
        }
    }

    if (isOK(m, n)) {
        printf("%d\n", n);
        return 0;
    }
    //cout << m.size() << endl;
    for (int i = n-1; i >=0; i--) {
        int num = nums[i];
        m[record[num]]--;
        if (m[record[num]] == 0)
            m.erase(record[num]);
        record[num]--;
        if (record[num] != 0) {
            if (m.count(record[num]))
                m[record[num]]++;
            else
                m[record[num]] = 1;
        }
        if (m.size() == 1) {
            printf("%d\n", i+1);
            return 0;
        }
        //cout << m.size() << endl;
        if (isOK(m, i)) {
            printf("%d\n", i);
            return 0;
        }
    }


#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
