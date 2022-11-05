class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int i = 0; i < asteroids.size(); i++){
            bool collision = false;
            while(!st.empty() && asteroids[i] < 0 && st.top() > 0){
                
                if(st.top() < -asteroids[i]){
                    st.pop();
                    continue;
                }else if(st.top() == -asteroids[i]){
                    st.pop();  
                    collision = true;
                    break;
                }else{
                    collision = true;
                    break;
                }
            }
            if(collision == false)
                st.push(asteroids[i]);
        }
        int size = st.size();
        vector<int> ans(size, 0);
        while(!st.empty()){
            ans[size-1] = st.top();
            st.pop();
            size--;
        }
        return ans;
    }
};