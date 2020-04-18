#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph {
    map<T, list<T> >adjlist;
public:
    void addEdge(T u, T v, bool bidir = true) {
        adjlist[u].push_back(v);
        if (bidir) {
            adjlist[v].push_back(u);
        }

    }
    void print() {
        for (auto i : adjlist) {
            auto node = i.first;
            cout << node << "->";
            auto neighbour = i.second;
            for (auto n : neighbour) {
                cout << n << ",";
            } cout << endl;
        }

    }

    T bfs(T src, T dest) {
        map<T, T>dist;
        queue<T>q;
        map<T, T>parent;
        q.push(src);

        for (auto d : adjlist) {
            dist[d.first] = INT_MAX;
        }
        dist[src] = 0;
        parent[src] = src;

        while (!q.empty()) {
            T node = q.front();
            q.pop();


            for (auto neighbour : adjlist[node]) {
                if (dist[neighbour] == INT_MAX) {
                    q.push(neighbour);
                    dist[neighbour] = dist[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }
        // for (auto i : adjlist) {
        //     T node = i.first;
        //     cout << "\nDistance of " << node << " is " << dist[node] << endl;
        // }

        // To trace the path
        int temp = dest;
        while ( temp != src) {
            cout << temp << "<--";
            temp = parent[temp];
        }

        return dist[dest];

    }


};


int main() {
    Graph<int>g;
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    for (int u = 0; u <= 36; u++) {
        for (int dice = 1; dice <= 6; dice++) {
            int v = u + dice + board[u + dice];
            g.addEdge(u, v, false);
        }
    }

    cout << "The shortest distance in a snakes & ladders game is " << g.bfs(0, 36) << endl;;


    return 0;
}