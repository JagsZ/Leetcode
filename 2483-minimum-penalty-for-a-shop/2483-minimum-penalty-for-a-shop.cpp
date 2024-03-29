class Solution {
public:
    int bestClosingTime(string customers) {
          // Start with closing at hour 0, the penalty equals all 'Y' in closed hours.
        int curPenalty = count(customers.begin(), customers.end(), 'Y');
        int minPenalty = curPenalty;
        int earliestHour = 0;

        for (int i = 0; i < customers.size(); i++) {
            char ch = customers[i];
            
            // If status in hour i is 'Y', moving it to open hours decrement
            // penalty by 1. Otherwise, moving 'N' to open hours increment
            // penatly by 1.
            if (ch == 'Y') {
                curPenalty--;
            } else {
                curPenalty++;
            }

            // Update earliestHour if a smaller penatly is encountered.
            if (curPenalty < minPenalty) {
                earliestHour = i + 1;
                minPenalty = curPenalty;
            }
        }

        return earliestHour;
    
    }
};