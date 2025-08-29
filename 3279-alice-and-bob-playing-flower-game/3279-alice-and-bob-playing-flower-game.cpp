class Solution {
public:
    long long flowerGame(int n, int m) {
        long long cnt = 0;

        long long n_odd = (n+1)/2;
        long long n_even = n/2;
        long long m_odd = (m+1)/2;
        long long m_even = m/2;

        cnt = (n_odd * m_even) + (n_even * m_odd);

        return cnt;
    }
};