#ifndef DS_BUBBLE_SORT_BENCH_H_
#define DS_BUBBLE_SORT_BENCH_H_

#include <bubble_sort.h>
#include <sorting_benchmark_utils.h>

template <typename Iterator, typename Compare>
struct bubblesorter_naive {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::bubblesort_naive(s, e, cmp);
  }
};

template <typename Iterator, typename Compare>
struct bubblesorter_improved {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::bubblesort_improved(s, e, cmp);
  }
};


#endif  // DS_BUBBLE_SORT_BENCH_H_