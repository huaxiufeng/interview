#include <iostream>
using namespace std;

void heapadjust(int arr[], int root, int leaf)
{
    int val = arr[root];
    for (int j = root*2; j <= leaf; j++) {
        if (j < leaf && arr[j] < arr[j+1]) {
            j++;
        }
        if (val > arr[j]) {
            break;
        }
        arr[root] = arr[j];
        root = j;
    }
    arr[root] = val;
}

void heapsort(int arr[], int cnt)
{
    for (int i = cnt/2; i >= 1; i--) {
        heapadjust(arr, i, cnt-1);
    }
    for (int i = cnt-1; i > 1; i--) {
        swap(arr[1], arr[i]);
        heapadjust(arr, 1, i-1);
    }
}

int main()
{
    int arr[] = {0,10,8,2,9,3,7,6};
    int cnt = sizeof(arr)/sizeof(int);
    heapsort(arr, cnt);
    for (int i = 1; i < cnt; i++) {
        cout<<arr[i]<<" ";
    }
    return 1;
}

