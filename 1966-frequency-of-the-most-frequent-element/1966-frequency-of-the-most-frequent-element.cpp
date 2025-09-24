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


            and instead of using binary search to find the starting point of the window , we can just solve this question using sliding window , we can maintain a window from i to j , and check cost i.e number of operations for that window , if the number of operations are greater than k then we shrink the window , else just increase the j
            
        */
        sort(nums.begin() , nums.end());

        int n = nums.size();
        vector<ll> psum(n+1, 0);
        psum[0] = nums[0];

        for(int i = 1 ; i < nums.size() ; i++){
            psum[i] = nums[i] + psum[i-1];
        }

        int maxi = 0 , i = 0;

        for(int j = 0 ; j < n ; j++){
            ll new_sum = nums[j] * 1ll *  (j-i+1);
            ll old_sum ;
            if(i == 0){
                old_sum = psum[j];
            }else{
                old_sum = psum[j] - psum[i-1];
            }
            ll cost = new_sum - old_sum;

            while(i < j && cost > k){
                i++;
                new_sum = nums[j] *1ll * (j-i+1);
                old_sum = psum[j] - psum[i-1];
                cost = new_sum - old_sum;
            }

            maxi = max(maxi , j-i+1);
        }

        return maxi;
        
    }
};