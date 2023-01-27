472. Concatenated Words 

Code: 
class Solution {
public:
    set<string> s;
    bool checkConcatenate(string word){
        for(int i = 1; i < word.length(); i++){
            string prefixWord = word.substr(0,i); 
            string suffixWord = word.substr(i, word.length() - i);
            
            if(s.find(prefixWord) != s.end() && (s.find(suffixWord) != s.end() || checkConcatenate(suffixWord)))
            return true;
        }
        return false;

    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    vector<string> concatenateWords; 
    
    for(string word: words)
        s.insert(word);
    for(string word: words){
        if(checkConcatenate(word) == true)
        concatenateWords.push_back(word); 
        }
        return concatenateWords;
    }
};

// Time complexity: O(n^2*m) where n is the number of words in the input array and m is the average length of the words.


Code: Solution using dp. 
    
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> words_set;
        for (string word : words) words_set.insert(word);
        vector<string> res;
    
        for (string word : words) {
            int n = word.size();
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (!dp[i]) continue;
                for (int j = i + 1; j <= n; j++) {
                    if (j - i < n && words_set.count(word.substr(i, j - i))) {
                        dp[j] = 1;
                    }
                }
                if (dp[n]) {
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};

//Time complexity: The time complexity of this solution is O(n * L^2), where n is the number of words in the input list and L is the maximum length of the words.
