class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = groups.size();
        vector<int> assigned(1e5+1 , -1);
    
        for(int i = 0; i < elements.size() ; i++){
            int num = elements[i];
            if(assigned[num] != -1) continue;
            for(int j = num ; j < 1e5+1 ; j += num){
                if(assigned[j] == -1){
                    assigned[j] = i;
                }
            }
        }


        for(int & i : groups){
            i = assigned[i];
        }

        return groups;
    }
};