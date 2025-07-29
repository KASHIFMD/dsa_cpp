// #include<cmath.h>
#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 5;
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
    int n;
    cout <<"code started ..." << endl;
    cin >> n;
    cout << "n: " << n << endl;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        cout << "temp: " << temp << endl;
        update(i, temp);
    }
    int t = rangeSum(4, 7);
    cout << t << endl;

    return 0;
}
