#include <iostream>
using namespace std;

void mergearray(int arr1[], int cnt1, int arr2[], int cnt2, int buf[])
{
    int idx1 = 0, idx2 = 0, idx = 0;
    while (idx1 < cnt1 && idx2 < cnt2) {
        if (arr1[idx1] <= arr2[idx2]) {
            buf[idx++] = arr1[idx1++];
        } else {
            buf[idx++] = arr2[idx2++];
        }
    }
    while (idx1 != cnt1) {
        buf[idx++] = arr1[idx1++];
    }
    while (idx2 != cnt1) {
        buf[idx++] = arr2[idx2++];
    }
}

void mergesort(int arr[], int begin, int end)
{
    if (end <= begin) {
        return;
    }

    int mid = (begin + end) / 2;
    mergesort(arr, begin, mid);
    mergesort(arr, mid+1, end);

    int* buf = new int[end-begin+1];
    mergearray(arr+begin, mid-begin+1, arr+mid+1, end-(mid+1)+1, buf);
    for (int i = 0; i < end-begin+1; i++) {
        arr[begin+i] = buf[i];
    }
    delete []buf;
}

int main()
{
    int arr[] = {6,2,-9,3,8,7,5};
    int cnt = sizeof(arr)/sizeof(int);
    mergesort(arr, 0, cnt-1);
    for (int i = 0; i < cnt; i++) {
        cout<<arr[i]<<" ";
    }
    return 1;
}

