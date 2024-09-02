#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

const int SIZE = 51;
int n, k;

struct Mat {
	int m[SIZE][SIZE];
	Mat() {
		memset(m, 0, sizeof(m));
	}
	
	Mat operator* (Mat a) {
		Mat res;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					res.m[i][j] += m[i][k] * a.m[k][j];
					res.m[i][j] %= _MOD;
				}
			}
		}
		return res;
	}
};

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> k;

    Mat res;
	Mat T;
	// res.identity();
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> T.m[i][j], res.m[i][i] = 1;

	// log(n)
	while (k) {
		if (k & 1) res = res * T;
		T = T * T;
		k /= 2;
	}

	int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans = mod(ans + res.m[i][j]);
	
	cout << ans << endl;
    return 0;
}