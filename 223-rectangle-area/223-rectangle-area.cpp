class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int ract1_width = abs(ax2 - ax1);
        int ract1_height = abs(ay2 - ay1);
        int ract1_area =  (ract1_width*ract1_height);
        
        int ract2_width = abs(bx2 - bx1);
        int ract2_height = abs(by2 - by1);
        int ract2_area =  (ract2_width * ract2_height);
        
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int x_common = (right - left);
        
        int top = min(ay2, by2);
        int bottom = max(ay1, by1);
        int y_common = top - bottom;
        
        int common_area = 0;
        if(x_common > 0 && y_common > 0)
            common_area = (x_common * y_common);
        
        return (ract1_area + ract2_area) - common_area;
        
    }
};