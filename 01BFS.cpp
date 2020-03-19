#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;
vector<pair<int,int>> adjList[100005];
int dist[100005];

void print(int n)
{
    for(int i=1; i<=n; i++)
    {
        cout << i << "-> ";
        for(auto neighbour : adjList[i])
        {
            cout << "(" << neighbour.first << " with weight " << neighbour.second << ") ";
        }
        cout << endl;
    }
}

void bfs(int src, int n)
{
    deque<int> q;
    q.push_back(src);
    for(int i=1; i<=n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    while(!q.empty())
    {
        int node = q.front(); q.pop_front();
        for(auto neighbour : adjList[node])
        {
            if(dist[node] + neighbour.second < dist[neighbour.first])
            {
                dist[neighbour.first] = dist[node] + neighbour.second;
                if(neighbour.second==0)
                {
                    q.push_front(neighbour.first);
                }
                else
                {
                    q.push_back(neighbour.first);
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout << "Distance of " << i << " is " << dist[i] << endl;
    }
}



int main() {
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        adjList[u].emplace_back(make_pair(v,weight));
        adjList[v].emplace_back(make_pair(u,weight));
    }
    bfs(1,n);
    print(n);
    return 0;
}
