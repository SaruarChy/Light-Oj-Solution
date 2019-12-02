#include<bits/stdc++.h>
using namespace std;
vector<int>adj[30001],cost[30001];
int n,dis[30001],dis1[30001],source,src,p;
void bfs(int source)
{
    for(int i=0;i<=n;i++)
        dis[i]=-1;
    int maxi=-1;
    queue<int>q;
    q.push(source);
    dis[source]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(maxi<dis[u])
        {
            maxi=dis[u];
            p=u;
        }
        for(int j=0; j<adj[u].size(); j++)
        {
            int v=adj[u][j];
                if(dis[v]==-1)
                {
                    dis[v]=dis[u]+cost[u][j];
                    q.push(v);
                }

        }
    }
}
void bfs1(int src){
    for(int i=0;i<=n;i++)
        dis1[i]=-1;
    queue<int>q;
    q.push(src);
    dis1[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int j=0; j<adj[u].size(); j++)
        {
            int v=adj[u][j];
                if(dis1[v]==-1)
                {
                    dis1[v]=dis1[u]+cost[u][j];
                    q.push(v);
                }
        }
    }
}
int main()
{
    int t,test=1,u,v,w,m,i;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        m=n-1;
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        bfs(0);
        source=p;
        bfs(source);
        src=p;
        bfs1(src);
        printf("Case %d:\n", test++);
        for(i=0;i<n;i++)
        {
            printf("%d\n", max(dis[i], dis1[i]));
            adj[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
