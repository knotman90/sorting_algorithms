#ifndef DS_INSERTION_SORT_BENCH_H_
#define DS_INSERTION_SORT_BENCH_H_

#include <insertion_sort.h>
#include <sorting_benchmark_utils.h>

template <typename Iterator, typename Compare>
struct insertion_sorter {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::insertion_sort(s, e, cmp);
  }
};

template <typename Iterator, typename Compare>
struct maybeis_insertion_sort_sorter {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::maybeis_insertion_sort(s, e, cmp);
  }
};


#endif  // DS_MERGE_SORT_BENCH_H_