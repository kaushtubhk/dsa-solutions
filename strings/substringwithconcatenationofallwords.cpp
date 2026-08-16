class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans ;
        int n = s.size() ;
        int k = words[0].size() ;
        int l = words.size() ;
        int totalLen = k*l ;

        if(totalLen > n){
            return ans ;
        }
        unordered_map<string , int> freq ;
        for(int i = 0 ; i < k ; i++){
            int left = i ;
            int count = 0 ;

            unordered_map<string , int> window ;
            for(string word : words){
                freq[word]++ ;
            }
            for( int j = i ; j <= n-k ; j += k){
                string word = s.substr(j,k);
                if(freq[word]){
                    window[word]++ ;
                    count++;
                    while(window[word] > freq[word]){
                        string leftword = s.substr(left , k);
                        window[leftword]-- ;
                        count-- ;
                        left += k ;
                    }
                    if(count == l){
                        ans.push_back(left) ;
                    }
                }else{
                    window.clear() ;
                    count = 0 ;
                    left = j+k ;
                }
            }
        }
        return ans ;
        
    }
};