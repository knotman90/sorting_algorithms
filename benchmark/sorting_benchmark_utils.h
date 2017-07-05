#ifndef DS_BENCH_UTILS_H_
#define DS_BENCH_UTILS_H_

#include <benchmark/benchmark_api.h>
#include <vector>
//sorting algorithms
#include <utils.h>
#include <common.h>
#include <bubble_sort_benchmark.h>
#include <quick_sort_benchmark.h>
#include <merge_sort_benchmark.h>
#include <insertion_sort_benchmark.h>
#include <selection_sort_benchmark.h>
#include <heap_sort_benchmark.h>
#include <shell_sort_benchmark.h>
#include <intro_sort_benchmark.h>



constexpr size_t RANGE_START_SLOW = 1 << 10;
constexpr size_t RANGE_END_SLOW   = 1 << 16;

constexpr size_t RANGE_START_FAST = 1 << 15;
constexpr size_t RANGE_END_FAST   = 1 << 24;
constexpr int RANGE_MULTIPLIER = 2;


using Container = std::vector<TYPE>;

constexpr auto TIME_UNIT = benchmark::kMillisecond;//benchmark::kNanosecond;
constexpr double MIN_TIME = 0.2;

template< template<typename, typename> typename SORTING_FUNCTOR>
void benchmark_random_values(benchmark::State& state) {

    using CMP_F_TYPE = decltype(DS::gt<TYPE>);

    SORTING_FUNCTOR<Container::iterator, CMP_F_TYPE>  sorting_functor;

    while (state.KeepRunning())
    {
        state.PauseTiming();

        Container v;
        populateRandom(v, state.range(0)); //numbers of elements

        state.ResumeTiming();

        sorting_functor(begin(v), end(v), DS::gt<TYPE>);
    }
}



/////////////////////////////////////////////////
/// @Brief Selection Sort random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, selection_sorter)
->Unit(TIME_UNIT)
->MinTime(MIN_TIME)
->RangeMultiplier(RANGE_MULTIPLIER)
->Range(RANGE_START_SLOW, RANGE_END_SLOW);



/////////////////////////////////////////////////
/// @Brief Bubble Sort random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, bubblesorter)
->Unit(TIME_UNIT)
->MinTime(MIN_TIME)
->RangeMultiplier(RANGE_MULTIPLIER)
->Range(RANGE_START_SLOW, RANGE_END_SLOW);


/////////////////////////////////////////////////
/// @Brief Insertion Sort random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, insertion_sorter)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->RangeMultiplier(RANGE_MULTIPLIER)
    ->Range(RANGE_START_SLOW, RANGE_END_SLOW);

//---------------------------FAST ALGORITHMS-----------------------------------

// -----------------shell sort benchamarks for differenet gap sequences ------------------
/////////////////////////////////////////////////
/// @Brief Shell Sort A154393 gap sequenece on 
/// random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, shell_sort_A154393_sorter)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->RangeMultiplier(RANGE_MULTIPLIER)
    ->Range(RANGE_START_FAST, RANGE_END_FAST);

/////////////////////////////////////////////////
/// @Brief Shell Sort A154393 gap sequenece on 
/// random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, sshell_sort_sedgewick_sorter)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->RangeMultiplier(RANGE_MULTIPLIER)
    ->Range(RANGE_START_FAST, RANGE_END_FAST);

/////////////////////////////////////////////////
/// @Brief Shell Sort A154393 gap sequenece on 
/// random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, shell_sort_sedgewick_incerpi_sorter)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->RangeMultiplier(RANGE_MULTIPLIER)
    ->Range(RANGE_START_FAST, RANGE_END_FAST);


// --------------------------------------------------------------------------------------


/////////////////////////////////////////////////
/// @Brief Merge Sort random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, merge_sorter)
->Unit(TIME_UNIT)
->MinTime(MIN_TIME)
->RangeMultiplier(RANGE_MULTIPLIER)
->Range(RANGE_START_FAST, RANGE_END_FAST);

/////////////////////////////////////////////////
/// @Brief Quick Sort random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, quicksorter_lomuto)
->Unit(TIME_UNIT)
->MinTime(MIN_TIME)
->RangeMultiplier(RANGE_MULTIPLIER)
->Range(RANGE_START_FAST, RANGE_END_FAST);

/////////////////////////////////////////////////
/// @Brief Quick Sort random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, quicksorter_hoare)
->Unit(TIME_UNIT)
->MinTime(MIN_TIME)
->RangeMultiplier(RANGE_MULTIPLIER)
->Range(RANGE_START_FAST, RANGE_END_FAST);


/////////////////////////////////////////////////
/// @Brief Quick Sort random values benchmark
/////////////////////////////////////////////////
template <typename Iterator, typename Compare>
struct sorter_std{
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    return std::sort(s, e, cmp);
  }
};
BENCHMARK_TEMPLATE(benchmark_random_values, sorter_std)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->RangeMultiplier(RANGE_MULTIPLIER)
    ->Range(RANGE_START_FAST, RANGE_END_FAST);


/////////////////////////////////////////////////
/// @Brief Heap Sort random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, heap_sorter)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->RangeMultiplier(RANGE_MULTIPLIER)
    ->Range(RANGE_START_FAST, RANGE_END_FAST);


/////////////////////////////////////////////////
/// @Brief Heap Sort std library random values benchmark
/////////////////////////////////////////////////
 template <typename Iterator, typename Compare>
struct sort_heap_std{
  inline void operator()(Iterator s, Iterator e, Compare cmp) {
    std::make_heap(s,e,cmp);
    return std::sort_heap(s, e, cmp);
  }
};

BENCHMARK_TEMPLATE(benchmark_random_values, sort_heap_std)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->RangeMultiplier(RANGE_MULTIPLIER)
    ->Range(RANGE_START_FAST, RANGE_END_FAST);



/////////////////////////////////////////////////
/// @Brief Intro Sort random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, introsorter_lomuto)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->RangeMultiplier(RANGE_MULTIPLIER)
    ->Range(RANGE_START_FAST, RANGE_END_FAST);


/////////////////////////////////////////////////
/// @Brief Intro Sort random values benchmark hoare partition scheme
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, introsorter_hoare)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->RangeMultiplier(RANGE_MULTIPLIER)
    ->Range(RANGE_START_FAST, RANGE_END_FAST);



/*
void benchmark_quicksort_T(benchmark::State& state) {


    while (state.KeepRunning())
    {
        state.PauseTiming();

        Container v;
        populateRandom(v, state.range(0)); //numbers of elements

        state.ResumeTiming();

        DS::qsort_t(v,0,v.size(), DS::gt<TYPE>);
    }
}
BENCHMARK(benchmark_quicksort_T)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->Range(RANGE_START, RANGE_END);

*/
#endif //DS_BENCH_UTILS_H_