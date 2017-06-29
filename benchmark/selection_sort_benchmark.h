#ifndef DS_SELECTION_SORT_BENCH_H_
#define DS_SELECTION_SORT_BENCH_H_

#include <benchmark/benchmark_api.h>
#include <sorting_benchmark_utils.h>
#include <common.h>
#include <selection_sort.h>
#include <utils.h>
#include <vector>

using TYPE = long long;
using Container = std::vector<TYPE>;

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