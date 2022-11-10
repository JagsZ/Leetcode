/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int  celebrity = 0;
        for(int i = 0; i < n; i++){
            if(celebrity != i && knows(celebrity, i)){
                celebrity = i;
            }
        }
        for(int j = 0; j < n; j++){
            if(celebrity != j){
                if(!knows(j, celebrity) || knows(celebrity, j))
                    return -1;
            }
        }
        return celebrity;
    }
};