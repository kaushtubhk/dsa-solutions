class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int count = 0;
        int sum = 0;

        for(int num : nums){
            
            sum += num ;
            int rem = ((sum % k) + k) % k ; //fix negative values

            if(mp.count(rem)){ // same remainder phle aaya tha ?
                count += mp[rem];
            }
            mp[rem]++ ; // add current remainder

        }
        return count;

        
    }
};
//TC = O(n)
//SC = O(k) use hashmap