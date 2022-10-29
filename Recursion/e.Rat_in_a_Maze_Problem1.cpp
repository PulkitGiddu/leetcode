Q - Rat in a Maze Problem - I
code:
class Solution{
    private: 
    bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &m ){
        if((x >= 0 && x < n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1 ){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(vector<vector<int>> &m, int n , vector<string>& ans, int x, int y, vector<vector<int>> visited, string path){
        // you have reached x, y
        // base case
        if( x == n-1 && y == n-1 ){
            ans.push_back(path);
            return; 
        }
        visited[x][y] = 1;
        
        // we have 4 choices = D, L , R , U
        
        // down
        int newx = x + 1;
        int newy = y;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('D');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        
        // left
        newx = x;
        newy = y - 1 ;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('L');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        
        // Right
        newx = x;
        newy = y + 1;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('R');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        
        // up
        newx = x - 1;
        newy = y;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('U');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
    
        visited[x][y] = 0;
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans; 
        if(m[0][0] == 0)
        {
                return ans;
        }
        
        int srcx = 0; 
        int srcy = 0;
        
        vector<vector<int>> visited = m; 
        // initialize with 0
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                visited[i][j] = 0; 
            }
        }
        string path = ""; 
        solve(m, n, ans, srcx, srcy, visited, path);
        sort(ans.begin(), ans.end());
        return ans; 
    }
};


Code: 
class Solution {
  void findPathHelper(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
    vector < vector < int >> & vis) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }

    // downward
    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
      vis[i][j] = 1;
      findPathHelper(i + 1, j, a, n, ans, move + 'D', vis);
      vis[i][j] = 0;
    }

    // left
    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j - 1, a, n, ans, move + 'L', vis);
      vis[i][j] = 0;
    }

    // right 
    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j + 1, a, n, ans, move + 'R', vis);
      vis[i][j] = 0;
    }

    // upward
    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
      vis[i][j] = 1;
      findPathHelper(i - 1, j, a, n, ans, move + 'U', vis);
      vis[i][j] = 0;
    }

  }
  public:
    vector < string > findPath(vector < vector < int >> & m, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));

      if (m[0][0] == 1) findPathHelper(0, 0, m, n, ans, "", vis);
      return ans;
    }
};
