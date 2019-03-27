#include <iostream>
#include <algorithm>
#include <string>
#define MAX 100005
using namespace std;

int arr[105], n;
struct HeFuMan
{
    int weight;
    int parent, lch, rch;
    string code;
};

void HuffmanCode();

HeFuMan *HuffTree;
string *HfCode;
string Hashtable[MAX];
void selectMinTwo(int high, int &s1, int &s2)
{
    int min = 255;
    for (int i = 1; i <= high; i++)
    {
        if (HuffTree[i].parent == 0 && min > HuffTree[i].weight)
        {
            min = HuffTree[i].weight;
            s1 = i;
        }
    }
    min = 255;
    for (int i = 1; i <= high; i++)
    {
        if (HuffTree[i].parent == 0 && min > HuffTree[i].weight && i != s1)
        {
            min = HuffTree[i].weight;
            s2 = i;
        }
    }
    if (s1 > s2)
    {
        swap(s1, s2);
    }
}
void HuffmanCode()
{
    int m, i;
    if (n <= 1)
        return;
    m = 2 * n - 1;
    HuffTree = new HeFuMan[m + 1];
    for (i = 1; i <= n; i++)
    {
        HuffTree[i].weight = arr[i];
        HuffTree[i].lch = HuffTree[i].rch = HuffTree[i].parent = 0;
    }
    for (i = n + 1; i <= m; ++i)
    {
        HuffTree[i].lch = HuffTree[i].rch = HuffTree[i].parent = 0;
    }
    for (i = n + 1; i <= m; i++)
    {
        int s1, s2;
        selectMinTwo(i - 1, s1, s2);
        HuffTree[i].weight = HuffTree[s1].weight + HuffTree[s2].weight;
        HuffTree[i].lch = s1, HuffTree[i].rch = s2;
        HuffTree[s1].parent = HuffTree[s2].parent = i;
    }
    HfCode = new string[n+1];
    for(i =1;i<=n;++i){
        string temp = "";
        for(int child = i,fa = HuffTree[i].parent;fa != 0;child = fa,fa = HuffTree[fa].parent){
            if(HuffTree[fa].lch == child){
                temp = '0' + temp;
            }else{
                temp =  '1'+temp;
            }
        }
        HfCode[i] = temp;
    }
}
int main()
{
    int i;
    cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        HuffmanCode();
        for (i = 1; i <= n; i++)
        {
            if(i!=n)
			cout<<HfCode[i]<<endl;
			else
			cout<<HfCode[i];
        }
        delete [] HuffTree;
        delete [] HfCode;
    return 0;
}
