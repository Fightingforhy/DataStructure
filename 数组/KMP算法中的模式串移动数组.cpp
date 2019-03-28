#include<iostream>
#include<cstring>
using namespace std;
void getNext(string ps){
   string strkey=ps;
   int next[20];
   int j=0;
   int count=0;
   int k=-1;
   next[0]=-1;
   while(j<strkey.length()-1){
      if(k==-1||strkey[j]==strkey[k]){
         next[++j]=++k;
         count++;
      }
      else{
         k=next[k];
      }
   }
   for(int x=0;x<count+1;x++){
      cout<<next[x]+1<<" ";
   }
}
int main(){
  string ps;
  cin>>ps;
  getNext(ps);
 
}
