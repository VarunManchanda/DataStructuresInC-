#include <bits/stdc++.h>
using namespace std;
//Kruskal is applied to find MST to a graph with property of graph as follows:-
//1) Undirected
//2) Connected
//3) Weighted
/*
                1 --- 3
              / |    /|
    Graph is 0  |  /  |
              \ |/    |
                2 --- 4
    weights of edges are as follows:-
    0----1 : 4
    0----2 : 8
    1----3 : 6
    1----2 : 2
    2----3 : 3
    2----4 : 9
    3----4 : 5
*/
//compile it using g++ Kruskal.cpp -o kruskal -std=c++11
//run it as ./kruskal and paste this below test case
/*run this test case
5 7 
0 1 4
0 2 8
1 2 2
1 3 6
2 3 3
2 4 9
3 4 5
*/
class Edge
{
    public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int node, int *parent)
{
    if(parent[node] == node)
    {
        return node;
    }
    return findParent(parent[node], parent);
}

void kruskalAlgo(Edge *input, int nodes, int edges)
{
    sort(input, input+edges, compare); //sort the edges based on weight
    //now pick one edge per edge and if it's having a cycle if not then add to final array
    //also we need a parent array, initially parent of all are they itself
    int *parent = new int[nodes];
    for(int i=0; i<nodes; i++)
    {
        parent[i] = i; //initially [0,1,2,3,4,5]
    }
    Edge *ouput = new Edge[nodes-1];
    int count = 0;
    int i = 0;
    while(count!=(nodes-1))
    {
        Edge minEdge = input[i];
        int sourceParent = findParent(minEdge.source, parent);
        int destParent   = findParent(minEdge.dest, parent);
        if(sourceParent!=destParent)
        {
            ouput[count] = minEdge;
            count += 1;
            //now take union 
            parent[sourceParent] = destParent;
        }
        i += 1;
    }

    //print the MST
    int total_min_distance = 0;
    for(int i=0; i<nodes-1; i++)
    {
        if(ouput[i].source < ouput[i].dest)
        {
            cout << ouput[i].source << " " << ouput[i].dest << " weight " << ouput[i].weight << endl;
            total_min_distance += ouput[i].weight;
        }
        else
        {
            cout << ouput[i].dest << " " << ouput[i].source << " weight " << ouput[i].weight << endl;
            total_min_distance += ouput[i].weight;
        }
    }
    cout << "Total Minimum Distance taken is " << total_min_distance << endl;
    //free space
    delete[] ouput;
    delete[] parent;
    //safe return!!
    return;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    //make an array of edges;
    Edge *input = new Edge[edges];
    for(int i=0; i<edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        input[i].source = u;
        input[i].dest = v;
        input[i].weight = w;
    }
    kruskalAlgo(input,nodes,edges);
    //free spaces
    delete[] input;
    return 0;
}
