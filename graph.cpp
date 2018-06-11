// Waylon Peng, Period 1
// 6May2018
// Linked List Assignment
// Implements an undirected graph with various utility functions.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

class Graph
{
  public:
    Graph(int n);
    void add_edge(int i, int j); // adds new edge to graph. can handle parallel edges and loops
    void print_adj_matrix(); // prints adj matrix
    void print_inc_matrix(); // prints inc matrix
    void print_edge_list(); // prints edge list
    int shortest_path(int i, int j);

    struct PathNode // used to store data for the BFS
    {
        PathNode(int node, int distance) : node(node), distance(distance) {}
        int node; // node to operate on
        int distance; // distance traveled to get to node
    };
    struct Edge {
        int a;
        int b;
        Edge(int i, int j)  : a(i), b(j) {}
    };

  private:
    int num_vertices; // number of vertices
    int **adj_matrix; // 2d array for adj matrix
    vector<int *> inc_matrix; // vector of arrays for inc matrix. vector used for arbitrary # of edges, as each element is an edge
    vector<Edge> edge_list;
};

Graph::Graph(int n) : num_vertices(n) // constructor
{
    // initialize adj matrix
    adj_matrix = new int *[n];
    for (int i = 0; i < n; i++) // for each node
    {
        adj_matrix[i] = new int[n]; // create row with one position for each node
        for (int j = 0; j < n; j++)
        {
            adj_matrix[i][j] = 0; // set all values to false
        }
    }
}

void Graph::add_edge(int i, int j)
{
    adj_matrix[i - 1][j - 1] += 1; // inserts true into adj matrix
    adj_matrix[j - 1][i - 1] += 1;
    inc_matrix.push_back(new int[num_vertices]); // inserts new row for new edge in inc matrix
    for (int n = 0; n < num_vertices; n++)
    {
        inc_matrix.at(inc_matrix.size() - 1)[n] = 0; // initializes values in row to false
    }
    inc_matrix.at(inc_matrix.size() - 1)[i - 1] += 1; // inserts true into inc matrix
    inc_matrix.at(inc_matrix.size() - 1)[j - 1] += 1;
    edge_list.push_back(Edge(i ,j));
}

void Graph::print_adj_matrix()
{
    cout << "   ";
    for (int i = 0; i < num_vertices; i++)
    {
        cout << i + 1 << "  ";
    }
    cout << endl;
    for (int i = 0; i < num_vertices; i++)
    {
        cout << " " << i + 1 << " ";
        for (int j = 0; j < num_vertices; j++)
        {
            cout << adj_matrix[i][j];
            cout << "  ";
        }
        cout << endl;
    }
}

void Graph::print_inc_matrix()
{
    cout << "   ";
    for (int i = 0; i < num_vertices; i++)
    {
        cout << i + 1 << "  ";
    }
    cout << endl;
    for (int i = 0; i < inc_matrix.size(); i++)
    {
        cout << "e" << i + 1 << " ";
        for (int j = 0; j < num_vertices; j++)
        {
            cout << inc_matrix.at(i)[j];
            cout << "  ";
        }
        cout << endl;
    }
}

void Graph::print_edge_list()
{
    for (int i = 0; i < edge_list.size(); i++)
    {
        Edge cur_edge = edge_list.at(i);
        cout << "   (" << cur_edge.a << ", " << cur_edge.b << ")" << endl;
    }
}

int Graph::shortest_path(int start, int end) // djikstra-based shortest path algorithm
{
    vector<int> seen; // tracks already-traversed nodes
    queue<PathNode> work; // queue for breadths

    PathNode start_node(start, 0); // initial starting node
    work.push(start_node); // insert starting node into queue
    seen.push_back(start); // mark starting node as already-seen
    while (work.size() != 0)
    {
        PathNode cur = work.front(); // grab the next queued node (now the current node)
        work.pop();
        seen.push_back(cur.node); // mark current node as seen
        if (cur.node == end) { // if current node is destination, return the traveled distance
            return cur.distance;
        }
        for (int i = 0; i < num_vertices; i++) // iterate over all nodes in graph
        {
            if (adj_matrix[i][cur.node - 1] != 0) // if new node is connected to current node
            {
                if (std::find(seen.begin(), seen.end(), i + 1) == seen.end()) // and if new node has not been traversed yet
                {
                    work.emplace(i + 1, cur.distance + 1); // queue new node with incremented travel distance
                }
            }
        }
    }

    return -1; // if the end is never found, return -1
}

void create_matrix(Graph in) {
    cout << "   Incidence Matrix" << endl;
    in.print_inc_matrix();
    cout << "   Adjacency Matrix" << endl;
    in.print_adj_matrix();
    cout << "   Edge List" << endl;
    in.print_edge_list();
}

int main()
{
    cout << "   Processing graph 1..." << endl;
    Graph one(7);
    one.add_edge(1, 2);
    one.add_edge(2, 3);
    one.add_edge(3, 4);
    one.add_edge(2, 4);
    one.add_edge(2, 5);
    one.add_edge(2, 6);
    one.add_edge(5, 6);
    one.add_edge(6, 7);
    create_matrix(one);

    cout << "   Processing graph 2..." << endl;
    Graph two(5);
    two.add_edge(1, 2);
    two.add_edge(2, 3);
    two.add_edge(1, 5);
    two.add_edge(3, 4);
    two.add_edge(1, 3);
    two.add_edge(1, 4);
    two.add_edge(3, 5);
    two.add_edge(4, 5);
    create_matrix(two);

    cout << "   Processing graph 3..." << endl;
    Graph three(5);
    three.add_edge(1, 2);
    three.add_edge(3, 5);
    three.add_edge(3, 4);
    three.add_edge(4, 5);
    create_matrix(three);

    cout << "   Processing graph 4..." << endl;
    Graph four(6);
    four.add_edge(1, 2);
    four.add_edge(1, 5);
    four.add_edge(1, 6);
    four.add_edge(2, 3);
    four.add_edge(2, 5);
    four.add_edge(3, 4);
    four.add_edge(4, 5);
    four.add_edge(4, 6);
    create_matrix(four);
}
