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

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sizeof(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

struct LCA {
    int T = 0;
    vi time, path, ret;
    RMQ<int> rmq;

    LCA(vector<vi>& C) : time(sizeof(C)), rmq((dfs(C,0,-1), ret)) {}
    void dfs(vector<vi>& C, int v, int par) {
        time[v] = T++;
        for (int y : C[v]) if (y != par) {
            path.push_back(v), ret.push_back(time[v]);
            dfs(C, y, v);
        }
    }

    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
    //dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

void solve() {
    int n;
    cin >> n;
    vi v;
    scan(n,v);
    vi pref(n+1,0);
    // fr(i,0,n) {
    //     st.update(i,v[i]);
    // }
    int q;
    cin >> q;
    while(q--) {
        int l,r;
        cin >> l >> r;
        l++;
        r--;
        // cout << st.query(l,r) << endl;
        cout << pref[r+1] - pref[l] << endl;
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