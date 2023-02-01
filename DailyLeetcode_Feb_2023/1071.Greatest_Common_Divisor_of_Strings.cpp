1071. Greatest Common Divisor of Strings

Concatenate the two strings in two different orders: str1+str2 and str2+str1.
Compare the two concatenated strings.
If the two concatenated strings are equal, then the two original strings share a common prefix.
Find the greatest common divisor of the lengths of the two strings.
Use the GCD as the length of the common prefix and return it using str1.substr(0, gcd(str1.length(), str2.length())).
If the two concatenated strings are not equal, then there is no common prefix, so return an empty string.

Code1:

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 == str2 + str1){
            return str1.substr(0, gcd(str1.length(), str2.length()));
        }
        return "";
    }
};

Code2: 

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size()) {
            swap(str1, str2);
        }
        int n = str2.size();
        for (int i = n; i >= 1; --i) {
            if (n % i != 0) continue;
            string sub = str2.substr(0, i);
            if (check(sub, str1) && check(sub, str2)) {
                return sub;
            }
        }
        return "";
    }
    
    bool check(string sub, string str) {
        int n = str.size(), m = sub.size();
        if (n % m != 0) return false;
        for (int i = 0; i < n; i += m) {
            if (str.substr(i, m) != sub) {
                return false;
            }
        }
        return true;
    }
};

