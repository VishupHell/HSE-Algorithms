#include "StringTester.h"
#include <fstream>

void StringTester::MeasureParameters(Algorithm &algo, vector<string> &data, string file_name) {
  std::ofstream out(file_name);
  out << "time,number_of_comparisons\n";
  for (int i = 100; i <= 3000; i += 100) {
    auto x = algo.apply(data, i);
    out << x.first << ',' << x.second << endl;
  }
  out.close();
}
