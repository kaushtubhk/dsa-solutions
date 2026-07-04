class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> prefixCount;
        prefixCount[0] = 1;//empty prefix (sum = 0) ek baar exist krta hai
        int currSum = 0;
        int count = 0;

        for(int num : nums){
            currSum += num;
            int needed = currSum - k;
            if(prefixCount.count(needed)){
                count += prefixCount[needed];
            }
            prefixCount[currSum]++;
        }
        return count;

        
    }
};
//TC = O(n)
//SC = O(n) use hashmap