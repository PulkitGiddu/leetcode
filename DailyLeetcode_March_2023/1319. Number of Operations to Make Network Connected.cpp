class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src){
        // normal dfs 
        visited[src] = true;
        for(int i : adj[src])
            if(!visited[i])
                dfs(adj, visited, i);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1; // if no of wires is less than n-1 then its not possible.
        
        // making an graph 
        vector<vector<int>> adj(n);
        for(auto c : connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        vector<bool> visited(n, false); // keeping visited to only visit an node once. 
        
        // Counting total no of connected components by dfs on every non visited element 
        int components = 0;
        for(int i=0; i<n; i++)
            if(!visited[i]){
                dfs(adj, visited, i);

                components++; // In one dfs visit all nodes in that component so ++ one component added 
            }

        return components - 1; 
    }
};
