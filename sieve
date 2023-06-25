int n;
const int N = 1e5 + 5;
vector<bool> is_prime;

void sieve(){
  is_prime.resize(N, 1)
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i < N; i++) {
      if (is_prime[i]) {
          for (int j = i * i; j < N; j += i)
              is_prime[j] = false;
      }
  }
}
