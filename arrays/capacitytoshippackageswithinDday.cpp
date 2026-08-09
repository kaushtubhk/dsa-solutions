class Solution {
public:
    bool canShip(vector<int>& weights , int days, int capacity){
        int day = 1 ;
        int load = 0 ;

        for(int w : weights){
            if(load + w > capacity){
                day++ ;
                load = 0 ;
            }
            load += w ;
        }
        return day <= days ;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin() , weights.end());
        int right = accumulate(weights.begin() , weights.end() , 0) ;
        int result = -1 ;

        while(left <= right){
            int mid = left + (right - left)/2 ;

            if(canShip(weights , days ,mid)){
                result = mid ;
                right = mid - 1 ;
            }else{
                left = mid + 1 ;
            }
        }
        return result ; 
        
    }
};