#ifndef DS_SHELL_SORT_BENCH_H_
#define DS_SHELL_SORT_BENCH_H_

#include <shell_sort.h>
#include <sorting_benchmark_utils.h>

//shell sort with different gap sequences 

template <typename Iterator, typename Compare>
struct sshell_sort_sedgewick_sorter {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::shell_sort_sedgewick(s, e, cmp);
  }
};

template <typename Iterator, typename Compare>
struct shell_sort_A154393_sorter {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::shell_sort_A154393(s, e, cmp);
  }
};


template <typename Iterator, typename Compare>
struct shell_sort_sedgewick_incerpi_sorter {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::shell_sort_sedgewick_incerpi(s, e, cmp);
  }
};

template <typename Iterator, typename Compare>
struct shell_sort_fibonacci_sorter {
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return DS::shell_sort_fibonacci(s, e, cmp);
  }
};



#endif  // DS_MERGE_SORT_BENCH_H_