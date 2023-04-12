class Solution {
public:
    string simplifyPath(string path) {
    
        string tmp = "";
        stack<string> st;
        stringstream ss(path);
        string token = "";
        
        while(getline(ss, token, '/')){
            if(token != "." && token != "" && token != ".."){
                st.push(token);
            }else{
                if(token == ".." && st.empty() == false){
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            tmp = st.top() + tmp;
            tmp = "/" + tmp;
            st.pop();
        }
        return tmp != ""? tmp : "/";
    }
};