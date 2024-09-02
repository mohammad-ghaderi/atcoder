#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE


struct segmenttree {
    int n;
    vector<int> st;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);
    }

    // void build(int start, int ending, int node, vector<int> &v) {
    //     // leaf node base case
    //     if (start == ending) {
    //         st[node] = v[start];
    //         return;
    //     }

    //     int mid = (start + ending) / 2;

    //     // left subtree is (start,mid)
    //     build(start, mid, 2 * node + 1, v);

    //     // right subtree is (mid+1,ending)
    //     build(mid + 1, ending, 2 * node + 2, v);

    //     st[node] = st[node * 2 + 1], st[node * 2 + 2];
    // }

    int query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        if (start > r || ending < l) {
            return 0;
        }

        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return max(q1, q2);
    }

    void update(int start, int ending, int node, int index, int value) {
        // base case
        if (start == ending) {
            st[node] = value;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid) {
            // left subtree
            update(start, mid, 2 * node + 1, index, value);
        }
        else {
            // right
            update(mid + 1, ending, 2 * node + 2, index, value);
        }

        st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);

        return;
    }

    // void build(vector<int> &v) {
    //     build(0, n - 1, 0, v);
    // }

    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }

    void update(int x, int y) {
        update(0, n - 1, 0, x, y);
    }
};




int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int h[n], a[n];
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    segmenttree tree;
    tree.init(n);

    for (int i = 0; i < n; i++) {
        int p = tree.query(0, h[i]-1) + a[i];
        tree.update(h[i], p);
    }

    cout << tree.query(0, n) << endl;

    return 0;
}