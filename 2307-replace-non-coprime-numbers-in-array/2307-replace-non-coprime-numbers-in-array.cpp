class Solution {
public:
    int lcm(int a , int b){
        return ((a / gcd(a,b)) * b);
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        // ans.push_back(nums[0

        for(int num : nums){
            ans.push_back(num);

            while(ans.size() > 1){
                int b1 = ans.back();
                int b2 = ans[ans.size()-2];

                int g = gcd(b1 , b2);

                if(g == 1) break;

                ans.pop_back();
                ans.pop_back();

                ans.push_back(lcm(b1 , b2));
            }
        }

        return ans;
    }
};