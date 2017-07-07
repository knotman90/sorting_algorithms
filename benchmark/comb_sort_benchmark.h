#ifndef DS_COMB_SORT_BENCH_H_
#define DS_COMB_SORT_BENCH_H_

#include <comb_sort.h>
#include <sorting_benchmark_utils.h>

template <typename Iterator, typename Compare>
struct comb_sorter {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::comb_sort(s, e, cmp);
  }
};



#endif  // DS_COMB_SORT_BENCH_H_