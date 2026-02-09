#ifndef RANDOMSTREAMGEN_H
#define RANDOMSTREAMGEN_H

#include <random>
#include <vector>

class RandomStreamGen
{
  size_t sub_stream_count;
  std::random_device rd = {};
  std::mt19937 gen = std::mt19937(rd());
  std::vector<char> alphabet;
  std::uniform_int_distribution<int> distrib_char = std::uniform_int_distribution<int>(0, 61);
  std::uniform_int_distribution<int> distrib_len = std::uniform_int_distribution<int>(1, 15);
public:
  RandomStreamGen(size_t sub_counts);
  std::string Next();
  std::vector<std::string> NextSubStream();
  size_t GetSubStreamCount() const;
};

#endif //RANDOMSTREAMGEN_H
