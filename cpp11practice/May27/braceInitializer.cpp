#include <iostream>

using namespace std;

int main()
{
    string var{"test"};
    string &lr{var};

    cout << var << "\n";
    cout << lr << "\n";

    string var1{"Cambridge"};
    string f();

    string &r1{var1};
    // string &r2{f()};         //f is a rvalue thus cannot be brace initialized
    //  const string &r3{"Princeton"};   ///similarly a rvalue cannot be used
    // string &r3 = "Princeton";
}