
#include <iostream>

#include <vector>
#include <queue> 
#include <stack>
using namespace std;

vector<int> G[55];
int Degree[55];
int GE[55][55];
queue<int> node;
int n; 

void Input(int N)
{
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>> GE[i][j];
		}	
	}
	for(int i=0;i<N;i++)
		{
			int count=0,j;
			for(int j=0;j<N;j++)
			{
				if(GE[i][j]==1)
					G[i].push_back(j);
				if(GE[j][i]==1)
					count++;
			}
			Degree[i]=count;//存储每个顶点的入度
		}	
}

bool TopologicalSort()
{
	int num=0;
	stack<int> p;
	for(int i=0;i<n;i++)
	{
		if(Degree[i]==0)
		{
	    	p.push(i);
		    Degree[i]=-1;
		}
	}	
	while(!p.empty())
	{
		int u=p.top();
		node.push(u);
		p.pop();
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			Degree[v]--;
			if(Degree[v]==0)
			{
				p.push(v);
				Degree[v]=-1;
			}
		}
		G[u].clear();
		num++;
	}
	if(num==n) return true;
	else return false;
} 

int main()
{
	cin>>n;
	Input(n);
	bool flag=TopologicalSort();
	if(flag) 
	{
		int len=node.size();
		for(int s=0;s<len;s++)
		{
			cout<<node.front()<<" ";
			node.pop();
	    } 
		cout<<endl;
	}
	else cout<<"ERROR"<<endl;
	return 0;
}
