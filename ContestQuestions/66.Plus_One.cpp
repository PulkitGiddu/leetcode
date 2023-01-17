66. Plus One

Code: 

class Solution{
public: 
vector<int> plusOne(vector<int>& d){
    int n = d.size() -1; 
    for(int i = n; i>= 0; --i){
        if(d[i] == 9){
            d[i] = 0;
        }
        else{
            d[i] += 1;
            return d;
        }
    }
    d.push_back(0);
    d[0] = 1;
    return d;
}
};
