
#ifndef STRINGGENERATOR_H
#define STRINGGENERATOR_H
#include <vector>
#include <algorithm>
#include <string>
#include <random>
using namespace std;

struct StringGenerator {
  StringGenerator();

  string GetString(int len);

  vector<string> GetFirstTypeVector(int len);

  vector<string> GetSecondTypeVector(int len);

  vector<string> GetThirdTypeVector(int len);

  vector<string> GetTestsVectors(int type, int len);


private:
  const int LEN = 75;
  vector<char> chars;
  std::random_device rd;
  std::mt19937 gen;
  std::uniform_int_distribution<> distr_for_chars;
  std::uniform_int_distribution<> distr_for_lens;
};

#endif //STRINGGENERATOR_H
