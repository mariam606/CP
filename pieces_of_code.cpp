//compression
comp[x];
int id = 1;
for (auto& u : comp) u.second = id++;

//giving ID
auto get_id = [&](int x) {
 return comp.emplace(x, (int)comp.size()).first->second;
};



