//O(ElogV)
#include<bits/stdc++.h>
using namespace std;
#define INF 100005
typedef pair<int, int> pii;
const int N = 105;
vector<pair <int, int> >adj[N];
int V, E;
bool visited[N];
void prim(int s)
{
    memset(visited,false, V);
    priority_queue<pii, vector<pii>, greater <pii> > q;
    vector<int> key(V, INF);
    int parent[V];
    memset(parent, -1, V);
    q.push(make_pair(0,s));
    visited[s] = true;
    key[s] = 0;
    while(!q.empty())
    {
        int u = q.top().second;
        visited[u] = true;
        q.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int weight= adj[u][i].second;
            if(visited[v] == false && key[v] > weight)
            {
                key[v] = weight;
                q.push(make_pair(weight, v));
                parent[v] = u;
            }
        }
    }

    cout << "Edges in MST: " << "\n";
    for(int i = 1; i < V; i++)
        cout  << parent[i] << " - " << i << "\n";
}

int main()
{
    freopen("in.in", "r",stdin);
    freopen("test.out", "w", stdout);
    cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
    prim(0);
    return 0;
}