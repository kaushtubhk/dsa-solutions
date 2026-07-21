class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size() ; 
        long long maxSum = 0 ;
        long long currSum = 0 ; 

        unordered_map<int,int> mp;
        int left = 0;
        for(int right =  0 ; right < n ; right++){
            mp[nums[right]]++; //add right element
            currSum += nums[right];

            if(right - left + 1 == k){ //window size = k
                if(mp.size() == k){ // having k distinct elements
                    maxSum = max(maxSum , currSum);
                }
                currSum -= nums[left]; //remove left element
                mp[nums[left]]-- ;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                    
                }
                left++;
            }
        }
        return maxSum;    


        
    }
};
//TC = O(n)
//SC = O(k)