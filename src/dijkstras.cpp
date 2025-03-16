#include "dijkstras.h"
#include <utility>

int calculate_cost(const vector<int>& path, const Graph& G){
    int total = 0;
    for (int i = 0; i < (int)path.size() - 1; ++i){
        for (Edge e : G[path[i]]){
            if (e.dst == path[i + 1]){
                total += e.weight;
                break;
            }
        }
    }
    return total;
}

void print_path(const vector<int>& v, int total){
    for (int val : v) cout << val << ' ';
    cout << endl << "Total cost is " << total << endl;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination){
    vector<int> res;
    int current = destination;
    stack<int> temp;
    while (current != 0){
        temp.push(previous[current]);
        current = previous[current];
    }
    while (!temp.empty()){
        res.push_back(temp.top());
        temp.pop();
    }
    res.push_back(destination);
    return res;
}

vector<int>& dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int n = G.size();
    vector<int> dist{n};
    previous.assign(n, -1);
    previous[source] = 0;
    vector<bool> visited(n);
    visited.assign(n, false);
    dist.assign(n, std::numeric_limits<int>::max());
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>> > pq;
    
    pq.push(pair{0, source});
    dist[source] = 0;
    
    while (!pq.empty()){
        pair current = pq.top(); pq.pop();
        int u = current.second; // vertex
        if (visited[u]) continue;
        visited[u] = true;
        for (Edge edge : G[u]){
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                previous[v] = u;
                pq.push(pair{dist[v], v});
            }
        }
    }
    return previous;

    
}