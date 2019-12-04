#include<bits/stdc++.h>
using namespace std;
bool bfs(int rg[105][105], int s, int t, int parent[])
{
    bool visited[105];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<105; v++)
            if (visited[v]==false && rg[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
    }
    return (visited[t] == true);
}
//fordfulkerson algorithm
int fordFulkerson(int graph[105][105], int s, int t)
{
    int u, v;
    int rg[105][105];
    for (u = 0; u < 105; u++)
        for (v = 0; v < 105; v++)
             rg[u][v] = graph[u][v];

    int parent[105];
    int maxflow = 0;
    while (bfs(rg, s, t, parent))
    {
        int pathflow=INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u= parent[v];
            pathflow = min(pathflow,rg[u][v]);
        }
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rg[u][v] -= pathflow;
            rg[v][u] += pathflow;
        }
        maxflow += pathflow;
    }
    return maxflow;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,cas=1;
    cin >> t;
    while(t--)
    {
        int n,m,u,v,w,s,e;

        cin>> n>>s>>e>>m;

        int adj[105][105];
        memset(adj,0,sizeof adj);

        while(m--)
        {
            cin >>u>>v>>w;
            adj[u][v]+=w;
            adj[v][u]+=w;
        }
        cout << "Case "<<cas++<<": "<<fordFulkerson(adj,s,e)<<endl;
    }
    return 0;
}
