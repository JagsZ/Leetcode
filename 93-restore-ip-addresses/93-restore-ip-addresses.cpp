class Solution {
   
    void solve(int start, string s, vector<string> &snip, vector<string> &ip_list){
        
        if(snip.size() == 4 && start == s.length()){
            string ip = snip[0] + "." + snip[1] + "." + snip[2] + "." + snip[3]; 
            ip_list.push_back(ip);
        }else if(snip.size() == 4 || start == s.length()){
            return;
        }

        for(int len = 1; len < 4 && (start+len) <= s.length(); len++){

            // choice
            string str = s.substr(start, len);

            // constraint
            if( (stoi(str) > 255) || (str.size() > 1 && str[0] == '0') )
                break;

            snip.push_back(s.substr(start, len));
            solve(start+len, s, snip, ip_list);
            snip.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ip_list;
        vector<string> snip;
        solve(0, s, snip, ip_list);
        return ip_list;
    }
};