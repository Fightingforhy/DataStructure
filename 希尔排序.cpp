#include<iostream>
using namespace std;
#define N 1000
typedef struct{
  int key;
}RecordType;
typedef struct{
   RecordType r[N+1];
   int length;
}Sequence;
void ShellInsert(Sequence &L,int delta){
   int i,j;
   for(i=1+delta;i<=L.length;i++){
      if(L.r[i].key<L.r[i-delta].key){
         L.r[0]=L.r[i];
         for(j=i-delta;j>0&&L.r[0].key<L.r[j].key;j-=delta){
            L.r[j+delta]=L.r[j];
         }
         L.r[j+delta]=L.r[0];
      }
   }
}
void ShellSort(Sequence &L,int dlta[],int t){
   int k;
   for(k=0;k<=t;++k){
      ShellInsert(L,dlta[k]);
   }
}
/*void printSequence(Sequence &L,int x){
   int i;
   for(i=1;i<x+1;i++){
      cout<<L.r[i].key<<" ";
   }
}*/
 int main(){
    Sequence L;
    int n;
    int dlta[]={5,3,1};
    cin>>n;
    L.length=n;
    for(int i=0;i<n;i++){
       cin>>L.r[i+1].key;
    }
    ShellSort(L,dlta,2);
    for(int i=1;i<L.length+1;i++){
      if(i==1)
      cout<<L.r[i].key;
      else
        cout<<" "<<L.r[i].key;
   }
    //printSequence(L,L.length);
    return 0;
 }
