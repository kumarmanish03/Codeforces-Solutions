// Manish Kumar, IIIT Allahabad

https://codeforces.com/contest/1660/problem/C

// DP + String

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define _print(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";

// #define int long long

string s;
int dp[200005];

int fun(int i){
	if(i >= s.size())
		return 0;

	if(i == s.size()-1)
		return 1;

	if(dp[i] != -1)
		return dp[i];

	if(i < s.size()-1 && s[i] == s[i+1]) 
		return dp[i] = fun(i+2);

	int j = i+1;
	while(j < s.size() && s[i] != s[j])
		j++;
	if(j >= s.size())
		return dp[i] = 1 + fun(i+1);
	else
		return dp[i] = min(1 + fun(i+1), j-i-1 + fun(j+1));
}

int solve(){
	cin >> s;
	int n = s.size();
	memset(dp, -1, sizeof(dp));
	print(fun(0));
	
	return 0;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin>>t;
	while(t--) solve();
}
