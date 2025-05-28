class Solution {
public:
    int cnt = 0;
    
    void merge(int l , int mid , int r , vector<int>& arr){
        int i = l , j = mid+1;
        
        vector<int> temp;

        while(i <= mid && j <= r){
            if(arr[i] > 2 *(long long)arr[j]){
                cnt += mid - i + 1;
                j++;
            }else{
                i++;
            }
        }

        i = l ;
        j = mid+1;
        
        while(i <= mid && j <= r){
            
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                temp.push_back(arr[j]);
                
                j++;
            }
        }
        
        while(i <= mid){
            temp.push_back(arr[i]);i++;
        }
        while(j <= r){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int e = l ; e <= r ; e++){
            arr[e] = temp[e-l];
        }
    }
    
    void ms(int l , int r , vector<int> &arr){
        if(l == r) return;
        
        int mid = (l + r)/2;
        
        ms(l , mid , arr);
        ms(mid+1 , r , arr);
        
        merge(l , mid , r , arr);
    }
    int reversePairs(vector<int>& nums) {
        ms(0 , nums.size() - 1 , nums);
        return cnt;
    }
};