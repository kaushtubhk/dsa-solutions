class Solution {
public:
    bool canArrive(vector<int>& dist , double hour , long long speed){
        double time = 0.0;
        int n = dist.size();

        for(int i = 0 ; i < n-1 ; i++){
            time += ((long long)dist[i] + speed - 1) /speed;

            
        }
        time += (double)dist[n-1]/speed ;
        return time <= hour  ;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();

        if(hour <= n-1){
            return -1;
        }
        long long left = 1;
        long long right = 1e7 ;
        long long  result = -1 ;

        while(left <= right){
            long long mid = left + (right - left)/2 ;
            if(canArrive(dist , hour , mid)){
                result = mid ;
                right = mid - 1 ;
            }else{
                left = mid + 1 ;
            }
        }
        return result ;

        
    }
};