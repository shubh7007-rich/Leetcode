class Solution {
public:
    int summ(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n /= 10;
        }

        return sum;
    }

    int minS(vector<int>& nums , unordered_map<int ,int>& ind){
        int swaps = 0 , n = nums.size();

        vector<bool> vis(n , false);

        for(int i = 0 ; i < n ; i++){
            if(vis[nums[i]] || ind[nums[i]] == i) continue;

            int c = 0 , j = nums[i];

            while(!vis[j]){
                c++;
                vis[j] = true;
                j = nums[j];
            }

            if(c > 1) swaps += (c-1);
        }

        return swaps;
    }
    int minSwaps(vector<int>& nums ) {
        vector<pair<int , int>> arr;

        for(int & num : nums){
            arr.push_back({summ(num) , num});
        }

        sort(arr.begin() , arr.end());

        unordered_map<int , int> ind;

        for(int i = 0 ; i < nums.size() ; i++){
            ind[arr[i].second] = i;
        }

        for(int  i = 0 ; i < nums.size() ; i++){
            nums[i] = ind[nums[i]];
        }

        return minS(nums , ind);
    }
};