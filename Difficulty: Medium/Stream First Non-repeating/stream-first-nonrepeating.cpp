class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        queue<char>q;
        vector<int>v(26,0);
        
        for(int i=0;i<s.size();i++){
            
           
            v[s[i]-'a']++;         
            if(v[s[i]-'a']==1)q.push(s[i]);
            
            while(!q.empty() && v[q.front()-'a']!=1){
                q.pop();
            }
            
            if(q.empty())s[i] = '#';
            else s[i] = q.front();
        }
        
        return s;
    }
};