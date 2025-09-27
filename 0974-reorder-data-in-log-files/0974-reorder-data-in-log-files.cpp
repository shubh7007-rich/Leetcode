class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string , string>> letterLogs , digLogs;

        for(string str : logs){
            int i = 0;
            string iden = "";
            while(i < str.length() && str[i] != ' '){
                iden += str[i];
                i++;
            }
            i++;
            
            char ch = str[i];
            
            string rest = str.substr(i);

            if(isdigit(ch)){
                digLogs.push_back({rest , iden});
            }else{
                letterLogs.push_back({rest , iden});
            }
        }

        sort(letterLogs.begin() , letterLogs.end());
        // sort(digLogs.begin() , digLogs.end());

        vector<string> ans;

        for(auto p : letterLogs){
            ans.push_back(p.second + " "  + p.first);
        }
        for(auto p : digLogs){
            ans.push_back(p.second + " " + p.first);
        }

        return ans;
    }
};