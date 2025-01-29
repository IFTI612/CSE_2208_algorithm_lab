///Johnson’s algorithm for All-pairs shortest paths
///id: 20220204030

#include<bits/stdc++.h>
using namespace std;

/*
 1.Add a new vertex s to the graph, add edges from the new vertex to all vertices of G.
 modify the graph G’.

 2.run bellman on G' graph.et the distances calculated by Bellman-Ford be h[0], h[1], .. h[V-1].
  If we find a negative weight cycle, then return. Note that the negative weight cycle cannot be
  created by new vertex s as there is no edge to s. All edges are from s.

 3.Reweight the edges of the original graph. For each edge (u, v), assign the new weight as
 “original weight + h[u] – h[v]”.

 4.Remove the added vertex s and run Dijkstra’s algorithm for every vertex.
*/


/*
Input from Slide
5 9
1 2 3
1 3 8
1 5 -4
5 4 6
4 1 2
4 3 -5
3 2 4
2 5 7
2 4 1

normal input....
4 5
1 2 -5
2 3 4
1 3 2
3 4 1
1 4 3


negative weight cycle
4 5
1 2 3
2 3 2
3 4 -5
4 2 -4
1 4 6

 */

#define para cout<<endl
#define INF 999
#define nul -1

int node_no,edge_no;
vector<vector<int>>cost,pi,adj;

vector<vector<int>>G, Gm;
bool negCycle = false;

vector<int>h;


void printMatrix(vector<vector<int>>&c)
{
    cout << "Matrix:" << endl;

    // Nested loops to access each element
    for (int i = 1; i < node_no; i++)                  // Iterate rows
    {
        for (int j = 1; j < node_no; j++)           // Iterate columns
        {
            cout << c[i][j] << " ";                        // Print each element
        }
        cout << endl;
    }
}

void printMatrixEn(vector<vector<int>>&e)
{
    cout << "Matrix:" << endl;

    // Nested loops to access each element
    for (int i = 0; i < node_no; i++)                  // Iterate rows
    {
        for (int j = 0; j < node_no; j++)           // Iterate columns
        {
            cout << e[i][j] << " ";                        // Print each element
        }
        cout << endl;
    }
}



void dijkstra(int src)
{
    vector<int> d(node_no, INF);   // Min cost to reach a node
    vector<int> pre(node_no, nul); // Predecessor node
    vector<bool> visited(node_no, false); // Mark visited nodes

    d[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, src});  // Push (distance, node)

    while (!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();

        if (visited[u]) continue;  // Skip already visited nodes
        visited[u] = true;

        for (int v : adj[u])
        {
            int weight = Gm[u][v];
            if (d[u] + weight < d[v])
            {
                d[v] = d[u] + weight;
                pre[v] = u;
                Q.push({d[v], v}); // Push updated distance and node
            }
        }
    }

    Gm[src] = d;   // Save shortest path costs for src
    pi[src] = pre; // Save predecessors for src
}





void Bellman(int scr)
{
    cout<<"Bellman Starts"<<endl;
    ///initializing single source
    vector<int> d(node_no, INF);
    vector<int> pre(node_no, nul);
    d[scr] = 0;

    h.resize(node_no); // Resizing h to the size of node_no

    for (int i = 1; i <= node_no; i++) // Bellman gives solution in node - 1 iterations
    {
        for (int u = 0; u < node_no; u++) // u starts from 0 as it is the newly added node
        {
            for (int v : adj[u]) // For all adjacent nodes of u
            {
                if (d[v] > (d[u] + cost[u][v])) // If the cost of using source and present node is lower than the previous min cost then it will be updated
                {
                    d[v] = (d[u] + cost[u][v]);
                    pre[v] = u; // Updates the predecessor to be the currently exploring node
                }
                h[v] = d[v]; // Sets all h(v) = lambda(s, v). copy the d[v]
            }
        }
    }

    /// For checking Negative Edge Cycle
    for (int u = 1; u < node_no; u++)
    {
        for (int i = 0; i < adj[u].size(); i++) // For all adjacent nodes of u
        {
            int v = adj[u][i];              // v is the adjacent node of u which updates every iteration
            if (h[v] > (h[u] + cost[u][v])) /// If the cost of using source and present node is lower than the previous min cost then there is a negative edge cycle
            {
                negCycle = true;
                cout << "There is a Negative Edge Cycle" << endl;
                return;
            }
        }
    }

}


