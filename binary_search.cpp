#include<iostream>
using namespace std;
void sort_arr(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
           int temp=arr[j];
           arr[j]=arr[j+1];
           arr[j+1]=temp;
        }
    }
}
int binary_search(int arr[],int n,int val ){
   int start=0,end=n-1,middle=0;
   while(start<=end){
      middle=(start+end)/2;
      if(arr[middle]<val)
        start=middle+1;
      else if(arr[middle]>val)
       end=middle-1;
      else
       return (middle);
   }
   return 0;
}
int main(){
    int n,val;
    cout << "Enter number of values in array:";
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
       cin >> arr[i];
    }
    cout << "\nEnter value to be search:";
    cin >> val;
    sort_arr(arr,n);
    int flag=binary_search(arr,n,val);
    if(flag)
     cout << "\nvalue is found.";
    else 
     cout << "value is not found.";
    return 0;
}