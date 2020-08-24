/**
 * Author : Deep Raval
 * There are no two words in the English language more harmful than "good job".
 * 1729 0_0
**/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <numeric>
using namespace std;
using ll = long long;
#define endl '\n'
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) 
{
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define FAST_IO ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define bp(x) __builtin_popcount(x)
#define zf(x) __builtin_clz(x)
#define zl(x) __builtin_ctz(x)
#define par(x) __bultin_parity(x)
#define all(x) (x).begin(), (x).end()
/* **************************************************************************************** */
int n;
ll total_sum = 0, ans = 0;
ll a[21];
void solve(int i, ll cur_sum = 0)
{
    if(i == n)
    {
        ans = min(ans, abs(cur_sum - (total_sum - cur_sum)));
        return;
    }
    solve(i + 1, cur_sum);
    solve(i + 1, cur_sum + a[i]);
}
void test_case()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
        total_sum += a[i];
    }
    ans = total_sum;

    solve(0, 0);
    cout << ans << endl;
    return;
}
int main()
{
	FAST_IO
    int t = 1;
    // cin >> t;
    while(t--)
        test_case();
	return 0;
}