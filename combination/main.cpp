#include <iostream>
#include <string>
using namespace std;

void combination(char* str, int n, string& s)
{
    if (n == 0) {
        cout<<s<<endl;
        return;
    }
    if (!*str) {
        return;
    }
    
    s += str[0];
    combination(str+1, n-1, s);
    s = s.substr(0, s.length()-1);

    combination(str+1, n, s);
}

void combination(char* str, int n)
{
    if (!str) {
        return;
    }

    string s;
    for (int i = 1; i <= n; i++) {
        combination(str, i, s);
    }
}

int main()
{
    combination("12345", 3);
    return 1;
}

