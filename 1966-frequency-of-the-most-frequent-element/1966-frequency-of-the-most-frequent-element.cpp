#define ll long long
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        /* 
            we have total of k operations so , and we can only add 1 to a particular number that means we can only increase a particular number , so if we sort our array then for a number num , we can only convert the numbers on the left to num 

            and we can check how many numbers we can convert to num , like
            for ex - [1 , 2 , 4 , 7 , 9]
                      i       j
            if i am standing at num = 4 , so if i want to convert all the number to the left of num to num, i can calculate the number of operations easily 
            new sum = num * (j-i+1) = 4 * (3) = 12
            old sum = 1 + 2 + 4 = 7
            operations required = new sum - old sum = 12 - 7 = 5 , so if op <= k , then we can expand the windom 

            take l = 0 , r = num's index , if possible for mid , we shift mid to the left else we shift mid to right

            so we need old sum , so we will use prefix sum
        */
        sort(nums.begin() , nums.end());

        int n = nums.size();
        vector<ll> psum(n , 0);
        psum[0] = nums[0];

        for(int i = 1 ; i < nums.size() ; i++){
            psum[i] = nums[i] + psum[i-1];
        }

        int maxi = 0;

        for(int j = 0 ; j < n ; j++){
            ll num = nums[j];

            int l = 0 , r = j ;

            while(l <= r){
                int mid = (l+r)/2;

                bool flag = false;

                ll new_sum = num * (j-mid+1);
                ll old_sum;

                if(mid == 0){
                    old_sum = psum[j];
                }else{
                    old_sum = psum[j] - psum[mid - 1];
                }

                ll op = new_sum - old_sum;

                if(op <= k){
                    maxi = max(maxi , j-mid+1);
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
        }

        return maxi;
    }
};