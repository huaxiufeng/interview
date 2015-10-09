#include <iostream>
using namespace std;

// return the index of the element
// or -1 if not found
int bsearch(const int arr[], int cnt, int val)
{
    int low = 0, high = cnt - 1;
    while (low <= high) {
        int mid = (high-low)/2 + low;
        if (arr[mid] == val) {
            return mid;
        } else if (arr[mid] < val) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int cnt = sizeof(arr)/sizeof(int);
    int val = 6;
    cout<<bsearch(arr, cnt, val)<<endl;
    return 1;
}

