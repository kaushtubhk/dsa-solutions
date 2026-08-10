class Solution {
public:
    bool canMake(vector<int>& bloomDay , int m , int k , int day){
        int consecutive = 0 ;
        int bouquets = 0 ;

        for(int bloom : bloomDay){
            if(bloom <= day){
                consecutive++ ;
                if(consecutive == k){
                    bouquets++ ;
                    consecutive = 0 ;
                }else{
                    consecutive = 0 ;
                }
            }
           
        }
        return bouquets >= m ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if((long long) m*k > n){
            return -1 ;
        }
        int left = 1 ;
        int right = *max_element(bloomDay.begin() , bloomDay.end()) ;
        int result = right ;

        while(left <= right){
            int mid = left + (right - left)/2 ;

            if(canMake(bloomDay, m , k , mid)){
                result = mid ;
                right = mid - 1 ;
            }else{
                left = mid + 1 ;
            }
        }
        return result ;
        
    }
};