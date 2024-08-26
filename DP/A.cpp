#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

const int inf = 1e9;

void solve() {
	int n;
	cin >> n;
	int h[n];
	int dp[n + 5]{};
	
	for (int i = 0; i < n; i++) cin >> h[i];

	for (int i = 1; i <= n; i++) dp[i] = inf;
	    
	for (int i = 0; i < n; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i])); 
		dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
	}	
	
	cout << dp[n - 1] << endl;
}


int main() {
	fastio
	solve();
	return 0;
}
