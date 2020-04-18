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
    bool isCyclic(T src) {
        map<T, bool>visited;
        map<T, T>parent;
        queue<T>q;
        q.push(src);
        visited[src] = true;
        parent[src] = src;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();


            for (auto neighbours : adjList[node]) {
                if (visited[neighbours] == true && parent[node] != neighbours) {
                    return true;
                }
                else if (!visited[neighbours]) {
                    visited[neighbours] = true;
                    q.push(neighbours);
                    parent[neighbours] = node;
                }

            }
        }
        return false;

    }
};


int main() {

    Graph<int>g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 4);

    if (g.isCyclic(0)) {
        cout << "It is a Cyclic graph!!" << endl;
    }
    else {
        cout << "It is not a Cyclic graph" << endl;
    }


    return 0;
}





















