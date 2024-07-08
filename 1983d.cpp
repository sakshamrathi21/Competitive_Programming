/**
 *    Author: Saksham Rathi
 *    Created: Mon Jul  8 16:16:43 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
          int right);
int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

// An auxiliary recursive function
// that sorts the input array and
// returns the number of inversions in the array.
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        // Divide the array into two parts and
        // call _mergeSortAndCountInv()
        // for each of the parts
        mid = (right + left) / 2;

        // Inversion count will be sum of
        // inversions in left-part, right-part
        // and number of inversions in merging
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        // Merge the two parts
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

// This function merges two sorted arrays
// and returns inversion count in the arrays.
int merge(int arr[], int temp[], int left, int mid,
          int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            // this is tricky -- see above
            // explanation/diagram for merge()
            inv_count = inv_count + (mid - i);
        }
    }

    // Copy the remaining elements of left subarray
    // (if there are any) to temp
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    // Copy the remaining elements of right subarray
    // (if there are any) to temp
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back the merged elements to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        for (int i = 0 ; i < n ; i ++) {
            cin >> b[i];
        }
        int x = mergeSort(a, n), y = mergeSort(b, n);
        bool eq = true;
        sort(a, a+n);
        sort(b, b+n);
        for (int i = 0 ; i < n ; i ++) {
            if (a[i] != b[i]) {
                eq = false;
                break;
            }
        }
        if (!eq) {
            cout << "NO\n";
            continue;
        }
        // cout << x << " " << y << "\n";
        if (x%2 == y%2) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}
