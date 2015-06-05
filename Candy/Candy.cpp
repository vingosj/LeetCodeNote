#include <map>

//   2015-6-4

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), result = 0;
        if(n == 0) return result;
        
        map<int, vector<int>> m;
        vector<int> can(n);
        
        for(int i = 0; i < n; i++){
            auto iter = m.find(ratings[i]);
            if(iter != m.end()){
                iter->second.push_back(i);
            }
            else{
                vector<int> entry(1, i);
                m[ratings[i]] = entry;
            }
        }
        
        for(auto s : m){
            for(int i : s.second){
                int value = 0;
                if(i != 0 && can[i-1] != 0 && ratings[i] > ratings[i-1]) value = can[i-1];
                if(i != n-1 && can[i+1] != 0 && ratings[i] > ratings[i+1]) value = value > can[i+1] ? value : can[i+1];
                can[i] = value + 1;
                result += can[i];
            }
        }
        
        return result;
    }
};