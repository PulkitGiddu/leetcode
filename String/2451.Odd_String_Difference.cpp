Q - Odd String difference. 

code1: 
class Solution{
    public: 
    string oddString(vector<string>& words){
        map<vector<int>, vector<string>> m;
        for(auto word: words){
            vector<int> arr; // creating temporary array for storing the difference
            for(int i = 1; i<word.size(); i++){
                arr.push_back((int)word[i]- (int)word[i - 1]); //converting char value and taking difference.
            }
            m[arr].push_back(word);
        }
        for(auto it: m){
            if(it.second.size() == 1)return it.second[0];
        }
        return "";
    }
};

code2:   
class Solution {
public:
    string oddString(vector<string>& a) {
    int sz = a.size();
    int n = a[0].size();
        map<vector<int>, int> ans;
        for(int i = 0; i<sz; i++){
            vector<int> temp;
            for(int j  = 1; j<n; j++){
                temp.push_back(a[i][j]- a[i][j-1]);
            }
            ans[temp]++;
        }
        vector<int> temps;
        for(auto i : ans )
            if(i.second == 1)
                temps = i.first;
        for(int i = 0; i<sz; i++){
            vector<int>temp;
            for(int j = 1; j<n; j++){
                temp.push_back(a[i][j] - a[i][j - 1]);
            }
            if(temp == temps)
                return(a[i]);
        }
        return(a[0]);
    }
};
