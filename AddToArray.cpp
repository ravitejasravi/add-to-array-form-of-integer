class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int carry = 0;

        for(int i = num.size() - 1; i >= 0 ; i--) {
            int temp = num[i] + (k % 10) + carry;

            if(temp > 9){
                carry = 1;
                num[i] = temp % 10;
            }
            else {
                carry = 0;
                num[i] = temp;
            }
               
            k = k / 10;
        }
        
        if(carry == 1 && k != 0) {
            int temp = carry + (k % 10);

            if(temp > 9) {
                carry = 1;
                temp = temp % 10;
            }
            else {
                carry = 0;
            }
            
            num.insert(num.begin() + 0, temp);
            k = k / 10;
        }
        else if(carry == 1) {
            num.insert(num.begin() + 0, carry);
            carry = 0;
        }
        
        while( k != 0) {
            int inter = 0;
            
            int temp = carry + (k % 10);

            if(temp > 9){
                carry = 1;
                inter = temp % 10;
            }
            else {
                carry = 0;
                inter = temp;
            }

            num.insert(num.begin() + 0, inter);
            k = k / 10;
        }

        if(carry == 1) {
            num.insert(num.begin() + 0, carry);
        }
            
        return num;
    }
};