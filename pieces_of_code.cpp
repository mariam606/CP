//compression
comp[x];
int id = 1;
for (auto& u : comp) u.second = id++;

//giving ID
function<int(int)> get_id = [&](int x) {
 return comp.emplace(x, (int)comp.size()).first->second;
};

//looping over the submasks of the mask s
for (int msk = s; msk; msk = (msk - 1) & s)
    ..use the msk

//LCM
int get_lcm(int x, int y) { return (x / __gcd(x, y)) * y; }

//Number of subrectangles in a rectangle n * m
n * (n + 1) * m * (m + 1) / 4

//Stress testing
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

//pi
double pi = 1.0 * acos(-1);
 
