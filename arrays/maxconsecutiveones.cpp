class Solution { //simple traversal
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxCount = 0;
        int count = 0;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 1){
                count++;
                maxCount = max(maxCount , count);
            }else{
                count = 0;
            }
        }
        return maxCount;

        
    }
};
//TC = O(n)
//SC = O(1) only two variables 