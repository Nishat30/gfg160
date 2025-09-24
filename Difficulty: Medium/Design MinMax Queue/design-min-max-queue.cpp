class SpecialQueue {

  public:
    deque<int> mini,maxi;
    vector<int> temp;
    int idx=0;
    void enqueue(int x) {
        // Insert element into the queue
        temp.push_back(x);
        while(!mini.empty() && temp[mini.back()] > x) mini.pop_back();
        mini.push_back(temp.size() - 1);
        
        while(!maxi.empty() && temp[maxi.back()] < x) maxi.pop_back();
        maxi.push_back(temp.size() - 1);
    }

    void dequeue() {
        // Remove element from the queue
        if(mini.front() == idx) mini.pop_front();
        if(maxi.front() == idx) maxi.pop_front();
        idx++;
    }

    int getFront() {
        // Get front element
        return temp[idx];
    }

    int getMin() {
        // Get minimum element
        return temp[mini.front()];
    }

    int getMax() {
        // Get maximum element
        return temp[maxi.front()];
    }
};