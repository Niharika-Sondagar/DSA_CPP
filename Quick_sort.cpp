#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high) {
    int i = low, j = high;
    int key = arr[low];  // pivot

    while (i < j) {
        while (arr[i] <= key && i <= high - 1) {
            i++;
        }
        while (arr[j] > key && j >= low + 1) {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);  // place pivot in correct position
    return j;
}

void Quick_sort(vector<int> &arr, int low, int high) {
    if (low < high) {   // base case
        int part = partition(arr, low, high);
        Quick_sort(arr, low, part - 1);
        Quick_sort(arr, part + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of values in array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Quick_sort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
