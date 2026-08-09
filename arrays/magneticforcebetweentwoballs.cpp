class Solution {
public:
    bool canPlace(vector<int>& pos , int m , int minDist){
        int balls = 1 ;
        int lastPos = pos[0] ;

        for(int i = 1 ; i < pos.size() ; i++){
            if(pos[i] - lastPos >= minDist){
                balls++ ;
                lastPos = pos[i];
            }
            if(balls == m){
                return true ;
            }
        }
        return false;

    }
    int maxDistance(vector<int>& pos, int m) {
        int n = pos.size() ;
        sort(pos.begin() , pos.end()) ;
        int left = 1 ; 
        int right = (pos[n-1] - pos[0])/(m-1) ;

        int result = -1 ;
        while(left <= right){
            int mid = left + (right - left)/2 ;

            if(canPlace(pos , m , mid)){
                result = mid ;
                left = mid + 1 ;

            }else{
                right = mid - 1 ;
            }
        }
        return result;
        
    }
};