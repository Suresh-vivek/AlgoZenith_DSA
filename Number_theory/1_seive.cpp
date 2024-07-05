#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void sieve(vector<bool>& is_prime, int max_num) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= max_num; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_num; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    long long l, r;
    cin >> l >> r;

    int limit = sqrt(r) + 1;
    vector<bool> is_prime(limit + 1, true);
    sieve(is_prime, limit);

    vector<bool> range_prime(r - l + 1, true);

    for (long long i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            long long start = max(i * i, (l + i - 1) / i * i);
            for (long long j = start; j <= r; j += i) {
                range_prime[j - l] = false;
            }
        }
    }

    if (l == 1) {
        range_prime[0] = false; // 1 is not a prime number
    }
    int count =0;

    for (long long i = l; i <= r; ++i) {
        if (range_prime[i - l]) {
            count++;
        }
    }
    cout<<count<<endl;
    for (long long i = l; i <= r; ++i) {
        if (range_prime[i - l]) {
            cout << i << " ";
        }
    }

    return 0;
}
