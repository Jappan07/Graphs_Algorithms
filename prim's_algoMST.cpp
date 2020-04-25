#include<iostream>
#include<list>
using namespace std;
class Graph {
	int v;
	list<pair<int, int> >*adjlist;
public:


	Graph(int maxsize) {
		v = maxsize;
		adjlist = new list<pair<int, int> >[v];



	}
	void addEdge(int u, int v, int w) {
		adjlist[u].push_back(make_pair(v, w));
		adjlist[v].push_back(make_pair(u, w));


	}
	void print_adjlist() {
		cout << "ADJACENCY LIST" << endl;
		for (int i = 0; i < v; i++) {
			int node = i;
			cout << node << "-->";
			auto neighbour = adjlist[node];
			for (auto n : neighbour) {
				cout << "(" << n.first << "," << n.second << ")";
			} cout << endl;


		}
	}
	int findminvertex(int *weight, int v, bool *visited) {
		int minvertex = -1;
		for (int i = 0; i < v; i++) {
			if (!visited[i] and (minvertex == -1 or weight[i] < weight[minvertex])) {
				minvertex = i;

			}
		}



		return minvertex;


	}
	void prims() {
		bool* visited = new bool[v];
		int* parent = new int[v];
		int* weight = new int[v];

		for (int i = 0; i < v; ++i) {
			visited[i] = false;
			weight[i] = INT_MAX;

		}
		parent[0] = -1;
		weight[0] = 0;
		for (int i = 0; i < v; i++) {
			int minvertex = findminvertex(weight, v, visited);
			visited[minvertex] = true;
			for (auto neighbours : adjlist[minvertex]) {
				if (!visited[neighbours.first]) {
					if (weight[neighbours.first] > neighbours.second) {
						parent[neighbours.first] = minvertex;
						weight[neighbours.first] = neighbours.second;

					}
				}
			}
		}

		for (int i = 1; i < v; i++) {
			cout << i << "--" << parent[i] << " with weight " << weight[i] << endl;
		}


	}



};


int main() {
	int n, e;
	cin >> n >> e;
	Graph g(n);
	int u, v, w;
	for (int i = 0; i < e; i++) {

		cin >> u >> v >> w;
		g.addEdge( u,  v,  w);
	}
	g.print_adjlist();
	g.prims();

// input file
	/*
	7 8
	0 3 4
	0 1 6
	1 2 5
	3 2 7
	3 4 2
	4 5 4
	5 6 1
	4 6 3
	*/




	return 0;
}