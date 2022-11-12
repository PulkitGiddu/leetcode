Q - 622. Design Circular Queue 
Code: 
// Time Complexity: O(1)
// Space Complexity: O(N)
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        // the queue holding the elements for the circular queue
        q.resize(k);
        // the number of elements in the circular queue
        cnt = 0;
        // queue size
        sz = k;
        // the idx of the head element
        headIdx = 0;
    }
    
    bool enQueue(int value) {
        // handle full case
        if (isFull()) return false;
        q[(headIdx + cnt) % sz] = value;
        // increase the number of elements by 1
        cnt += 1;
        return true;
    }
    
    bool deQueue() {
        // handle empty case
        if (isEmpty()) return false;
        // update the head index
        headIdx = (headIdx + 1) % sz;
        // decrease the number of elements by 1
        cnt -= 1;
        return true;
    }
    
    int Front() {
        // handle empty queue case
        if (isEmpty()) return -1;
        // return the head element
        return q[headIdx];
    }
    
    int Rear() {
        // handle empty queue case
        if (isEmpty()) return -1;
        return q[(headIdx + cnt - 1) % sz];
    }
    
    bool isEmpty() {
        // no element in the queue
        return cnt == 0;
    }
    
    bool isFull() {
        // return true if the count is equal to the queue size
        // else return false
        return cnt == sz;
    }
    
private:
    int cnt, sz, headIdx;
    vector<int> q;
};
