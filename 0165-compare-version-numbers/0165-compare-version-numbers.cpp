class Solution {
public:
    int compareVersion(string ver1, string ver2) {
        int len1 = ver1.length() , len2 = ver2.length() , i = 0 , j = 0;
        
        while(i < len1 && j < len2){
            string str1 = "" , str2 = "";
            while(i < len1 && ver1[i] != '.'){
                str1 += ver1[i];
                i++;
            }
            while(j < len2 && ver2[j] != '.'){
                str2 += ver2[j];
                j++;
            }
            int n1 = stoi(str1) , n2 = stoi(str2);

            if(n1 > n2){
                return 1;
            }else if(n2 > n1){
                return -1;
            }

            i++;
            j++;
        }

        while(i < len1){
            string str1 = "";
            while(i < len1 && ver1[i] != '.'){
                str1 += ver1[i];
                i++;
            }
            int n1 = stoi(str1);

            if(n1 > 0) return 1;
            i++;
        }
        while(j < len2){
            string str1 = "";
            while(j < len2 && ver2[j] != '.'){
                str1 += ver2[j];
                j++;
            }
            int n1 = stoi(str1);

            if(n1 > 0) return -1;
            j++;
        }

        return 0;
    }
};