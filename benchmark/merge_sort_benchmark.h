#ifndef DS_MERGE_SORT_BENCH_H_
#define DS_MERGE_SORT_BENCH_H_

#include <benchmark/benchmark_api.h>
#include <common.h>
#include <merge_sort.h>
#include <sorting_benchmark_utils.h>

template <typename Iterator, typename CMP_FN>
struct merge_sorter {
  inline void operator()(Iterator s, Iterator e, CMP_FN cmp) {
    return DS::mergesort(s, e, cmp);
  }
};



#endif  // DS_MERGE_SORT_BENCH_H_