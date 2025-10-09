class Solution {

    long long LIM;
    vector<long long> SPF;
    vector<long long> primes;
void generate(int n) {
    LIM = n;
    if (n <= 2) {
        return;
    }
    SPF.resize(LIM + 1);
    SPF[0] = -1, SPF[1] = -1;
    for (long long i = 2; i <= LIM; i++) {
        SPF[i] = i;
    }
    for (long long i = 2; i * i <= LIM; i++) {
        if (SPF[i] == i) {
            for (long long j = i * i; j <= LIM; j += i) {
                if (SPF[j] == j) SPF[j] = i;
            }
        }
    }
    for (long long i = 0; i <= LIM; i++) {
        if (SPF[i] == i) {
            primes.push_back(i);
        }
    }
}

public:
    int countPrimes(int n) {
        generate(n);
        int idx = (int)(lower_bound(primes.begin(), primes.end(), n) - primes.begin());
        return idx;
    }
};