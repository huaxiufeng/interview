#include <iostream>
using namespace std;

void permutation(char* str, char* beg)
{
    if (*beg == 0) {
        cout<<str<<endl;
        return;
    }
    
    for (char* p = beg; *p != 0; p++) {
        swap(*beg, *p);
        permutation(str, beg+1);
        swap(*beg, *p);
    }
}

void permutation(char* str)
{
    if (!str) {
        return;
    }

    permutation(str, str);
}

int main()
{
    char str[] = "12345";
    permutation(str);
    return 1;
}

