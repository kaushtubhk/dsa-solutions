class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0 ;
        int right = nums.size() - 1 ;

        while(left <= right){
            int mid = left + (right - left)/2 ;

            if(nums[mid] == target){
                return mid ;
            }
            if(nums[left] <= nums[mid]){//check left sorted Left sorted half: search interval is [left, mid)
                if(nums[left] <= target && target < nums[mid]){//check is target in left ?
                    right = mid - 1 ;
                }else{
                    left = mid + 1 ;
                }
            }else{//check target in right ?
                if(nums[mid] < target && target <= nums[right]){ //Right sorted half: search interval is (mid, right]
                        left = mid + 1 ;
                }else{
                        right = mid - 1 ;
                }
            }    
            
        }
        return -1 ;
        
    }
};