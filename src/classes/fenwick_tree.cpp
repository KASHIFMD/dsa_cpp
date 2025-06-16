// #include<cmath.h>
#include<bits/stdc++.h>

const int N = 100000+5;
int fen[N];
void update(int i, int add){
    while(i<N){
        fen[i] += add;
        i = ((-i) & i) + i;
    }
}

int sum(int i){
    int s = 0;
    while(i>0){
        s += fen[i];
        i = i - ((-i) & i);
    }
    return s;
}

int rangeSum(int l, int r){
    return sum(r) - sum(l-1);
}

int find(int k){
    int curr = 0, prevsum = 0;
    for (int i = log2(N);i>=0; i--)
    {
        if(fen[curr + 1<<i]+prevsum < k){
            curr = curr + (1 << i);
            prevsum += fen[curr];
        }
    }
    return curr+1;
}

int main(){
    
    return 0;
}