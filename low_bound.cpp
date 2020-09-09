#include<vector>
#include<iostream>

using namespace std;

int main()
{
    int a[10]={7,2,3,1,5,8,9,6,23,11};
    vector<int> f;
    for(int i=0;i<10;i++){
        auto it = lower_bound(f.begin(),f.end(),a[i]);
        if(it != f.end()){
            *it = a[i];
        } else
        {
            f.push_back(a[i]);
        }
    }
    for(auto i:f){
        cout<<i<<' ';
    }
    cout<<f.size()<<endl;
    getchar();
}