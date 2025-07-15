#include<bits/stdc++.h>
using namespace std;
class NumArray {
    int n;
    vector<int> tree;
    int merge(int a, int b){
        return a+b;
    }
    void build(int start, int end, int node, vector<int> &nums){
        if(start == end){
            tree[node] = nums[start];
            return; 
        }
        int mid = start + (end-start)/2;
        build(start, mid, 2*node, nums);
        build(mid+1, end, 2*node+1, nums);
        tree[node] = merge(tree[2*node], tree[2*node+1]);

    }
    void update_tree(int start, int end, int index, int node, int val){
        if(start == end and start == index){
            tree[node] = val;
            return;
        }
        int mid = start + (end-start)/2;
        if(index<=mid)
            update_tree(start, mid, index, 2*node, val);
        else
            update_tree(mid+1, end, index, 2*node+1, val);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }
    int sum(int left, int right, int start, int end, int node){
        if(left>right)
            return 0;
        if(left == start and right == end)
            return tree[node];
        int mid = start + (end-start)/2;
        int a = 0, b = 0;
        a = sum(left, min(mid, right), start, mid, 2*node);
        b = sum(max(left, mid+1), right, mid+1, end, 2*node+1);
        return a+b;
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.assign(n*4+1, 0);
        build(0, n-1, 1, nums);
    }
    
    void update(int index, int val) {
        update_tree(0, n-1, index, 1, val);
    }
    
    int sumRange(int left, int right) {
        if(left>right)
            return 0;
        return sum(left, right, 0, n-1, 1);
    }
    
    ~NumArray(){

    }
};


int main(){
    int n = 5;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = i+1;
    }
    NumArray tree(nums);
    // tree.build(0, 0, 4);
    int L = 0, R = 2;
    int ans = tree.sumRange(L, R);
    cout << ans << endl;
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
