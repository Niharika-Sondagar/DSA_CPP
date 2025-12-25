#include<iostream>
using namespace std;
void insertion_sort(int a[],int n){
     int i,j,key,k;
     for(i=1;i<n;i++){
        key=a[i];
        j=i-1;
          while(j>=0 && a[j]>key)
         { 
             a[j+1]=a[j];
           j--;
         }
         a[j+1]=key;
         cout<<"After pass"<<i<<":";
         for(k=0;k<n;k++)
          cout<<a[k]<<"\t";
          cout<<endl;
        }

}
int main(){
    int n,val;
    cout << "Enter number of values in array:";
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
       cin >> arr[i];
    }
    insertion_sort(arr,n);
    return 0;
}