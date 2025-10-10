class Solution {
public:
    void merge(vector<int>& arr, int lb, int mid, int ub) {
        int i = lb;
        int j = mid + 1;
        vector<int> sorted_arr(ub - lb + 1);
        int k = 0;

        while (i <= mid && j <= ub) {
            if (arr[i] < arr[j]) {
                sorted_arr[k] = arr[i];
                i++;
            } else {
                sorted_arr[k] = arr[j];
                j++;
            }
            k++;
        }

        while (i <= mid) {
            sorted_arr[k] = arr[i];
            i++;
            k++;
        }
        while (j <= ub) {
            sorted_arr[k] = arr[j];
            j++;
            k++;
        }

        for (int m = 0; m < sorted_arr.size(); m++) {
            arr[lb + m] = sorted_arr[m];
        }
    }

    void mergesort(vector<int>& arr, int lb, int ub) {
        if (lb < ub) {
            int mid = lb + (ub - lb) / 2;
            mergesort(arr, lb, mid);
            mergesort(arr, mid + 1, ub);
            merge(arr, lb, mid, ub);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};
