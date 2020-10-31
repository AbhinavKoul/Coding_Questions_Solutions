#include<math>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=height.size();
        int ini=0;
        int area=0;
        int fin=l-1;
        while (ini<fin){
            if (height[ini]<height[fin]){
                area=max(area,height[ini]*(fin-ini));
                ini+=1;
                }
            else{
                area=max(area,height[fin]*(fin-ini));
                fin-=1;
                }
          
        }
        return area;  
    }
};