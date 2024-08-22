void rec(int num, vector<int>& arr){
        int ind = 31;
        num = abs(num);
        while(num){
            int temp = num & 1;
            if(temp) arr[ind]++;
            num = num >> 1;
            --ind;
        }
    }
    int singleNumber(vector<int>& nums) {
        vector<int> arr(32, 0);
        int neg = 0, maxi = 0;
        for(auto a : nums){
            if(a < 0) ++neg;
            if(a == INT_MIN) ++maxi;
            else rec(abs(a), arr);
        } 
        int ans = 0, curr = 1;
        for(int i = 31; i >= 0; --i){
            if(arr[i] % 3 != 0) ans += curr;
            curr = curr << 1;
        }
        if(maxi % 3 != 0) return INT_MIN;
        if(neg % 3 != 0) ans *= -1;
        return ans;
    }
