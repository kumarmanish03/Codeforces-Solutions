// Manish Kumar, IIIT Allahabad
// Good

// https://codeforces.com/contest/1658/problem/C

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define _print(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";

#define int long long

void solve(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int &x:v)
		cin >> x;

	bool isOne = false, found = true;
	for(int i = 0; i < n; i++){
		if(v[i] == 1){
			isOne = true;
			rotate(v.begin(), v.begin()+i, v.end());
		}
	}

	if(isOne){
		for(int i = 0; i < n-1; i++){
			if(v[i+1] == 1){
				return void(print("NO"));
			}
			int delta = v[i+1] - v[i];
			if(delta > 0){
				if(delta > 1){
					return void(print("NO"));
				}
			}
		}
	}
	else {
		return void(print("NO"));
	}

	return void(print("YES"));

}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin>>t;
	while(t--) solve();
}
