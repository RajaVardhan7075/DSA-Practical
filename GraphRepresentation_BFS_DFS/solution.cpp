#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Graph class
class Graph {
    int vertices;

    // Adjacency list
    vector<vector<int>> adjList;

    // Adjacency matrix
    vector<vector<int>> adjMatrix;

public:

    // Constructor
    Graph(int v) {
        vertices = v;

        // Create empty list for each vertex
        adjList.resize(vertices);

        // Create matrix and fill it with 0
        adjMatrix.assign(vertices, vector<int>(vertices, 0));
    }

    // Add an edge between two vertices
    void addEdge(int u, int v) {

        // Add v to u's list
        adjList[u].push_back(v);

        // Add u to v's list
        // This is an undirected graph
        adjList[v].push_back(u);

        // Add edge in adjacency matrix
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    // Display adjacency list
    void displayAdjList() {

        cout << "\nAdjacency List:\n";

        for (int i = 0; i < vertices; i++) {

            cout << i << " -> ";

            // Display all connected vertices
            for (int j : adjList[i])
                cout << j << " ";

            cout << endl;
        }
    }

    // Display adjacency matrix
    void displayAdjMatrix() {

        cout << "\nAdjacency Matrix:\n";

        // Display column numbers
        cout << "  ";

        for (int i = 0; i < vertices; i++)
            cout << i << " ";

        cout << endl;

        // Display matrix
        for (int i = 0; i < vertices; i++) {

            cout << i << " ";

            for (int j = 0; j < vertices; j++)
                cout << adjMatrix[i][j] << " ";

            cout << endl;
        }
    }

    // Breadth First Search
    void BFS(int start) {

        // Initially all vertices are not visited
        vector<bool> visited(vertices, false);

        // Queue is used for BFS
        queue<int> q;

        // Mark starting vertex as visited
        visited[start] = true;

        // Add starting vertex to queue
        q.push(start);

        cout << "\nBFS from " << start << ": ";

        // Continue until queue becomes empty
        while (!q.empty()) {

            // Get the first vertex from queue
            int node = q.front();
            q.pop();

            cout << node << " ";

            // Check all neighbouring vertices
            for (int neighbour : adjList[node]) {

                // Visit only unvisited vertices
                if (!visited[neighbour]) {

                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        cout << endl;
    }

    // Helper function for DFS
    void DFSHelper(int node, vector<bool>& visited) {

        // Mark current vertex as visited
        visited[node] = true;

        cout << node << " ";

        // Visit all unvisited neighbours
        for (int neighbour : adjList[node]) {

            if (!visited[neighbour])
                DFSHelper(neighbour, visited);
        }
    }

    // Depth First Search
    void DFS(int start) {

        // Initially all vertices are not visited
        vector<bool> visited(vertices, false);

        cout << "DFS from " << start << ": ";

        // Start DFS from given vertex
        DFSHelper(start, visited);

        cout << endl;
    }
};

int main() {

    int vertices, edges;

    // Read number of vertices
    cout << "Enter number of vertices: ";
    cin >> vertices;

    // Read number of edges
    cout << "Enter number of edges: ";
    cin >> edges;

    // Create graph
    Graph graph(vertices);

    // Read edges
    cout << "Enter " << edges << " edges (u v):\n";

    for (int i = 0; i < edges; i++) {

        int u, v;

        cin >> u >> v;

        graph.addEdge(u, v);
    }

    // Display adjacency list
    graph.displayAdjList();

    // Display adjacency matrix
    graph.displayAdjMatrix();

    int start;

    // Read starting vertex
    cout << "\nEnter start vertex for traversal: ";
    cin >> start;

    // Perform BFS
    graph.BFS(start);

    // Perform DFS
    graph.DFS(start);

    return 0;
}
