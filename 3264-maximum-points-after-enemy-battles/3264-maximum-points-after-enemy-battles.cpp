#define ll long long
class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        ll points = 0;


        ll curr = currentEnergy;

        

        sort(enemyEnergies.begin() , enemyEnergies.end());
        if(curr < enemyEnergies[0]) return 0;

        for(int i = 1 ; i < enemyEnergies.size() ; i++){
            curr += enemyEnergies[i];
        }

        return (curr/enemyEnergies[0]);
    }
}; 