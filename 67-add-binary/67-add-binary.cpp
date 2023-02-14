class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, index = 0, bit = 0;
        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while(index < a.length() && index < b.length()){
            if(a[index] == '1' && b[index] == '1'){
                bit = carry;
                carry = 1;
            }else{
                bit = (a[index]-'0') ^ (b[index] - '0') ^ carry;
                if(((a[index]-'0') ^ (b[index]-'0')) && carry)
                    carry = 1;
                else 
                    carry = 0;
            }
            ans = to_string(bit) + ans;
            index++;
        }
        while(index < a.length()){
            if(a[index] == '1' && carry){
                bit = ((a[index]-'0') ^ carry);
                carry = 1;
            }else{
                bit = ((a[index]-'0') ^ carry);
                carry = 0;
            }
            ans = to_string(bit) + ans;
            index++;
        }
        while(index < b.length()){
            if(b[index] == '1' && carry){
                bit = ((b[index]-'0') ^ carry);
                carry = 1;
            }else{
                bit = ((b[index]-'0') ^ carry);
                carry = 0;
            }
            index++;
            ans = to_string(bit) + ans;
        }
        if(carry){
            ans = to_string(carry) + ans;
        }
        return ans;
        
    }
};