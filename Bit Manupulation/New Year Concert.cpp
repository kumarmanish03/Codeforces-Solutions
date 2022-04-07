/* Manish Kumar, IIIT Allahabad
** Hard
** Binary Search + Sparse table + Greedy Approach
**
** https://www.youtube.com/watch?v=mcuqPXHPzeo&t=1025s
** https://codeforces.com/contest/1632/problem/D
**
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define printArr(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";

// #define int long long

// ===============================================================

const int N = 2e5;
const int K = 20;

int table[N+1][K];
int arr[N+1];

bool cmp(vector<vector<int>>&a, vector<vector<int>>&b){
	if(a[1] == b[1])
		return a[0] < b[0];
	return a[1] < b[1];
}

int gcd(int a, int b){
	if(a == 0)
		return b;
	return gcd(b%a, a);
}

void sparse(int n){
	for(int i = 1; i <= n; i++){
		table[i][0] = arr[i];
	}
	for(int j = 1; j <= K; j++){
		for(int i = 1; i + (1 << j) <= n+1; i++){
			table[i][j] = __gcd(table[i][j-1], table[i + (1 << (j-1))][j-1]);
		}
	}
	return;
}

int getGCD(int l, int r, int n){
	int j = log2(r - l + 1);
	return __gcd(table[l][j], table[r - (1 << j) + 1][j]);
}

int solve(){
	int n;
	vector<vector<int>> ranges;
	cin >> n;

	for(int i = 1; i < n+1; i++)
		cin >> arr[i];

	sparse(n);

	for(int i = 1; i < n+1; i++){
		int l = i, r = n, ans = -1, mid;
		while(l <= r){
			mid = (l + r)/2;

			int val_gcd = getGCD(i, mid, n);

			if(val_gcd == mid - i + 1){
				ans = mid;
				break;
			}
			else if(val_gcd > mid - i + 1){
				l = mid + 1;
			}
			else
				r = mid - 1;
		}

		if(ans != -1)
			ranges.push_back({ans, i});
	}

	sort(ranges.begin(),ranges.end());

	vector<int> ans(n+1, 0);
	int smallR = -1;
	for(auto v:ranges){
		if(v[1] <= smallR and smallR <= v[0]){
			continue;
		}
		smallR = v[0];
		ans[v[0]] = 1;
	}
	
	for(int i = 1; i < n+1; i++)
		ans[i] += ans[i-1];

	for(int i = 1; i < n+1; i++)
		cout << ans[i] << " ";
	cout << "\n";

	return 0;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin>>t;
	while(t--) solve();
}
