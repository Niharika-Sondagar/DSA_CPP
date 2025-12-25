#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Knapsack {
    int n;
    vector<int> v, w;
    vector<double> ratio;

public:
    Knapsack() {}

    Knapsack(int n) {
        this->n = n;

        v.resize(n);
        w.resize(n);
        ratio.resize(n);

        cout << "Enter value of objects:"<<endl;
        for (int i = 0; i < n; i++) 
        cin >> v[i];

        cout << "Enter weight of objects:"<<endl;
        for (int i = 0; i < n; i++) 
        cin >> w[i];

        for (int i = 0; i < n; i++)
            ratio[i] = (double)v[i] / w[i];

        sort_ratio();
    }

    
     void sort_ratio(){
        for(int i=0;i<n-1;i++){
          for(int j=0;j<n-i-1;j++){
             if(ratio[j]<ratio[j+1]){
                swap(ratio[j],ratio[j+1]);
                swap(v[j],v[j+1]);
                swap(w[j],w[j+1]);
             }
          }
        }
     }
     
     double Knapsack_profit(int mw){
        int i=0;
        double weight=0;
        double x[n]={0},profit=0;
        while(i<n && weight<mw){
         if((weight+w[i])<=mw){
            x[i]=1;
         }
         else{
            x[i]=(mw-weight)/(double)w[i];
         }
         weight=weight+x[i]*w[i];
         profit += x[i]*v[i];
         i++;
        }
        return profit;
     }
};
int main(){
    int n;
    cout << "Enter no of objects:"<<endl;
    cin >> n;
    Knapsack k(n);
    int weight;
    cout << "Enter maximum weight:"<<endl;
    cin>>weight;
    int profit=k.Knapsack_profit(weight);
    cout<<"Maximum profit is:" << profit <<endl;
    return 0;
}
