#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph {
    map<T, list<T> > adjList;

public:
    Graph() {
    }

    void addEdge(T u, T v, bool bidir = true) {
        adjList[u].push_back(v);
        if (bidir) {
            adjList[v].push_back(u);
        }
    }
    void print() {

        for (auto p : adjList) {
            auto key = p.first;
            auto neigbours = p.second; //list of neigbours

            cout << key << "->";
            for (auto n : neigbours) {
                cout << n << ",";
            }
            cout << endl;
        }
    }
    void dfsHelper(T node, map<T, bool>&visited) {
        visited[node] = true;
        cout << node << " ";
        for (auto neighbours : adjList[node]) {
            if (!visited[neighbours]) {
                dfsHelper(neighbours, visited);
            }
        }

    }

    void dfs(T src) {
        map<T, bool>visited;
        int component = 1;
        dfsHelper(src, visited);
        cout << '\n';
        for (auto i : adjList) {
            T city = i.first;
            if (!visited[city]) {
                dfsHelper(city, visited);
                component++;

            }

        } cout << "The current graph had " << component << " components" << endl;

    }
};


int main() {

    Graph<string>g;
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Delhi", "Jaipur");
    g.addEdge("Mumbai", "Jaipur");
    g.addEdge("Mumbai", "Bhopal");
    g.addEdge("Delhi", "Bhopal");
    g.addEdge("Mumbai", "Bangalore");
    g.addEdge("Agra", "Delhi");
    g.addEdge("Andaman", "Nicobar");


    cout << "Adjacency list:" << endl;
    g.print();
    cout << "Depth First Search Traversal Applied:" << endl;
    g.dfs("Amritsar");


    return 0;
}





















