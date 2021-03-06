#ifndef DS_SELECTION_SORT_BENCH_H_
#define DS_SELECTION_SORT_BENCH_H_

#include <selection_sort.h>
#include <sorting_benchmark_utils.h>

template <typename Iterator, typename Compare>
struct selection_sorter {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::selection_sort(s, e, cmp);
  }
};



#endif  // DS_SELECTION_SORT_BENCH_H_