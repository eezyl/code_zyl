//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1157/C2
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
/*
int solve(int head, int tail, vector<int>& nums) {

    if (head == tail) {
        return 1;
    }
    if (nums[head] == nums[tail]) {
        if (head+1 > tail-1)
            return 1;
        //if (nums[head+1] == nums[tail-1] && nums[head+1] > nums[head]) {
            int k = solve(head+1, tail-1, nums);
            if (k > 0)
                return k+1;
            else if (k < 0)
                return k-1;
    } else if (nums[head] <= nums[head-1])
        return -1;
    else if (nums[tail] <= nums[tail+1])
        return 1;
    else if (nums[head] > nums[tail])
        return -1;
    else
        return 1;
}
*/
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
            if (nums[head] < nums[tail]) {
                baseline = nums[head];
                head++;
                ans.push_back('L');
            } else if (nums[tail] < nums[head]) {
                baseline = nums[tail];
                tail--;
                ans.push_back('R');
            } else if (head == tail) {
                ans.push_back('R');
                break;
            } else if (nums[head] == nums[tail]) {
                int h = head;
                int h_count = 0;
                while (h+1 < tail && nums[h+1] > nums[h]) {
                    h++;
                    h_count++;
                }
                int t = tail;
                int t_count = 0;
                while (t-1 > head && nums[t-1] > nums[t]) {
                    t--;
                    t_count++;
                }
                //cout << head << " " << tail << endl;
                //cout << h_count <<" " <<t_count << endl;
                if (h_count > t_count) {
                    while (head < tail && nums[head] > baseline) {
                        baseline = nums[head];
                        ans.push_back('L');
                        head++;
                    }
                } else {
                    while (tail > head && nums[tail] > baseline) {
                        baseline = nums[tail];
                        ans.push_back('R');
                        tail--;
                    }
                }

                /*
                int k = solve(head, tail, nums);
                //cout << k << endl;
                if (k > 0) {
                    for (int i = 0; i < k-1; i++) {
                        if (nums[head] > baseline) {
                            baseline = nums[head];
                            head++;
                            ans.push_back('L');
                        } else
                            break;
                    }
                }
                else if (k < 0) {
                    k *= -1;
                    for (int i = 0; i < k-1; i++) {
                        if (nums[tail] > baseline) {
                            baseline = nums[tail];
                            tail--;
                            ans.push_back('R');
                        } else
                            break;
                    }
                }
                */
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
