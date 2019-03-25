#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int main()
{
    char str1[201];
    char str2[201];
    while(cin.getline(str1, 201)){
        int i,j=0;
        for(i=0;str1[i]!='\0';i++)
        {
            if(str1[i]=='#')
            {
                j--;
            }
            else if(str1[i]=='@')
            {
                j=0;
            }
            else
            {
                str2[j]=str1[i];
                j++;
            }
        }
        str2[j]='\0';
        cout<<str2<<endl;
    }
    return 0;
}
