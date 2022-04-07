// Manish Kumar, IIIT Allahabad

https://codeforces.com/contest/1658/problem/D1

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define _print(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";

#define int long long

int solve(){
	int l, r, x, ans = 0;
	vector<int> v(18, 0), v2(18, 0);
	cin >> l >> r;
	for(int i = 0; i < (r-l+1); i++){
		cin >> x;
		for(int j = 0; 1<<j <= x; j++){
			if(1 << j & x){
				v[j]++;
			}
		}
	}

	for(int x = l; x <= r; x++){
		for(int j = 0; 1<<j <= x; j++){
			if(1 << j & x){
				v2[j]++;
			}
		}
	}

	for(int i = 0; i < 18; i++){
		if(v[i] != v2[i])
			ans += (1 << i);
	}

	print(ans);

	
	return 0;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin>>t;
	while(t--) solve();
}
