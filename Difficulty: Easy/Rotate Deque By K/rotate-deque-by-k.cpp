class Solution {
  public:
    void clockwiseRotation(deque<int>& dq, int k){
        for(int i=0; i<k; i++){
            int el = dq.back();
            dq.pop_back();
            dq.push_front(el);
        }
    }

    void anticlockwiseRotation(deque<int>& dq, int k){
        for(int i=0; i<k; i++){
            int el = dq.front();
            dq.pop_front();
            dq.push_back(el);
        }
    }
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
         int n = dq.size();

        k = k%n;

        if(k == 0){
            return;
        }

        if(type == 1){
            clockwiseRotation(dq, k);

        }else if(type == 2){
    
            anticlockwiseRotation(dq, k);
        }

        return;
    }
};