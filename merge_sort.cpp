#include <iostream>
#include <vector>
using namespace std;
void Merge(vector<int>&arr,int low,int mid,int high){
    vector<int>temp(high-low+1);
    int left=low,right=mid+1,i=0;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp[i++]=arr[left++];
        }
        else{
            temp[i++]=arr[right++];
        }
    }
    while (left<=mid)
    {
         temp[i++]=arr[left++];
    }
    while(right<=high){
         temp[i++]=arr[right++];
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void Merge_sort(vector<int>&arr,int low,int high){
    if(low==high)
    return;
      int mid=(low+high)/2;
      Merge_sort(arr,low,mid);
      Merge_sort(arr,mid+1,high);
      Merge(arr,low,mid,high);
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

    Merge_sort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
