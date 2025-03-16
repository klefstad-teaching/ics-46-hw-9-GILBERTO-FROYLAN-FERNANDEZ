#include "dijkstras.h"
#include <numeric>

int main(int argc, char* args[]){
    Graph G;
    string path = (argc > 1) ? args[1] : "../src/small.txt";
    file_to_graph(path, G);
    // if (argc > 1) file_to_graph(args[1], G);
    // else file_to_graph("../src/small.txt", G);
    // else {cerr << "Please input file name" << endl; return 0;}
    vector<int> previous(G.size());
    for (int i = 0; i < previous.size(); ++i){
        dijkstra_shortest_path(G, 0, previous);
        vector<int> path(extract_shortest_path({}, previous, i));
        print_path(path, calculate_cost(path, G));
    }
    // for (int val : value) cout << val;
    // cout << endl;
}