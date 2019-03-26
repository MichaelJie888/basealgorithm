class Solution {
private:
    stack<int> s;
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int po=0;
        int i=0;
        while(i<pushed.size()) {
            if(pushed[i]!=popped[po] && !s.empty() && s.top()==popped[po]) {
                s.pop();
                po++;
            }else if(pushed[i]!=popped[po] ){
                s.push(pushed[i]);
                i++;
            }else if(pushed[i]==popped[po]){
                i++;
                po++;
            }
        }
        while(po<popped.size() && !s.empty()){
            if(s.top()==popped[po]){
                po++;
                s.pop();
            }else{
                return false;
            }
        }
        return true;
    }
};