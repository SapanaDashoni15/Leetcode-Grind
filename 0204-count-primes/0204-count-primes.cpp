class Solution {
public:
    int countPrimes(int n) {
        // sieve of eratoasthenes

        int count = 0;
        vector<bool> primes(n+1, true);
        primes[0] = primes[1] = false;

        for(int i = 2; i< n; i++) {
            if(primes[i]) {
                count++;

                for(int j = 2*i; j<n; j = j+i) {
                primes[j] = 0;

            }
            }

            
        }
        return count;
    }
};