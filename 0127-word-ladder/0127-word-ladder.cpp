class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> check(wordList.begin(), wordList.end());

        if(!check.count(endWord)) return 0;
        
        queue<string> que;
        que.push(beginWord);
        check.erase(beginWord);
        int lvl = 1;

        while(!que.empty()){
            int size = que.size();

            while(size--){
                string fro = que.front();
                que.pop();

                if(fro == endWord) return lvl ;

                for(int i = 0 ; i < fro.size() ; i++){
                    char ch = fro[i];
                    
                    for(char j = 'a' ; j <= 'z' ; j++){
                        fro[i] = j;

                        if(check.count(fro)){
                            que.push(fro);
                            check.erase(fro);
                        }
                    }

                    fro[i] = ch;
                }


            }
            lvl++;
        }

        return 0;
    }
};