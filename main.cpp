#include <iostream>
#include <unordered_set>
#include <fstream>
#include "HashFuncGen.h"

std::pair<int, int> GetMetaData(size_t hash, int m) {
  size_t k = ((size_t)1 << 31);
  int st = (1 << (m - 1));
  int ind = 0;
  for (int j = 0; j < m; j++) {
    if ((hash & k) > 0) {
      ind += st;
    }
    st >>= 1;
    k >>= 1;
  }
  int ans = 1;
  while ((hash & k) == 0 && k > 0) {
    ++ans;
    k >>= 1;
  }
  return {ind, ans};
}

void HyperLogLog(HashFuncGen& func_gen, RandomStreamGen& random_gen, size_t count, int m, double alpha) {
  std::ofstream fout("ans3.txt");
  std::unordered_set<std::string> set{};
  std::vector<int> sub_threads(1 << m, 1);
  for (int x = 0; x < count / random_gen.GetSubStreamCount(); ++x) {
    std::vector<std::string> strings = random_gen.NextSubStream();
    for (int j = 0; j < strings.size(); ++j) {
      set.insert(strings[j]);
      auto ans = GetMetaData(func_gen.GetHash(strings[j]), m);
      sub_threads[ans.first] = std::max(ans.second, sub_threads[ans.first]);
    }
    double sum = 0;
    for (int i = 0; i < sub_threads.size(); i++) {
      sum += (1. / (1 << sub_threads[i]));
    }
    //fout << (x + 1) << ' ' << set.size() << ' ' << alpha * sub_threads.size() * sub_threads.size() / sum << "\n";
    fout << (int)(alpha * sub_threads.size() * sub_threads.size() / sum) << "\n";
  }
  fout.close();
}

int main() {
  const size_t mod = (size_t)1 << 32;
  std::cout << mod << " mod\n";
  HashFuncGen func_gen(mod);
  RandomStreamGen stream_gen(10000);
  HyperLogLog(func_gen, stream_gen, 1000000, 13, 0.721);
  CheckUniformDistribution(1000000, mod / (1 << 16));
}