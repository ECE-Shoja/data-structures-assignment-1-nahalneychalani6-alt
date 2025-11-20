#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

int findSet(int v) {
    while(v!=parent[v]){
        v=parent[v];
}
return v ;
}
void unionset(int p , int q){
        int rootP=parent[p] ;
        int rootQ=parent[q] ;
        if(rootP==rootQ) return ;
         if(sz[rootP]<sz[rootQ]){
             parent[rootP]=rootQ ;
             sz[rootQ]+=sz[rootP] ;
        }else if(sz[rootP]>sz[rootQ]){
             parent[rootQ]=rootP ;
             sz[rootP]+=sz[rootQ]
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    sz.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (q--) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == '+') {
            unionSet(a, b);
        } else if (type == '?') {
            if (findSet(a) == findSet(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
