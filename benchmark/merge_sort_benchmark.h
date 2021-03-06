#ifndef DS_MERGE_SORT_BENCH_H_
#define DS_MERGE_SORT_BENCH_H_

#include <benchmark/benchmark_api.h>
#include <common.h>
#include <merge_sort.h>
#include <sorting_benchmark_utils.h>

template <typename Iterator, typename Compare>
struct merge_sorter {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::mergesort(s, e, cmp);
  }
};



#endif  // DS_MERGE_SORT_BENCH_H_