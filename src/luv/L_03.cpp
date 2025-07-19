#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    int a = 100000;
    int b = 100000;
    long long int c = (LL)a * (LL)b;
    cout << c << endl;

    
    c = a * b * 1LL;
    cout << c << endl;
    c = a *1LL* b ;
    cout << c*100 << endl;
    double d = 1e24;
    cout << d << endl;
    cout<< fixed << d << endl;
    return 0;
}
/*
double
float
long long int/long long
long int
-10^9 < int < 10^9
-10^12 < long int < 10^12
-10^18 < long long int < 10^18
char
*/
