#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
 
int main(){
    int i,N,x,weight;
    while(scanf("%d",&N) != EOF){
        weight = 0;
        priority_queue<int, vector<int>, greater<int> > MinHeap;
        for(i = 0;i < N;i++){
            scanf("%d",&x);
            MinHeap.push(x);
        }
        while(MinHeap.size() > 1){
            int a = MinHeap.top(); 
            MinHeap.pop();
            int b = MinHeap.top();
            MinHeap.pop();
            weight += a + b;
            MinHeap.push(a + b);
        }
        printf("%d\n",weight);
    }
    return 0;
}
