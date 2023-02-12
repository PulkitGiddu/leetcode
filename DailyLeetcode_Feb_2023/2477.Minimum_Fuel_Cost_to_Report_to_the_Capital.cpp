2477. Minimum Fuel Cost to Report to the Capital 

code: 

class Solution {
public:
    vector<vector<int>> edges; 
    vector<bool> visit; 
    long long ret = 0; 
    
    int count(int curr, int k){
        int cnt = 1;  // whereever you stand make that as 1. 
        visit[curr] = true; 
        for(auto i: edges[curr]){
            if(visit[i] == false)
            cnt += count(i,k);
        }
        if(curr != 0)
        ret += ((cnt + k - 1)/k);

        return cnt; 
        
    } 

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size(); 
        edges.resize(n+1);
        visit.resize(n+1);
        for(auto road: roads){
            edges[road[0]].push_back(road[1]);
            edges[road[1]].push_back(road[0]);
        }
        count(0, seats);
        return ret; 
    }
};
