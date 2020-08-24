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
#pragma GCC optimize("O2") 
string s;
int ans = 0;
bool visited[7][7];
inline bool cv(int x, int y)
{
    return x >= 0 && x <= 6 && y >=0 && y <=6 && !visited[x][y];
}

inline void solve(int r, int c, int cur_path)
{
    if(r == 6 && c == 0)
    {
        if(cur_path == 48)
        {
            ans++;
        }
        return;
    }


    visited[r][c] = true;

    if(c && !visited[r][c - 1] && (s[cur_path] == '?' || s[cur_path] == 'L') && !( !cv(r, c - 2) && cv(r + 1, c - 1) && cv(r - 1, c - 1)))
        solve(r, c- 1, cur_path + 1);

    if(c < 6 && !visited[r][c + 1] && (s[cur_path] == '?' || s[cur_path] == 'R') && !( !cv(r, c + 2) && cv(r + 1, c + 1) && cv(r - 1, c + 1)))
        solve(r, c + 1, cur_path + 1);

    if(r && !visited[r - 1][c] && (s[cur_path] == '?' || s[cur_path] == 'U') && !( !cv(r - 2, c) && cv(r - 1, c + 1) && cv(r - 1, c - 1)))
        solve(r - 1, c, cur_path + 1);

    if(r < 6 && !visited[r + 1][c] && (s[cur_path] == '?' || s[cur_path] == 'D') && !( !cv(r + 2, c) && cv(r + 1, c + 1) && cv(r + 1, c - 1)))
        solve(r + 1, c, cur_path + 1);

    visited[r][c] = false;
    return;
}

void test_case()
{
    cin >> s;
    solve(0, 0, 0);
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