2300. Successful Pairs of Spells and Potions

Code: 
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end()); 

        vector<int> res; 
        for(int spell : spells){
            long potions_needed = (success + spell - 1)/spell;
            auto it = lower_bound(potions.begin(), potions.end(), potions_needed);
            res.push_back(potions.end() - it); 

        }
        return res; 
    }
};
