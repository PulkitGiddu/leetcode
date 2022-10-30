Q - 17. Letter Combinations of a Phone Number
Code: 
class Solution {
private:
    void solve(string digits, string output, int index, vector<string>& ans, string mapping[]){
        // base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        
        // map kr do no ko with its value ie augar 2 hai toh  2 - abc sae mapp kr do
        int number = digits[index] - '0';
        string value = mapping[number]; 
        
        // loop run kro for putting elements into empty string
        for(int i = 0; i < value.length(); i++){
            // when moving downwards in recursive call 
            output.push_back(value[i]);
            // recursive call 
            solve(digits, output, index + 1, ans, mapping);
            // when calls are returning and moving to check next element then first we have to empty the string so that new element gets added
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if(digits.length() == 0) // if String is empty then we can return our ans. 
            return ans;
        
        string output; 
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans; 
    }
};

Code: 2 Iterative solution
/*
Explanation with sample input "123"

Initial state:

result = {""}
Stage 1 for number "1":

result has {""}
candiate is "abc"
generate three strings "" + "a", ""+"b", ""+"c" and put into tmp,
tmp = {"a", "b","c"}
swap result and tmp (swap does not take memory copy)
Now result has {"a", "b", "c"}
Stage 2 for number "2":

result has {"a", "b", "c"}
candidate is "def"
generate nine strings and put into tmp,
"a" + "d", "a"+"e", "a"+"f",
"b" + "d", "b"+"e", "b"+"f",
"c" + "d", "c"+"e", "c"+"f"
so tmp has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
swap result and tmp
Now result has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
Stage 3 for number "3":

result has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
candidate is "ghi"
generate 27 strings and put into tmp,
add "g" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
so, tmp has
{"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
"adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
"adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi" }
swap result and tmp
Now result has
{"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
"adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
"adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi" }
Finally, return result.
*/
class Solution {
public:
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
		vector<string> result;
        result.push_back("");
        
        for(auto digit: digits) {
            vector<string> tmp;
            for(auto candidate: pad[digit - '0']) {
                for(auto s: result) {
                    tmp.push_back(s + candidate);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};


Code3: using queue data structues 
class Solution {
public:
	//Method - 3 Queue
    vector<string> letterCombinations(string digits) {
    
        vector<string> phone={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
    if(digits.empty())
        return {};
    
        queue<string> q;
        vector<string> ans;
        
        q.push("");
        
        while(!q.empty())
        {
            string curr = q.front();
            q.pop();
            
            if(curr.length()==digits.length())
                ans.push_back(curr);
            else{
                string s = phone[digits[curr.length()] - '0'];
                for(auto x: s)
                    q.push(curr + x);
            }
            
        }
        return ans;
    }
};
