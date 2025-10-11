class Solution {
public:
    /*
        people = [1,1,3,3] limit = 5
        
    */
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt = 0;

        sort(people.begin() , people.end());

        int l = 0 , r = people.size() - 1;

        while(l < r){
            if(people[l] + people[r] <= limit){
                l++;
                r--;
                cnt++;
            }else{
                cnt++;
                r--;
            }
        }

        return (l > r) ? cnt : cnt + 1;
    }
};