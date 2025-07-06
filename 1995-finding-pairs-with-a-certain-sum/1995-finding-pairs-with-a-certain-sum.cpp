class FindSumPairs {
public:
    vector<int> n1 , n2;
    map<int , int> mp1 , mp2;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        // i can sort nums1
        // so for every index in num2 i can find 
        for(int i : nums1){
            n1.push_back(i);
            mp1[i]++;
        }
        for(int i : nums2){
            n2.push_back(i);
            mp2[i]++;
        }
        sort(n1.begin() , n1.end());
    }
    
    void add(int index, int val) {
        mp2[n2[index]]--;
        n2[index] += val;
        mp2[n2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        
        for(auto [num , freq] : mp1){
            int tar = tot - num;

            if(tar < 0) continue;

            if(mp2.find(tar) != mp2.end()){
                cnt += (freq * mp2[tar]);
            }
        }

        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */