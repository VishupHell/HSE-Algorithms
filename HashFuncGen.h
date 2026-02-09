#ifndef HASHFUNCGEN_H
#define HASHFUNCGEN_H

#include <random>
#include <vector>
#include <iostream>
#include "RandomStreamGen.h"

class HashFuncGen {
  const size_t MOD;
  std::vector<size_t> coefficients;
  std::random_device rd = {};
  std::mt19937 gen = std::mt19937(rd());
  std::uniform_int_distribution<int> distrib = std::uniform_int_distribution<int>(MOD/2, MOD - 1);
public:
  HashFuncGen(const size_t mod);
  size_t GetHash(const std::string& key, size_t p = 197);
};

void CheckUniformDistribution(int count, size_t m);

#endif //HASHFUNCGEN_H
