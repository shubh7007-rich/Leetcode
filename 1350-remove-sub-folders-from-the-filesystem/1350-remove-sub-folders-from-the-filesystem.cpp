class Solution {
public:
    bool func(string perm , string temp){
        int n = perm.length() , l = temp.length() , i = 0 , j = 0;
        while(i < n && j < l){
            if(temp[j] != perm[i]) return false;
            i++;j++;
        }

        if(temp[j] == '/' || j == l) return true;

        return false;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin() , folder.end());

        int prev = 0 , i = 1;
        string p = folder[prev];

        vector<string> ans;
        ans.push_back(folder[0]);

        while(i < folder.size()){
            if(folder[i].length() < p.length()){
                prev = i;
                p = folder[prev];  
                ans.push_back(folder[i]);  
            }else{
                // string temp = folder[i].substr(0 , p.length());
                bool flag = func(folder[prev] ,folder[i]);

                if(!flag){
                    prev = i;
                    p = folder[prev];
                    ans.push_back(folder[i]); 
                }
            }

            i++;
        }

        return ans;
    }
};