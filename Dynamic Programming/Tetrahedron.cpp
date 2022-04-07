// Manish Kumar, IIIT Allahabad

https://codeforces.com/contest/166/problem/E

#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 10e9+7;

int solve(){
  int n;
  cin >> n;
  int dp[2][n+1];
  // dp[pos][steps] : no. of ways if we are at this pos(top 1, bottom 0) and n{steps} left 
  dp[0][0] = 0; // 0 step : not possible
  dp[1][0] = 1; // 1 step : dont move at all
  for(int j = 1; j < n+1; j++){
    dp[1][j] = 3*dp[0][j-1] % MOD;
    dp[0][j] = (2*dp[0][j-1] + dp[1][j-1]) % MOD;
  }
  cout << dp[1][n];
  return 0;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin>>t;
  while(t--) solve();
}
