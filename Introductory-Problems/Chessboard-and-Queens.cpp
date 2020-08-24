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
map <pair<int, int>, bool> occ;
// N QUEEN
ll sols = 0, N = 0;
bool can_place(vector <int> pos, int col)
{
    int row = pos.size();
    for(int i = 0; i < pos.size(); i ++)
        if(pos[i] == col || abs(row - i) == abs(col - pos[i]))
            return false;
    return true;
}
bool check_sol(vector <int> pos)
{
    for(int i = 0; i < N; i++)
        if(occ[{i, pos[i]}])
            return false;
    return true;
}
void solve(vector<int> pos)
{
    if(pos.size() == N )
    {
        if(check_sol(pos))
            sols ++;
        return;
    }

    for(int i = 0; i < N; i ++)
    {
        if(can_place(pos, i))
            {
                pos.push_back(i);
                solve(pos);
                pos.pop_back();
            }
    }
    return ;
}

//
void test_case()
{
    vector <string> board(8);
    for(auto &x : board)
        cin >> x;

    for(int i = 0; i < 8; i ++)
        for(int j = 0; j < 8; j ++)
            if(board[i][j] == '*')
                occ[{i, j}] = true;

    N = 8;
    for(int i = 0; i < N; i ++)
        solve({i}) ;
    
    cout << sols << endl;
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