class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int i = 0; i < asteroids.size(); i++){
            bool collision = false;
            /*collision condition- (asteroids[i] < 0 && st.top() > 0 */
            while(!st.empty() && asteroids[i] < 0 && st.top() > 0){
                
                /* case 1 - if prev asteroid is lesser than curr
                so prev asteroid will explode(prev < curr) and i will keep checking previous
                asteroid also*/
                if(st.top() < -asteroids[i]){
                    st.pop();
                    continue;
                /*case 2 - prev and curr asteroid are equals both will explode*/
                }else if(st.top() == -asteroids[i]){ 
                    st.pop();  
                    collision = true;
                    break;
                /* if prev asteroid is larger than curr so current asteroid will explode*/
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