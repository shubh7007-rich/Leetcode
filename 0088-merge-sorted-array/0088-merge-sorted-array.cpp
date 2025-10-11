class Solution {
public:
    /*
        [4, 5 , 4 , 5 , 6 , 7]
         i
        [1 , 2 , 7]
             j
    */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1 , j = n-1;
        int p = m+n-1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[p] = nums1[i];
                i--;
            }else{
                nums1[p] = nums2[j];
                j--;
            }
            p--;
        }

        while(i >= 0){
            nums1[p] = nums1[i];
            p--;
            i--;
        }
        while(j >= 0){
            nums1[p] = nums2[j];
            p--;
            j--;
        }

    }
};