#include<iostream>
using namespace std;
void selection_sort(int arr[],int n){
     int i,j,mp,min_pos,temp;
     for(i=0;i<n-1;i++){
        min_pos=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min_pos])
              min_pos=j;
        }
            if(min_pos!=i)
            {
                temp=arr[i];
                arr[i]=arr[min_pos];
                arr[min_pos]=temp;
            }
        
        cout << "After Pass " << i+1 << ": ";
        for(int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
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
    selection_sort(arr,n);
    return 0;
}