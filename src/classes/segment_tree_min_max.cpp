#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> node_type;

class NumArray
{
    int n;
    vector<node_type> tree;
    node_type merge(node_type a, node_type b){
        return {min(a.first, b.first), max(a.second, b.second)};
    }
    void build(int start, int end, int node, vector<int> &nums){
        if(start == end){
            tree[node] = {nums[start], nums[start]};
            return; 
        }
        int mid = start + (end-start)/2;
        build(start, mid, 2*node, nums);
        build(mid+1, end, 2*node+1, nums);
        tree[node] = merge(tree[2*node], tree[2*node+1]);

    }
    void update_tree(int start, int end, int index, int node, int val){
        if(start == end and start == index){
            tree[node] = {val, val};
            return;
        }
        int mid = start + (end-start)/2;
        if(index<=mid)
            update_tree(start, mid, index, 2*node, val);
        else
            update_tree(mid+1, end, index, 2*node+1, val);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }
    node_type sum(int left, int right, int start, int end, int node){
        if(left>right)
            return {INT_MAX, INT_MIN};
        if(left == start and right == end)
            return tree[node];
        int mid = start + (end-start)/2;
        node_type a, b;
        a = sum(left, min(mid, right), start, mid, 2*node);
        b = sum(max(left, mid+1), right, mid+1, end, 2*node+1);
        return {min(a.first, b.first), max(a.second, b.second)};
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.assign(n*4+1, {INT_MAX, INT_MIN});
        build(0, n-1, 1, nums);
    }
    
    void update(int index, int val) {
        update_tree(0, n-1, index, 1, val);
    }
    
    node_type sumRange(int left, int right) {
        if(left>right)
            return {INT_MAX, INT_MIN};
        return sum(left, right, 0, n-1, 1);
    }
    
    ~NumArray(){

    }
};

int main(){
    int n = 10;
    vector<int> nums(n);
    random_device rd;
    mt19937 gen(rd());
    int lower = 10, upper = 80;
    uniform_int_distribution<int> dist(lower, upper);
    for (int i = 0; i < n; i++){
        nums[i] = dist(gen);
        cout << "{"<<i<<"}:"<<nums[i] << ", ";
    }
    // for (int i = 0; i < n; i++)
    // {
    //     nums[i] = i+1;
    //     cout << i + 1 << ", ";
    // }
    NumArray tree(nums);
    // tree.build(0, 0, 4);
    int L = 2, R = 8;
    node_type ans = tree.sumRange(L, R);
    cout << "MIN: "<<ans.first<< ", MAX: "<< ans.second << endl;
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
