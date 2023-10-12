int n;
const int N = 1e5 + 5;
vector<bool> is_prime;
vector<int> num_div, sumdiv, big;
vector<vector<int>> divs;
vector<int> pfact[N];

//O(N * loglog(N))
void sieve(){
    is_prime.resize(N + 1, 1)
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}

//O(N * log(N))
void num_of_divisors(){
    divisors.resize(N + 1);
    for (int i = 1; i <= N; ++i)
     for (int j = i; j <= N; j += i)
      ++num_div[j];
}

//O(N * log(N)), number of divisors of N is at most N^(1/3)
void get_divs(){
    divs.resize(N + 1);
    for (int i = 1; i <= N; ++i)
     for (int j = i; j <= N; j += i)
      divs[j].push_back(i);
}

//O(N * log(N))
void sum_of_divisors(){
    sumdiv.resize(N + 1);
    for (int i = 1; i <= N; ++i)
     for (int j = i; j <= N; j += i)
      sumdiv[j] += i;
}

//O(N * log(N))
void prime_factorization() {
    for (int i = 2; i < N; i++) if (pfact[i].empty())
        for (int j = i; j < N; j += i) pfact[j].push_back(i);
}

//O(N * log(N))
void biggest_prime_divisor(){
    big.resize(N + 1);
    big[0] = big[1] = 1;
    for (int i = 1; i <= N; ++i)
     if (big[i] == 1)
      for (int j = i; j <= N; j += i)
       big[j] = i;
}
