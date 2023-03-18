1472. Design Browser History

Code: 
class BrowserHistory {
public:

    vector<string> history;
    int curr = 0;

    BrowserHistory(string homepage) {
        history.push_back(homepage); 
        curr = 0; 
    }
    
    void visit(string url) {
        history.erase(history.begin() + curr + 1, history.end());
        history.push_back(url);
        curr++;
    }
    
    string back(int steps) {
        curr = max(0, curr - steps);
        return history[curr];
    }
    
    string forward(int steps) {
        curr = min((int)history.size()-1, curr + steps);
        return history[curr];
    }
};
