#ifndef DS_INTRO_SORT_BENCH_H_
#define DS_INTRO_SORT_BENCH_H_

#include <benchmark/benchmark_api.h>
#include <common.h>
#include <intro_sort.h>
#include <sorting_benchmark_utils.h>

template <typename Iterator, typename Compare>
struct introsorter_lomuto {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::intro_sort_lomuto(s, e, cmp);
  }
};

template <typename Iterator, typename Compare>
struct introsorter_hoare {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::intro_sort_hoare(s, e, cmp);
  }
};


#endif  // DS_HEAP_SORT_BENCH_H_