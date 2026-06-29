class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()){
            return 0;
        }
        int slow = 0;
        for(int fast = 1 ; fast < n ; fast++){
            if(nums[fast] != nums[slow]){
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1 ;
        
    }
};
//TC = O(n)
//SC = O(1)