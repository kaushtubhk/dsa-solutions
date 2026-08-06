class Solution {
public:
    int calculateHours(vector<int>& piles , int k){
        int hours = 0;
        for(int pile : piles){
            hours += (pile + k - 1 ) / k ;
        }
        return hours ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1 ;
        int right = *max_element(piles.begin(), piles.end()) ;
        int ans = right ;

        while(left <= right){
            int mid = left + (right - left)/2 ;
            int hours = calculateHours(piles,mid) ;

            if(hours <= h){
                ans = mid ;
                right = mid - 1 ;
            }else{
                left = mid + 1 ;
            }
        }
        return ans ;

        
    }
};