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
    bool isCyclic_helper(T node, map<T, bool>&visited, map<T, bool>&inStack) {
        // processing the current node- Visited,inStack
        visited[node] = true;
        inStack[node] = true;
        for (auto neighbour : adjList[node]) {
            if ((!visited[neighbour] && isCyclic_helper(neighbour, visited, inStack)) or inStack[neighbour]) {
                return true;
            }
        }
        inStack[node] = false;
        return false;


    }
    bool isCyclic() {
        map<T, bool>visited;
        map<T, bool>inStack;
        // to check for a cycle in each dfs tree
        for (auto i : adjList) {
            auto node = i.first;
            if (!visited[node]) {
                bool cyclepresent = isCyclic_helper(node, visited, inStack);
                if (cyclepresent) {
                    return true;
                }
            }
        }
        return false;
    }

};


int main() {

    Graph<int>g;
    g.addEdge(0, 2, false);
    g.addEdge(0, 1, false);
    g.addEdge(2, 3, false);
    g.addEdge(2, 4, false);
    // g.addEdge(3, 0, false);
    g.addEdge(4, 5, false);
    g.addEdge(1, 5, false);


    if (g.isCyclic()) {
        cout << "It is a Cyclic graph!!" << endl;
    }
    else {
        cout << "It is not a Cyclic graph" << endl;
    }


    return 0;
}