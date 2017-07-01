#ifndef DS_BUBBLE_SORT_BENCH_H_
#define DS_BUBBLE_SORT_BENCH_H_

#include <bubble_sort.h>
#include <sorting_benchmark_utils.h>

template <typename Iterator, typename CMP_FN>
struct bubblesorter {
  inline void operator()(Iterator s, Iterator e, CMP_FN cmp) {
    return DS::bubblesort(s, e, cmp);
  }
};

#endif  // DS_BUBBLE_SORT_BENCH_H_