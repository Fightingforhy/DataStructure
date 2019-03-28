#include<iostream>
using namespace std;
void BinSrch(int r[],int length){
   int temp;
   for(int i=0;i<length-1;i++){
    for(int j=i+1;j<length;j++){
        if(r[j]<r[i]){
           temp=r[j];
           r[j]=r[i];
           r[i]=temp;
        }
    }
   }
   for(int a=0;a<length;a++){
    cout<<r[a]<<" ";
   }
}
int main(){
   int n;
   int i,j;
   cin>>n;
   int record[n];
   for(i=0;i<n;i++){
     cin>>record[i];
   }
   BinSrch(record,n);
   return 0;
}
