#include<iostream>
#include<map>
#include<vector>
#include<list>

using namespace std;

class Graph{
    map<int, list<int>> g;
    vector<int> visited;
    vector<int> stack;
    int V;
    public:
    Graph(int n):V{n}{
        visited.resize(n);
    };
    void addEdge(int u, int v){
        g[u].push_back(v);
    }
    bool cycle_handler(int src){
        // start
        visited[src] = true;
        stack[src] = true;

        for(int nbr:g[src]) {
            if(stack[src]) return true;
            else if(!visited[nbr]) if(cycle_handler(nbr)) return true;
        }


        //end

        stack[src] = false;

        return false;

    }

    bool hasCycle(){
        fill_n(visited.begin(), V, false);
        fill_n(stack.begin(), V, false);

           for(int i=0; i<V; i++){
            if(!visited[i]){
                if(cycle_handler(i)) return true;
            }
        }

        return false; 


        // for(auto l:g){
        //     int src = l.first;
        //     if(!visited[src]) cycle_handler(src);;
        // }
 
     }
};

int main(){
    int V,E,x,y;
    cin>>V>>E;
    Graph g(V);
    while(E--){
        cin>>x>>y;
        g.addEdge(x,y);
    }

    cout << (g.hasCycle() ? "has Cycle" : "No Cycle") << endl;


    return 0;

}