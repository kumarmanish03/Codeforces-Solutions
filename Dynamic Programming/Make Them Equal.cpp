// Manish Kumar, IIIT Allahabad
// Medium-Hard 

// Refer Video : https://www.youtube.com/watch?v=7n0uMlJHCy0&t=1480s
// https://codeforces.com/contest/1633/problem/D

#include<bits/stdc++.h>
using namespace std;

// template <typename T>
// void print(T &&t)  { cout << t << "\n"; }
// template <typename T, typename... Args>
// void print(T &&t, Args &&... args)
// {   cout << t << " ", print(forward<Args>(args)...); }
// #define printArr(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";

// #define int long long

// ===============================================================

const int N = 1e3;
vector<int> step(N+1, 1e6);

void pre(){
	step[0] = step[1] = 0;
	step[2] = 1;
	for(int i = 2; i < N+1; i++){
		for(int j = 1; j <= i; j++){
			int d = i + i/j;
			if(d < N+1) step[d] = min(step[d], 1 + step[i]);
		}
	}
	return;
}

int solve(){
	int n, k, temp = 0;
	cin >> n >> k;
	vector<int> b(n), c(n);
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}

	int dp[2][k+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i < n+1; i++){
		for(int j = 0; j < k+1; j++){
			if(step[b[i-1]] <= j)
				dp[i&1][j] = max(dp[(i+1)&1][j], c[i-1] + dp[(i+1)&1][j-step[b[i-1]]]);
			else
				dp[i&1][j] = dp[(i+1)&1][j];
		}
	}

	cout << dp[n&1][k] << "\n";
	
	return 0;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pre();
	int t = 1;
	cin>>t;
	while(t--) solve();
}
