class Solution {
public:
    int cnt = 0;

    void merge(int lb , int mid , int ub , vector<int>& nums){
        int p1 = lb , p2 = mid + 1;

        vector<int> copy;
        int i = lb , e = mid + 1;
        while(i <= mid && e <= ub){
            if(nums[i] >   2 *(long)1* nums[e]){
                cnt += (mid - i + 1);
                e++;
            }else{
                i++;
            }
        }

        while(p1 <= mid && p2 <= ub){
            if(nums[p1] <= nums[p2]){
                copy.push_back(nums[p1]);
                p1++;
            }else{
                copy.push_back(nums[p2]);
                p2++;
            }
        }

        while(p1 <= mid){
            copy.push_back(nums[p1]);
            p1++;
        }
        while(p2 <= ub){
            copy.push_back(nums[p2]);
            p2++;
        }

        for(int i = lb ; i <= ub ; i++){
            nums[i] = copy[i - lb];
        }
    }

    void mergeS(int lb , int ub , vector<int>& nums){
        if(lb < ub){
            int mid = lb + (ub - lb)/2;

            mergeS(lb , mid , nums);
            mergeS(mid + 1 , ub , nums);
            merge(lb , mid , ub , nums);
        }
    }
    int reversePairs(vector<int>& nums) {
        int lb = 0 , ub = nums.size() - 1;
        mergeS(lb , ub , nums);
        return cnt;
    }
};