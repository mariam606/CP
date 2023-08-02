//compression
comp[x];
int id = 1;
for (auto& u : comp) u.second = id++;

//giving ID
auto get_id = [&](int x) {
 return comp.emplace(x, (int)comp.size()).first->second;
};

//looping over the submasks of the mask s
for (int msk = s; msk; msk = (msk - 1) & s)
    ..use the msk

//LCM
int lcm(int x, int y) { return (x / __gcd(x, y)) * y; }
