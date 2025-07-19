#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    string s = "hello";
    string b = "why";
    cout << s + b << endl;
    cout << s.size() << endl;
    string str1, str2;
    cin >> str1 >> str2;
    cout << "str1: "<<str1 << endl;
    cout << "str2: "<<str2 << endl;
    cout << str1.size()<<" " << str2.size() << endl;
    cin >> str1 >> str2;
    cout << "str1: "<<str1 << endl;
    cout << "str2: "<<str2 << endl;
    cout << str1.size()<<" " << str2.size() << endl;
    cin.ignore();
    // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline
    getline(cin, str1);
    cout << str1 << endl;
    cout << str1.size() << endl;
    return 0;
}
/*

*/
