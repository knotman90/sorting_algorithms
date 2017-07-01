#ifndef DS_QUICK_SORT_BENCH_H_
#define DS_QUICK_SORT_BENCH_H_

#include <quick_sort.h>
#include <sorting_benchmark_utils.h>

template <typename Iterator, typename CMP_FN>
struct quicksorter {
  inline void operator()(Iterator s, Iterator e, CMP_FN cmp) {
    return DS::quicksort(s, e, cmp);
  }
};


template <typename Iterator, typename CMP_FN>
struct quicksorter_tail_recursive{
  inline void operator()(Iterator s, Iterator e, CMP_FN cmp) {
    return DS::quicksort_tail_recursive(s, e, cmp);
  }
};

#endif  // DS_QUICK_SORT_BENCH_H_