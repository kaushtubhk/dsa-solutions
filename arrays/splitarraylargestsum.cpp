class Solution {
public:
    bool canSplit(vector<int>& nums, int k , int maxSum){
        int parts = 1 ;
        int currSum = 0 ;

        for(int num: nums){
            if(currSum + num > maxSum){
                parts++ ;
                currSum = 0 ;
                if(parts > k){
                    return false ;
                }
            }
            currSum += num ;
        }
        return parts <= k ;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size() ;
        int left = *max_element(nums.begin() , nums.end()) ;
        int right = 0 ;

        for(int num : nums){
            right += num ;
        }
        int result = -1 ;

        while(left <= right){
            int mid = left + (right - left)/2 ;

            if(canSplit(nums , k , mid)){
                result = mid ;
                right = mid - 1 ;
            }else{
                left = mid + 1 ;
            }
        }
        return result ;
    }
};