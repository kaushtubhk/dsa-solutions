class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currSum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < n ; i++){
            currSum = max(nums[i], currSum + nums[i]);

            maxSum = max(maxSum , currSum);
        }
       return maxSum;
    }

};
//TC = O(n)
//SC = O(1) only 2 variables 
//use kadane's algo (contiguous -> decide kro har idx p naya shuru kru ya pichle subarray ko extend kru)