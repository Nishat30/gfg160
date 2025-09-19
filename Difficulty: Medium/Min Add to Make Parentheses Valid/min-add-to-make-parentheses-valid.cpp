class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int open = 0;
        int close = 0;
        // increment and descrement based on the condition for each and every char
        for(char cha : s){
            if(cha=='('){
                open++;
            } else if(cha ==')'){
                
                //check
                if(open>0){
                    open--;
                } else{
                    close++;
                }
            }
        }
        return open+close;
    }
};