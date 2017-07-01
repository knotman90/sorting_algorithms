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



constexpr size_t RANGE_START = 1 << 10;
constexpr size_t RANGE_END   = 1 << 16;


using Container = std::vector<TYPE>;

constexpr auto TIME_UNIT = benchmark::kMillisecond;
constexpr double MIN_TIME = 0.5;

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


/*
/////////////////////////////////////////////////
/// @Brief Selection Sort random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, selection_sorter)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->Range(RANGE_START, RANGE_END);



/////////////////////////////////////////////////
/// @Brief Bubble Sort random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, bubblesorter)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->Range(RANGE_START, RANGE_END);


/////////////////////////////////////////////////
/// @Brief Merge Sort random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, merge_sorter)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->Range(RANGE_START, RANGE_END);*/
/////////////////////////////////////////////////
/// @Brief Quick Sort random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, quicksorter)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->Range(RANGE_START, RANGE_END);

/////////////////////////////////////////////////
/// @Brief Quick Sort random values benchmark
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, quicksorter_tail_recursive)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->Range(RANGE_START, RANGE_END);

/////////////////////////////////////////////////
/// @Brief Insertion Sort random values benchmark   
/////////////////////////////////////////////////
BENCHMARK_TEMPLATE(benchmark_random_values, insertion_sorter)
    ->Unit(TIME_UNIT)
    ->MinTime(MIN_TIME)
    ->Range(RANGE_START, RANGE_END);

#endif //DS_BENCH_UTILS_H_