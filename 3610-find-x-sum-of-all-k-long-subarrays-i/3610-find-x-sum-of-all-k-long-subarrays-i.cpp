class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int i = 0 , n = nums.size();

        unordered_map<int , int> freq;

        vector<int> ans;

        for(int j = 0 ; j < n ; j++){
            freq[nums[j]]++;

            if(j-i+1 == k){
                priority_queue<pair<int , int>> pq;

                for(auto & [num , f] : freq) pq.push({f , num});

                int temp = x , sum = 0;

                while(!pq.empty() && (temp--)){
                    auto p = pq.top();
                    pq.pop();

                    sum += (p.first * p.second);
                }

                ans.push_back(sum);

                freq[nums[i]]--;

                i++;
            }
        }

        return ans;
    }
};