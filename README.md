# sorting_algorithms
Collection of sorting algorithms and their implementation in C++11/14

This repo contains a collection of C++ implementations of a number of sorting algorithms. It also contains tests (written using google test suite).

## Compiling and running the tests requires [Google Test](https://github.com/google/googletest) [Google Benchmark](https://github.com/google/benchmark) and Cmake

 - `cd sorting_algoritms`
 - `mkdir build && cd build`
 - `cmake -DCMAKE_BUILD_TYPE=Release ..`
 - `make && ./sorting_tests`
 
 
 ## How to Contribute
- **Each algoirithm implementation should be in its own file in the `source` folder**.
- **Make sure that the interface for the sorting algorithm is the following:**
```c++
// CMP_FN has type: D -> D -> bool
template < typename Iterator, typename CMP_FN>
void awesome_sorting_algorithm(Iterator s, Iterator e, CMP_FN cmp)
```

- **Write the relative tests: each tests in its own file in the `tests` folder**
- **The minimal tests are:** 

```c++
#ifndef DS_AWESOME_ALGORITHM_SORT_TESTS_H_
#define DS_AWESOME_ALGORITHM_SORT_TESTS_H_

#include <gtest/gtest.h>
#include <sorting_test_utils.h>
#include <merge_sort.h>
//#include <common.h>
#include<vector>

TEST_P(RandomVectorSortTest, awesome_sorting_algorithm){
    std::cout<<"Input size = "<<v.size()<<std::endl;
    ASSERT_EQ(v.size(),SIZE);
    DS::awesome_sorting_algorithm(begin(v),end(v),DS::lt<TYPE>);
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,ASCENDING),true);
}

TEST_P(RandomVectorSortTest, mergesort_ascending){
    std::cout<<"Input size = "<<v.size()<<std::endl;
    ASSERT_EQ(v.size(),SIZE);
    DS::awesome_sorting_algorithm(begin(v),end(v),DS::gt<TYPE>);
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,DESCENDING),true);
}
#ENDIF // DS_AWESOME_ALGORITHM_SORT_TESTS_H_
```

- **Write a benchmark for the algorithm**
- **Each benchmark in a separate file**
- **A minimal benchmark could be the following**
```c++

static void selection_sort_BM(benchmark::State& state) {
	while (state.KeepRunning())
	{
		state.PauseTiming();

		Container v;
		populateRandom(v, state.range(0)); //numbers of elements

		state.ResumeTiming();

		DS::selection_sort(begin(v), end(v), DS::gt<TYPE>);
	}
}

BENCHMARK(selection_sort_BM)->Unit(benchmark::kMillisecond)->Range(RANGE_START, RANGE_END);

#endif //DS_SELECTION_SORT_BENCH_H_
```
- **Make sure the only timed portion of the code is the sorting. Any initialization that is not relevant for measuring the speed of the algorithm should not be counted (use `	state.PauseTiming();` and `	state.ResumeTiming();`  as in the example).**



