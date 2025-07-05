#include<bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> parent, rank, size;

public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for (int i = 0; i <= n;i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void UnionByRank(int a, int b){
        int upa = findParent(a);
        int upb = findParent(b);
        if(upa == upb) return;

        if(rank[upa] > rank[upb])
            parent[upb] = upa;
        else if(rank[upa] < rank[upb])
            parent[upa] = upb;
        else{
            parent[upa] = upb;
            rank[upb]++;
        }
    }

    void UnionBySize(int a, int b){
        int upa = findParent(a);
        int upb = findParent(b);
        if(upa == upb) return;
        if(size[upa] > size[upb]){
            parent[upb] = upa;
            size[upa] += size[upb];
        }
        else{
            parent[upa] = upb;
            size[upb] += size[upa];
        }
    }
};

// int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     DisjointSet ds(7);
//     ds.UnionByRank(1, 2);
//     ds.UnionByRank(2, 3);
//     ds.UnionByRank(4, 5);
//     ds.UnionByRank(6, 7);
//     ds.UnionByRank(5, 6);

//     ds.findParent(3) == ds.findParent(7) ? cout << "same\n" : cout << "not same\n";

//     ds.UnionByRank(3, 7);
//     ds.findParent(3) == ds.findParent(7) ? cout << "same\n" : cout << "not same\n";

//     return 0;
// }
