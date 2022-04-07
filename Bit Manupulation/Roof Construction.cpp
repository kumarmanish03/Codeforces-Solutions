// Manish Kumar, IIIT Allahabad
// Medium

https://codeforces.com/contest/1632/problem/B

// For a given n, max no. lower than n has power of 2 ex. low2(15) = low2(11) = 8
// So we had to arrange no. like max adjacent xor will come that low2()
// Ans : First arrange n to low(n) then 0 to low(n)-1
// Their max adjacent xor will come =low(n)

#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 0;

int low2(int n)
{
    int res = 0;
    for (int i=n; i>=1; i--)
    {
        // If i is a power of 2
        if ((i & (i-1)) == 0)
        {
            res = i;
            break;
        }
    }
    return res;
}

int solve(){
  int n;
  cin >> n;

  int k = low2(n);
  
  if(k == n){
    k/=2;
  }

  int i = n-1;
  while(i >= k){
    cout << i-- << " ";
  }
  int j = 0;
  while(j < k){
    cout << j++ << " ";
  }
  cout << "\n";
  
  return 0;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin>>t;
  while(t--) solve();
}
