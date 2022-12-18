class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
   
   stack<int> index;
        vector<int> result(temperatures.size(),0);
        index.push(0);
        for(int i=1;i<temperatures.size();i++){
            int element = temperatures[i];
            while(!index.empty() && element>temperatures[index.top()]){
                result[index.top()] = i-index.top();
                index.pop();
            }
            
            index.push(i);
        }
        
        return result;
    }
};