void printPath(int i, int j) // Recursive print path
{
    // The basic principle is that it will explore from the destination to the source by going
    // through the predecessor node
    // If the predecessor node is NIL, there will be no way to reach j from i
    // Else, it will recursively check the predecessor node until it reaches the source
    if (i == j) // Starts from i
    {
        cout << i;
    }
    else if (pi[i][j] == nul) // If the predecessor of any node is NIL
    {
        cout << "No path from " << i << " to " << j << " exists" << endl;
        return;
    }
    else
    {
        printPath(i, pi[i][j]); // Recursively reaches the source and then goes back to the immediate after node until reaching the destination
        cout << " -> " << j;
    }
}


void Jonson()
{
    cout<<"Jonson Starts"<<endl;
    int new_scr = 0;



    for (int i = 1; i < node_no; i++)
    {
        cost[0][i] = 0;      // Sets cost from 0 to all nodes as 0
        adj[0].push_back(i); // COnnects all nodes with 0
    }

    printMatrixEn(cost);

    Bellman(new_scr);

    if (negCycle) /// If there is a negative cycle Jonson return
    {
        cout << "There is no solution to the graph" << endl;
        return;
    }

    Gm.resize(node_no,vector<int>(node_no,INF));//initialize Gm as a modified graph

    for (int i = 1; i < node_no; i++)
    {
        Gm[i][i] = 0; // Self looping prevention thing
    }

    for (int u = 1; u < node_no; u++)
    {
        for (int v : adj[u])
        {
            Gm[u][v] = cost[u][v] + h[u] - h[v]; // Updates each element using W' = W(u,v) + h(v) - h(u)
        }
    }

    ///run dijkstra in all nodes

    for (int src = 1; src < node_no; src++)
    {
        dijkstra(src);
    }

    // Initializes G = d(u,v) as a new node_no x node_no matrix
    G.resize(node_no, vector<int>(node_no, INF));
    for (int i = 1; i < node_no; i++)
    {
        G[i][i] = 0; // Self looping prevention thing
    }

    for (int u = 1; u < node_no; u++)
    {
        for (int v = 1; v < node_no; v++)
        {

            G[u][v] = Gm[u][v] + h[v] - h[u]; // Updates each element as d(u,v) = lambda(u,v) + h(v) - h(u)

        }
    }




    ///print paths

    for (int i = 1; i < node_no; i++) // Prints ALL path
    {
        cout << "From " << i << " to " << endl;
        for (int j = 1; j < node_no; j++)
        {
            cout << j << ": ";
            printPath(i, j);
            if (G[i][j] != INF)
            {
                cout << "   Cost: " << G[i][j] << endl;
            }
        }
        para;
    }
para;
    cout << "Johnson completed cost: ";
    printMatrix(G);  // Prints the finally obtained Cost Matrix
    cout << "pi: ";
    printMatrix(pi); // Prints the finally obtained Predecessor Matrix


}


int main()
{
    cout << "Enter Number of Nodes and Edges: ";
    cin>>node_no>>edge_no;
    ///first take the the number of node
    ///then new graph node no and init the cost matrix with INF
    node_no++;///for 1 base matrix


    cost.resize(node_no,vector<int>(node_no,INF));///creating 2d cost and pi matrix

    pi.resize(node_no,vector<int>(node_no,nul));

    for(int i=1; i<node_no; i++)
    {
        cost[i][i]=0; ///preventing from self looping
    }

    adj.resize(node_no);///creates node size of rows

    cout << "Enter connections and weights: " << endl;

    int node_a, node_b, weight;
    for (int i = 1; i <= edge_no; i++)
    {
        cin >> node_a >> node_b >> weight;
        cost[node_a][node_b] = weight;   // Sets the [i][j]-th element of the matrix to be the cost to visit j from i
        pi[node_a][node_b] = node_a;    // Sets the [i] as [j]'s predecessor
        adj[node_a].push_back(node_b); //
    }


    para;

    cout<<"Cost ";
    printMatrix(cost);///printing  cost matrix
    para;
    cout<<"Pi ";
    printMatrix(pi);///printing  pi matrix

    para;
    Jonson();




    return 0;
}
