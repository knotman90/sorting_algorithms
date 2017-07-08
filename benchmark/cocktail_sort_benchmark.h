#ifndef DS_COCKTAIL_SORT_BENCH_H_
#define DS_COCKTAIL_SORT_BENCH_H_

#include <cocktail_sort.h>
#include <sorting_benchmark_utils.h>

template <typename Iterator, typename Compare>
struct cocktail_sorter {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::cocktail_sort(s, e, cmp);
  }
};



#endif  // DS_COCKTAIL_SORT_BENCH_H_