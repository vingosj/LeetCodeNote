// 2016-1-16

class Solution {
public:
    bool check(string session){
        int n = session.size();
        if(n > 3 || (n > 1 && session[0] == '0')) return false;
        int num = stoi(session);
        if(num <= 255 && num >= 0) return true;
        else return false;
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> result;
        if(n < 4 || n > 12) return result;
        
        string p1, p2, p3, p4, ip;
        for(int x = 1; x <= n-3; x++)
            for(int y = x+1; y <= n-2; y++)
                for(int z = y+1; z <= n-1; z++){
                    p1 = s.substr(0, x);
                    p2 = s.substr(x, y-x);
                    p3 = s.substr(y, z-y);
                    p4 = s.substr(z, n-y);
                    if(check(p1) && check(p2) && check(p3) && check(p4)) {
                        ip = p1 + "." + p2 + "." + p3 + "." + p4;
                        result.push_back(ip);
                    }
                }
        return result;
    }
};