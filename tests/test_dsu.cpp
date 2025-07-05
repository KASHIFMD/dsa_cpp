// test/test_dsu.cpp
#include <bits/stdc++.h>
// #include<dsu.hpp>
#include "../src/classes/dsu.cpp"
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    DisjointSet ds(7);            // nodes [0‥7]

    // Build two separate components: {1,2,3} and {4,5,6,7}
    // ds.UnionByRank(1, 2);
    // ds.UnionByRank(2, 3);
    // ds.UnionByRank(4, 5);
    // ds.UnionByRank(6, 7);
    // ds.UnionByRank(5, 6);
    ds.UnionBySize(1, 2);
    ds.UnionBySize(2, 3);
    ds.UnionBySize(4, 5);
    ds.UnionBySize(6, 7);
    ds.UnionBySize(5, 6);

    // 1️⃣  Components are still different
    if (ds.findParent(3) == ds.findParent(7))
        cout << "same\n";           // should print “not same”
    else
        cout << "not same\n";

    // Merge the two components
    // ds.UnionByRank(3, 7);
    ds.UnionBySize(3, 7);

    // 2️⃣  Now they are in the same set
    if (ds.findParent(3) == ds.findParent(7))
        cout << "same\n";           // should print “same”
    else
        cout << "not same\n";

    return 0;
}
