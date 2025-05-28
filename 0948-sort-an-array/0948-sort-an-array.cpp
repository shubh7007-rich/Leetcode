class Solution {
public:
    void merge(int l , int m , int h , vector<int>& nums){
        int i = l , j = m+1;
        vector<int> temp;
        while(i <= m && j <= h){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while( i <= m){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= h){
            temp.push_back(nums[j]);
            j++;
        }

        for(int e = l  ; e <= h ; e++){
            nums[e] = temp[e - l];
        }
    }
    void mergeSort(int l , int h , vector<int>& nums){

        if(l == h) return;

        int m = (l + h)/2;

        mergeSort(l , m , nums);
        mergeSort(m+1 , h , nums);
        merge(l , m , h , nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        // using merge sort

        int l = 0 , h = nums.size() - 1;

        mergeSort(l , h ,nums);

        return nums;
    }
};