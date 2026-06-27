class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxWater = 0;

        while(left < right){
            int h = min(height[left], height[right]);
            int w = right - left ;
            int area = w*h ;
            maxWater = max(maxWater , area);
              
            if(height[left] < height[right]){
                left++ ;

            }else{
            right-- ;
            }
        }
        return maxWater;


      
    }
}; //using two pointer approach and trapping rainwater is a similar problem but here we are finding the maximum area of water that can be contained between two lines. The time complexity is O(n) and space complexity is O(1).    