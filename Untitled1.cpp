#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cout<<"enter n";
    cin>>n;
    cout<<endl<<"enter m";
    cin>>m;
    int a[m]={0};
    for(int i=0;i<m;i++){
        cout<<endl<<"enter n";
        cin>>a[i];
    }
    cout<<endl;
    int c[n+2]={0};
    for(int i=0;i<m-1;i++){
        int x=a[i];
        int y=a[i+1];
        if(x>y){
            c[x]++;
            c[1]++;
            c[y+1]--;
        }
        else{
            c[x]++;
            c[y+1]--;
        }
        cout<<endl<<"done"<<endl;
    }
    for(int i=0;i<n+2;i++){
        c[i]+=c[i-1];
        cout<<c[i]<<" ";
    }
    return 0;
}

