class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
//         int area1=abs(ax2-ax1)*abs(ay1-ay2);
//         int area2=abs(bx2-bx1)*abs(by1-by2);
        
//         int x1=max(ax1,bx1);
//         int y1=max(ay1,by1);
//         int x2=min(ax2,bx2);
//         int y2=min(ay2,by2);
        
//         int area=abs(x2-x1)*abs(y1-y2);
        
//         if(bx2-ax1<0 || bx1-ax2>0 || by1-ay2>0 || ay1-by2>0)
//             return area1+area2;
//         return area1+area2-area;
        
        
        int area1=abs(ax2-ax1)*abs(ay1-ay2);
        int area2=abs(bx2-bx1)*abs(by1-by2);
        
        int x1=max(ax1,bx1);
        int y1=max(ay1,by1);
        int x2=min(ax2,bx2);
        int y2=min(ay2,by2);
        
        int area=abs(x2-x1)*abs(y1-y2);
        if(x2>x1 && y2>y1)
             return area1+area2-area;
        return area1+area2;
        
    }
};