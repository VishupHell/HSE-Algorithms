#include <iostream>

#include "algorithms/BasicMergeSort.h"
#include "algorithms/BasicQuickSort.h"
#include "algorithms/MergeSort.h"
#include "algorithms/MSBRadixQuickSort.h"
#include "algorithms/QuickSort.h"
#include "algorithms/RadixSort.h"
#include "StringGenerator.h"
#include "infrastructure/StringTester.h"

int main() {
  StringGenerator g;
  auto x1 = g.GetTestsVectors(1, 3000);
  auto x2 = g.GetTestsVectors(2, 3000);
  auto x3 = g.GetTestsVectors(3, 3000);
  StringTester st;
  MergeSort ms;
  st.MeasureParameters(ms, x1, "Merge_sort_type1.txt");
  st.MeasureParameters(ms, x2, "Merge_sort_type2.txt");
  st.MeasureParameters(ms, x3, "Merge_sort_type3.txt");
  QuickSort qs;
  st.MeasureParameters(qs, x1, "Quick_sort_type1.txt");
  st.MeasureParameters(qs, x2, "Quick_sort_type2.txt");
  st.MeasureParameters(qs, x3, "Quick_sort_type3.txt");
  MSBRadixSort rs;
  st.MeasureParameters(rs, x1, "Radix_sort_type1.txt");
  st.MeasureParameters(rs, x2, "Radix_sort_type2.txt");
  st.MeasureParameters(rs, x3, "Radix_sort_type3.txt");
  MSBRadixQuickSort rqs;
  st.MeasureParameters(rqs, x1, "Radix_Quick_sort_type1.txt");
  st.MeasureParameters(rqs, x2, "Radix_Quick_sort_type2.txt");
  st.MeasureParameters(rqs, x3, "Radix_Quick_sort_type3.txt");
}