#ifndef DS_QUICK_SORT_BENCH_H_
#define DS_QUICK_SORT_BENCH_H_

#include <quick_sort.h>
#include <sorting_benchmark_utils.h>

template <typename Iterator, typename Compare>
struct quicksorter_lomuto {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::quicksort_lomuto(s, e, cmp);
  }
};

template <typename Iterator, typename Compare>
struct quicksorter_hoare {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::quicksort_hoare(s, e, cmp);
  }
};

template <typename Iterator, typename Compare>
struct quicksorter_tail_recursive{
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::quicksort_tail_recursive(s, e, cmp);
  }
};

template <typename Iterator, typename Compare>
struct quicksorter_std{
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return std::sort(s, e, cmp);
  }
};




#endif  // DS_QUICK_SORT_BENCH_H_