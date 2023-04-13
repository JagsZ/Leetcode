class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int index = 0;
        
        for(int i = 0; i < popped.size(); i++){
            if(st.empty() == false && st.top() == popped[i]){
                st.pop();
            }else{
                while(index < pushed.size()){
                
                    if(popped[i] != pushed[index]){
                        st.push(pushed[index]);
                    }else{
                        index++;
                        break;
                    }
                    index++;
                }
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};