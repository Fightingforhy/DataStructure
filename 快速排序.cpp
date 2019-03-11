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
int Partition(Sequence &L,int i,int j){
    int pkey;
    L.r[0]=L.r[i];
    pkey=L.r[i].key;
    while(i<j){
       while(i<j&&L.r[j].key>=pkey)
       --j;
       L.r[i]=L.r[j];
       while(i<j&&L.r[i].key<=pkey)
       ++i;
       L.r[j]=L.r[i];
    }
    L.r[i]=L.r[0];
    return i;
}
void Quick(Sequence &L,int i,int j){
   int pkl;
   if(i<j){
      pkl=Partition(L,i,j);
      Quick(L,i,pkl-1);
      Quick(L,pkl+1,j);
   }
}
void QuickSort(Sequence &L){
   Quick(L,1,L.length);
}

/*void printfSequence(Sequence &L,int tq){
   int i;
   for(i=1;i<=tq;i++){
      if(i==1)
      cout<<L.r[i].key;
      else
      cout<<" "<<L.r[i].key;
   }
}
*/
int main(){
   Sequence L;
   int n;
   cin>>n;
   L.length=n;
   for(int i=1;i<=n;i++){
      cin>>L.r[i].key;
   }
   QuickSort(L);
   //printfSequence(L,L.length);
   for(int i=1;i<=L.length;i++){
      if(i==1)
      cout<<L.r[i].key;
      else
      cout<<" "<<L.r[i].key;
   }
   return 0;
}
