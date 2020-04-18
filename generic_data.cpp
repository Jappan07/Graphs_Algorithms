#include<iostream>
#include<map>
#include<list>
using namespace std;

class Graph{
    map<string,list<string> > adjList; 

public:
    Graph(){
    }

    void addEdge(string u,string v,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    void print(){

        for(auto p:adjList){
            string key = p.first;
            auto neigbours = p.second; //list of neigbours

            cout<<key<<"->";
            for(auto n:neigbours){
                cout<<n<<",";
            }
            cout<<endl;
        }
    }
};


int main(){

    Graph g;
    g.addEdge("Putin","Trump",false);
    g.addEdge("Putin","Modi",false);
    g.addEdge("Putin","Pope",false);
    g.addEdge("Modi","Trump",true);
    g.addEdge("Modi","Yogi",true);
    g.addEdge("Yogi","Prabhu",false);
    g.addEdge("Prabhu","Modi",false);
    
    g.print();
    

    return 0;
}