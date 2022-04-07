// Manish Kumar, IIIT Allahabad

// https://codeforces.com/contest/1485/problem/D

// since all no 1 <= a <= 16 and their lcm is the multiple of all no. of matrix

#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 0;

int solve(){
  int lcm = 1;
  for(int i = 2; i <= 16; i++){
    lcm = (lcm * i) / __gcd(lcm, i);
  }

  int n, m;
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int a;
      cin >> a;
      if((i + j) % 2){
        cout << lcm + a*a*a*a<< " ";
      }
      else{
        cout << lcm << " ";
      }

    }
    cout << "\n";
  }
  
  return 0;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin>>t;
  while(t--) solve();
}
