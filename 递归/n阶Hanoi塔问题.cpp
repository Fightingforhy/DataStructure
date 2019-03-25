#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
 
int i=1;
 
void move(int n,char from,char to){
    printf("%2d. Move disk %d from %c to %c\n",i++,n,from,to);
}
 
void hanoi(int n,char from,char dep,char to){
    if(n==1){
        move(1,from,to);
    }
    else{
        hanoi(n-1,from,to,dep);
        move(n,from,to);
        hanoi(n-1,dep,from,to);
    }
}
 
int main(){
    int num;
    while(scanf("%d",&num)!=EOF){
        char a='X',b='Y',c='Z';
        hanoi(num,a,b,c);
        printf("\n");
        i=1;
    }
    return 0;
}
