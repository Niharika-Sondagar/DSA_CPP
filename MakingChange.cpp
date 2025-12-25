#include<iostream>
#include<vector>
using namespace std;
class MakingChange{
    vector<int>D;
    public:
      MakingChange(){}
      MakingChange(int n,vector<int>&arr){

       D.resize(n);
       D=arr;
       sort_array(n);
      }
      void sort_array(int n){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(D[j+1]>D[j]){
                    int temp=D[j];
                    D[j]=D[j+1];
                    D[j+1]=temp;
                }
            }
        }
      }
      int min_coin(int n,int p){
        int count=0;
        
        for(int i=0;i<n;i++){
            
            if(p>=D[i]){
                int ans=p/D[i];
                 p=p%D[i];
            count=count+ans;
            }
        }
        return count;
      }
};
int main(){
    int n;
    cout << "Enter no of objects:"<<endl;
    cin >> n;
    vector<int>arr(n);
     cout << "Enter objects:"<<endl;
     for (int i=0;i<n;i++) 
      cin >> arr[i];
    MakingChange a(n,arr);
    int p;
    cout << "Enter maximum amount:";
    cin >> p;
    int count=a.min_coin(n,p);
    cout << "Minimum coins are:"<<count;
    return 0;
}
