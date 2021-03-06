#ifndef DS_SORTING_TEST_UTILS_H_
#define DS_SORTING_TEST_UTILS_H_

#include <gtest/gtest.h>
#include <common.h>
#include <utils.h>
#include <utils.h>
#include <vector>
#include <insertion_sort.h>

constexpr bool ASCENDING  = true;
constexpr bool DESCENDING = false;

/**
	Check if the container if ordered in increasing or decreasing fashion
*/
template<class Container>
bool checksorting(Container& v, bool ascending) {
	using Container_type = typename Container::value_type;
	if (v.size() <= 1)
		return true;

	auto prev = v[0];
	auto cmp = ascending ? DS::gt<Container_type> : DS::lt<TYPE>;
	for (size_t i = 1; i < v.size(); i++) {
		if (cmp(prev, v[i])) {
			std::cout << "error on " << prev << " " << v[i] << std::endl;
			return false;
		}
		prev = v[i];
	}
	return true;
}



using ::testing::TestWithParam;
using ::testing::Values;
using ::testing::Range;

constexpr int START = 5;
constexpr int END   = 100;
constexpr int RUNS  = 20; //change this
constexpr int STEP  = (END - START) / RUNS;

//TYPE and size_TYPE defined in utils.h
class RandomVectorSortTest : public ::testing::TestWithParam<int> {

protected:
	SIZE_TYPE SIZE = 1000 ;
public:
	std::vector<TYPE> v;

void SetUp() {
		SIZE = GetParam();
		populateRandom(v,SIZE);
	}

};


INSTANTIATE_TEST_CASE_P(
    size_list,
    RandomVectorSortTest,
//    Values(1 , 2 , 3 , 5 , 10 , 100,1000,10000 ,50000  )
    //Values(2 , 4 , 8 , 16 , 32, 64, 128, 256, 512, 1024, 2048, 2048 * 4, 155, 13, 25    )
    Range(START, END, STEP)
//Values( 0 , 1 , 2, 3, 6 )
);


//a container filled with othe same value (means also already sorted)
class UniformVectorSortTest : public ::testing::TestWithParam<int> {

protected:
	SIZE_TYPE SIZE = 1000 ;
public:
	std::vector<TYPE> v;

void SetUp() {
		SIZE = GetParam();
		populateUniform(v,SIZE);
	}

};


INSTANTIATE_TEST_CASE_P(
    size_list,
    UniformVectorSortTest,
//    Values(1 , 2 , 3 , 5 , 10 , 100,1000,10000 ,50000  )
    //Values(2 , 4 , 8 , 16 , 32, 64, 128, 256, 512, 1024, 2048, 2048 * 4, 155, 13, 25    )
    Range(START, END, STEP)
//Values( 0 , 1 , 2, 3, 6 )
);


#endif //DS_SORTING_TEST_UTILS_H_