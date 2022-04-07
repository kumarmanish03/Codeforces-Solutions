// Manish Kumar, IIIT Allahabad

// https://codeforces.com/contest/1632/problem/C
// https://www.youtube.com/watch?v=Xg79ffvNkRQ&t=545s

#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 0;

int getMSB(int n){
	int msb = 30;
	for(; msb >= 0; msb--){
		if(n & (1 << msb)){
			break;
		}
	}
	return msb;
}

int solve(){
	int a, b;
	cin >> a >> b;
	int msb = getMSB(b);
	int mx = (1 << msb) * 2 - 1;
	int ans = INT_MAX;
	for(int x = a; x < b; x++){
		vector<int> v(msb+1, 0);
		int y = x;
		for(int i = 0; i <= msb; i++){
			if(y & (1 << i)){
				v[i] = 0;
			} else{
				v[i] = (1 << i);
			}
		}
		for(int i = 1; i < v.size(); i++){
			v[i] += v[i-1];
		}
		for(int i = msb; i >= 0; i--){
			if(y >= b) break;
			if(i == 0){
				y |= 1;
			}else{
				if(v[i-1] + y >= b) continue;
				int add = v[i] - v[i-1];
				y += add;
			}
		}
		int step = y - b + x - a;
		// a = a|b;
		if(x != y) step++;
		ans = min(ans, step);
	}
	cout << ans << "\n";

	return 0;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin>>t;
	while(t--) solve();
}
