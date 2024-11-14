#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifndef ONLINE_JUDGE
#else
#define debug(...)
#define debugArr(...)
#endif

#ifndef ONLINE_JUDGE
clock_t tStart = clock();
#endif
void runtime(){
    #ifndef ONLINE_JUDGE
        fprintf(stderr, ">> Runtime: %.10fs \n ", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int long long
#define fast() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define scan(n, a) for (int i = 0; i < n; i++) { int x11; cin >> x11; a.push_back(x11); }
#define fr(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define vi vector<int>
#define vvi vector<vi>
typedef pair<int, int> pi;
typedef vector<pi> vpi;
#define endl "\n"
#define pb push_back
#define prDouble(x) cout << fixed <<setprecision(10) << x
#define setio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
int M = 1e9+7;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

vi divisors(int n) {
    vi v;
    for(int i=1; i<=sqrt(n); i++) {
        if (n%i == 0) {
            if (n/i == i) v.pb(i);
            else {
                v.pb(i);
                v.pb(n/i);
            }
        }
    }
    return v;
}

void printcase(int k) {
    cout << "Case #" << k << ": ";
}

struct segtree {
    typedef int T;
    // for max segtree, set unit = INT_MIN and f(a,b) = max(a,b)
    static constexpr T unit = 0; // identity for sum
    T f(T a, T b) { return a + b; } // (any associative fn)
    vector<T> s; int n;
    segtree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    int n;
    cin >> n;
    vi v;
    scan(n,v);
    segtree st(n);
    fr(i,0,n) {
        st.update(i,v[i]);
    }
    int q;
    cin >> q;
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << st.query(l,r+1) << endl;
    }
}

signed main() {
    fast();
    int t = 1;
    cin >> t;
    int iter = 1;
    while (t--) {
        // printcase(iter);
        iter++;
        solve();
    }
    // runtime();
    return 0;
}