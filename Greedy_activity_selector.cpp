#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout << "Enter no. of activities" <<endl;
    cin >>n;
    cout << "Enter activities according start and finish time respectivly:" <<endl;
    vector<int>s(n),f(n);

    for(int i=0;i<n;i++){
      cin >> s[i] >> f[i];
    }
   cout << "Non Overlaping Activities are performed:";
   cout << "("<<s[0] <<"," << f[0]<< ")" << endl;
    int j=0;
    for(int i=0;i<n;i++){
        if(s[i]>f[j]){
           cout << "("<<s[i] <<"," << f[i]<< ")" << endl;
           j=i;
        }
        else{
            continue;
        }
    }

    return 0;
}