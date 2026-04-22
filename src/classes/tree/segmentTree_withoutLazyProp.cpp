#include <bits/stdc++.h>
using namespace std;

class SegTree{
public:
    int n;
    vector<int> t;
    SegTree() {}
    SegTree(int n){
        this->n = n;
        t.assign(4*n, 0);
    }
    void buildTree(vector<int> &a, int v, int tl, int tr){
        if(tl == tr){
            t[v] = a[tl];
            return;
        }
        int tm = (tl+tr) / 2;
        buildTree(a, 2*v, tl, tm);
        buildTree(a, 2*v+1, tm+1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    void build(vector<int> &a){
        buildTree(a, 1, 0, n-1);
    }

    int queryTree(int v, int l, int r, int tl, int tr){
        if(r<tl or tr<l)
            return 0;
        if(l<=tl and tr<=r)
            return t[v];

        int tm = (tl+tr) / 2;
        int left = queryTree(2*v, l, r, tl, tm);
        int right = queryTree(2*v+1, l, r, tm+1, tr);
        return left + right;
    }
    int query(int l, int r){
        return queryTree(1, l, r, 0, n-1);
    }

    void updateTree(int v, int id, int val, int tl, int tr){
        if(tl==id and tr==id){
            t[v] = val;
            return;
        }
        if(id<tl or tr<id)
            return;

        int tm = (tl+tr)/2;
        updateTree(2*v, id, val, tl, tm);
        updateTree(2*v+1, id, val, tm+1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    void update(int id, int val){
        updateTree(1, id, val, 0, n-1);
    }
};

int main(){
    vector<int> a = {2, 3, 4, 1, 3, 6, 4, 3, 2};
    int n = a.size();

    SegTree tree(n);
    tree.build(a);
    cout << "before ans:" << endl;
    cout << tree.query(2, 5) << endl;
    
    tree.update(5, 24);
    cout << "after ans:" << endl;
    cout << tree.query(2, 5) << endl;
    return 0;
}
