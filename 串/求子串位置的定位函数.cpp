#include<stdio.h>
#include<string.h>
#define M 100
typedef struct{
    char ch[M];
    int len;
}SString;
int StrIndex(SString s,int pos,SString t){
   int i,j,start;
   if(t.len==0) return 0;
   start=pos;
   i=start;
   j=0;
   while(i<s.len&&j<t.len){
      if(s.ch[i]==t.ch[j]){
         printf("%c",s.ch[i]);
         i++;
         j++;
      }
      else{
         printf("%c",s.ch[i]);
         start++;
         i=start;
         j=0;
      }
   }
   if(j>=t.len) return start+1;
   else return 0;
}
int main(){
   SString s,t;
   while(scanf("%s",s.ch)!=EOF){
      scanf("%s",t.ch);
      s.len=strlen(s.ch);
      t.len=strlen(t.ch);
      printf("\n%d\n",StrIndex(s,0,t));
   }
   return 0;
}
