#include "HashFuncGen.h"

HashFuncGen::HashFuncGen(const size_t mod): MOD(mod) {
  coefficients.resize(30);
  for (int i = 0; i < 30; ++i) {
    coefficients[i] = distrib(gen);
  }
}

size_t HashFuncGen::GetHash(const std::string& key, size_t p) {
  size_t hash = 0;
  size_t pow_p = 1;
  for (int i = 0; i < key.length(); ++i) {
    hash += (std::hash<char>() (key[i]) % MOD) * pow_p * coefficients[i];
    pow_p *= p;
    hash %= MOD;
  }
  return hash ^ (std::hash<std::string>()(key) % MOD);
}

void CheckUniformDistribution(int count, size_t m) {
  RandomStreamGen gen(1);
  std::vector<size_t> v(m, 0);
  HashFuncGen hash_gen(m);
  for (size_t i = 0; i < count; i++) {
    ++v[hash_gen.GetHash(gen.Next())];
  }
  std::cout << *std::max_element(v.begin(), v.end()) << ' ' << *std::min_element(v.begin(), v.end()) << std::endl;
}
