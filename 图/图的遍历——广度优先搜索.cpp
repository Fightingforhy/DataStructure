#include <stdio.h>
#include <string.h>
int main()
{
    int n, head, tail;
    int arr[2500], map[55][55], vis[55];
    while (~scanf("%d", &n))
    {
    head = tail = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
            for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    } 
    vis[0] = 1;
    arr[tail++] = 0;
    printf("0 ");
    while (head < tail)
    {
        for (int i = 0; i < n; i++)
            {
        if (map[arr[head]][i] && !vis[i])
        {
            vis[i] = 1;
            arr[tail++] = i;
            printf("%d ", i);
        }
        }
        head++;
    }
    puts("");
    }
    return 0;
}
 
