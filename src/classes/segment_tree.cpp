#include<bits/stdc++.h>
using namespace std;

class SEGMENT_TREE{
    public:
    int a[100005], seg[4 * 100005];
    SEGMENT_TREE(){
        fill(a, a+100005, 0);
        fill(seg, seg+100005, 0);
    }

    void build(int ind, int low, int high){
        if(low==high){
            seg[ind] = a[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid+1, high);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
        // max, min, sum;
    }

    int query(int ind, int low, int high, int l, int r){
        if(low>=l and high<=r){
            return seg[ind];
        }
        if(high < l or low > r){
            return INT_MIN;
        }
        int mid = (low+high) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return max(left, right);
    }

    ~SEGMENT_TREE(){

    }
};

int main(){
    SEGMENT_TREE tree;
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        tree.a[i] = i+1;
    }
    tree.build(0, 0, 4);
    int L = 0, R = 2;
    int ans = tree.query(0, 0, n-1, L, R);
    cout << ans << endl;
}


