#ifndef DS_HEAP_SORT_BENCH_H_
#define DS_HEAP_SORT_BENCH_H_

#include <benchmark/benchmark_api.h>
#include <common.h>
#include <heap_sort.h>
#include <sorting_benchmark_utils.h>

template <typename Iterator, typename Compare>
struct heap_sorter {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::heap_sort(s, e, cmp);
  }
};



#endif  // DS_HEAP_SORT_BENCH_H_