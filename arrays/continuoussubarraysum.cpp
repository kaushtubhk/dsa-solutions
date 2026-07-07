class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = -1;
        int prefix = 0;
        for(int i = 0 ; i < n ; i++){
            prefix += nums[i];
            int rem = prefix % k;
            if(mp.count(rem)){
                if(i - mp[rem] >= 2){ //check length of subarray more than 2 or not
                    return true;
            

                }else{
                    mp[rem] = i; //store rem
                }
            }
        }
        return false;

        
    }
};
//TC = O(n)
//SC = O(n)