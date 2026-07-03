#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        
        // 1. Build adjacency list and in-degrees for topological sort
        // We only consider edges where both endpoints are online
        vector<vector<pair<int, int>>> adj(n);
        vector<int> in_degree(n, 0);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            
            if (online[u] && online[v]) {
                adj[u].push_back({v, cost});
                in_degree[v]++;
            }
        }
        
        // 2. Compute Topological Order
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) q.push(i);
        }
        
        vector<int> topo_order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo_order.push_back(u);
            
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                if (--in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // Helper lambda function to check feasibility for a given target score
        auto check = [&](int mid) -> bool {
            vector<long long> dist(n, -1); // -1 representing infinity/unreachable
            dist[0] = 0;
            
            for (int u : topo_order) {
                if (dist[u] == -1) continue;
                
                for (const auto& edge : adj[u]) {
                    int v = edge.first;
                    int cost = edge.second;
                    
                    // Only traverse paths that meet the bottleneck score criteria
                    if (cost >= mid) {
                        if (dist[v] == -1 || dist[u] + cost < dist[v]) {
                            dist[v] = dist[u] + cost;
                        }
                    }
                }
            }
            return dist[n - 1] != -1 && dist[n - 1] <= k;
        };
        
        // 3. Binary Search over potential minimum edge weights
        int low = 0, high = 1e9;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;       // Try to find a larger minimum edge cost
                low = mid + 1;
            } else {
                high = mid - 1;  // Relax requirements to find a valid path
            }
        }
        
        return ans;
    }
};