Q -692. Top K Frequent Words
code: 
class Solution {
public:
    static bool comp(pair<int, string> &a, pair<int, string> &b){
        if(a.first != b.first) return a.first>b.first;
        else return a.second<b.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map <string, int > mp; 
         for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
         vector<pair<int, string>> q;
         for(auto &it : mp){
             q.push_back({it.second,it.first});
         }
        sort(q.begin(), q.end(), comp);
        vector<string> ans;
        for(int i = 0; i<q.size(); i++){
            if(k){
                ans.push_back(q[i].second);
                k--;
            }
        }
        return ans;
        
    }
};

Code2: 
