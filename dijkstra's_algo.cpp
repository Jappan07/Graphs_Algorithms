#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<queue>
using namespace std;
template<typename T>
class Graph {
    unordered_map<T, list<pair<T, int> > > adjList;

public:

    void addEdge(T u, T v, int dist, bool bidir = true) {
        adjList[u].push_back(make_pair(v, dist));
        if (bidir) {
            adjList[v].push_back(make_pair(u, dist));
        }
    }


    void print() {

        for (auto p : adjList) {
            auto key = p.first;
            auto neigbours = p.second; //list of neigbours

            cout << key << "->";
            for (auto n : neigbours) {
                cout << "(" << n.first << "," << n.second << ")";
            }
            cout << endl;
        }
    }


    void dijkstraSSS(T src) {
        unordered_map<T, int>dist;
        // set all distances to infinity
        for (auto i : adjList) {
            dist[i.first] = INT_MAX;
        }
        // make a set to find out the node with minimum distance.
        set<pair<int, T> >s; // by default set sorts according to the first parameter(here it's the distance)
        dist[src] = 0;
        s.insert(make_pair(0, src));
        while (!s.empty()) {
            // find the pair at the front
            auto p = *(s.begin()); //* will return the pair
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            for (auto neighbours : adjList[node]) {

                if (nodeDist + neighbours.second < dist[neighbours.first]) {
                    // in set, updation is not possible
                    // we have to remove the old pair and insert the new one.
                    T dest = neighbours.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if (f != s.end()) {
                        s.erase(f);

                    }
                    // insert the new pair
                    dist[dest] = nodeDist + neighbours.second;
                    s.insert(make_pair(dist[dest], dest));



                }


            }




        }
        // lets print the distances to all the nodes from the source.
        for (auto d : dist) {

            cout << d.first << " is located at distance of " << d.second << endl;
        }



    }




};


int main() {

    Graph<int>g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);
    g.print();
    g.dijkstraSSS(1);
    // Graph<string>india;
    // india.addEdge("Amritsar", "Delhi", 1);
    // india.addEdge("Amritsar", "Jaipur", 4);
    // india.addEdge("Jaipur", "Delhi", 2);
    // india.addEdge("Jaipur", "Mumbai", 8);
    // india.addEdge("Bhopal", "Agra", 2);
    // india.addEdge("Mumbai", "Bhopal", 3);
    // india.addEdge("Agra", "Delhi", 1);
    // india.print();
    // india.dijkstraSSS("Amritsar");




    return 0;
}





















