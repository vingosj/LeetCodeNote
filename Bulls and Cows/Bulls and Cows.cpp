class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0 , n = secret.size();
        if(n == 0) return "0A0B";
        map<char, int> bits;
        char c = '0';
        
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]){
                bulls++;
                continue;
            }
            c = secret[i];
            if(bits.count(c) == 0) bits[c] = 1;
            else bits[c]++;
        }
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]) continue;
            c = guess[i];
            if(bits.count(c) == 1 && bits[c] > 0){
                cows++;
                bits[c]--;
            }
        }
        
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};