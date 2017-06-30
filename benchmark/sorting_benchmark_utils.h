#ifndef DS_BENCH_UTILS_H_
#define DS_BENCH_UTILS_H_

#include <benchmark/benchmark_api.h>
#include <sorting_benchmark_utils.h>
#include <common.h>
#include <insertion_sort.h>
#include <utils.h>
#include <vector>
#include <functional>
#include <quick_sort.h>
constexpr size_t RANGE_START = 1<<10;
constexpr size_t RANGE_END   = 1<<17;

using TYPE = long long;
using Container = std::vector<TYPE>;
/*
template<class SORTING_FUNCTION> void benchmark_algo(benchmark::State& state) {
	while (state.KeepRunning())
	{
		state.PauseTiming();

		Container v;
		populateRandom(v, state.range(0)); //numbers of elements

		state.ResumeTiming();

		SORTING_FUNCTION(begin(v), end(v), DS::gt<TYPE>);
	}
}
*/
//using TYPE_SORT_FUNCTION = decltype(DS::quicksort< Container::iterator,decltype(DS::gt<TYPE>)>);

//BENCHMARK_TEMPLATE(benchmark_algo,TYPE_SORT_FUNCTION)->Unit(benchmark::kMillisecond)->Range(RANGE_START, RANGE_END);




#endif //DS_BENCH_UTILS_H_