#ifndef DS_MERGE_SORT_BENCH_H_
#define DS_MERGE_SORT_BENCH_H_

#include <benchmark/benchmark_api.h>
#include <sorting_benchmark_utils.h>
#include <common.h>
#include <merge_sort.h>
#include <utils.h>
#include <vector>

using TYPE = long long;
using Container = std::vector<TYPE>;

static void merge_sort_BM(benchmark::State& state) {
	while (state.KeepRunning())
	{
		state.PauseTiming();

		Container v;
		populateRandom(v, state.range(0)); //numbers of elements

		state.ResumeTiming();

		DS::mergesort(begin(v), end(v), DS::gt<TYPE>);
	}
}

BENCHMARK(merge_sort_BM)->Unit(benchmark::kMillisecond)->Range(RANGE_START, RANGE_END);


#endif //DS_MERGE_SORT_BENCH_H_