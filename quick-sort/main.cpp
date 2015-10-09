#include <iostream>
using namespace std;


void quicksort(int arr[], int left, int right)
{
    if (left >= right) {
        return;
    }

    int i = left, j = right;
    int pivot = arr[i];
    while (i < j) {
        while (i < j && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            arr[i++] = arr[j];
        }
        while (i < j && arr[i] < pivot) {
            i++;
        }
        if (i < j) {
            arr[j--] = arr[i];
        }
    }
    arr[i] = pivot;

    quicksort(arr, left, i-1);
    quicksort(arr, i+1, right);
}

int main()
{
    int arr[] = {0,10,8,2,9,3,7,6};
    int cnt = sizeof(arr)/sizeof(int);
    quicksort(arr, 0, cnt-1);
    for (int i = 1; i < cnt; i++) {
        cout<<arr[i]<<" ";
    }
    return 1;
}

