#include<iostream>
using namespace std;
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void swap1(char *xp, char *yp) 
{ 
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}   
// A function to implement bubble sort 
void sort(int arr[], int n,char name[]) 
{ 
   int i, j; 
   bool swapped; 
   for (i = 0; i < n-1; i++) 
   { 
     swapped = false; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j] < arr[j+1]) 
        { 
    swap1(&name[j], &name[j+1]);     
           swap(&arr[j], &arr[j+1]); 
           swapped = true;
        } 
     } 
  
     // IF no two elements were swapped by inner loop, then break 
     if (swapped == false) 
        break; 
   } 
} 
int ranker(int r[],int a[], int n){
int s=1;
r[0]=s;
for(int i=1;i<n;i++){
if(a[i]<a[i-1]){
r[i]=++s;
}
else if(a[i]==a[i-1]){
r[i]=s;
}
}
return (s+1);
}
int main(){
int n;cin>>n;
char name[n+1]={0};
int a[n+1]={0};
int r[n+1]={0};
int i;
for(int i=0;i<n;i++){
cin>>a[i];
r[i]=0;
}
name[n]='a';
a[n]=0;
r[n]=0;
sort(a,n,name);
r[n]=ranker(r,a,n);

int p=n;
int x;
cin>>x;
for(int i=0;i<x;i++){
int k;
cin>>k;
if(i==0){
for(int i=0;i<n+1;i++){
if(name[i]=='a')
{
//cout<<"name found in "<<i;
p=i;break;}
}
}
//cout<<a[p]<<"="<<k;
a[p]=k;
sort(a,n+1,name);
ranker(r,a,n+1);
for(int i=0;i<n+1;i++){
if(name[i]=='a'){
cout<<r[i]<<endl;
p=i;
}//<<endl<<"score"<<a[i];
//cout<<"i am alice";
//cout<<"rank "<<r[i]<<"score="<<a[i]<<endl;

}

}
return 0;
}
