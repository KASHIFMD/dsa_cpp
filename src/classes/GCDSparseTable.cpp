#include<bits/stdc++.h>
using namespace std;

class GCDSparseTable{
private:
    vector<vector<int>> st;
    vector<int> logVal;
    int n;

public:
    GCDSparseTable(const vector<int>&a){
        n = a.size();
        assert(n>0);
        int maxLog = 32 - __builtin_clz(n); // (what's the position of most highest index after which all are '0')
        // int maxLog = floor(log2(n)+1); // this line same as above
        st.assign(n, vector<int>(maxLog));
        logVal.resize(n+1); 
        for (int i = 2; i <= n; i++) // n+1 is must
        {
            logVal[i] = logVal[i / 2] + 1;
        }
        for (int i = 0; i < n;i++)
        {
            st[i][0] = a[i];
        }

        for (int j = 1; (1<<j) <=n;j++)
        {
            for (int i = 0; i+(1<<j) <= n; i++)
            {
                st[i][j] = __gcd(st[i][j-1], st[i + (1<<(j-1))][j-1]);
            }
        }
    }

    int getGCD(int l, int r){
        assert(0 <= l && l <= r && r < n);
        int t = logVal[r-l+1];
        int x = st[l][t];
        int y = st[r-(1<<t)+1][t];
        return __gcd(x, y);
    }
};
