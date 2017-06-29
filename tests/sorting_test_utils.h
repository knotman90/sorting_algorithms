
#ifndef DS_SORTING_TEST_UTILS_H_
#define DS_SORTING_TEST_UTILS_H_

#include <gtest/gtest.h>
#include <common.h>

constexpr bool ASCENDING  = true;
constexpr bool DESCENDING = false;

/**
	Check if the container if ordered in increasing or decreasing fashion
*/
template<class Container>
bool checksorting(Container& v, bool ascending) {
	using TYPE = typename Container::value_type;
	if (v.size() <= 1)
		return true;

	auto prev = v[0];
	auto cmp = ascending ? DS::gt<TYPE> : DS::lt<TYPE>;
	for (size_t i = 1; i < v.size(); i++) {
		if (cmp(prev, v[i])) {
			std::cout << "error on " << prev << " " << v[i] << std::endl;
			return false;
		}
		prev = v[i];
	}
	return true;
}

std::string random_string( size_t length )
{
	auto randchar = []() -> char
	{
		const char charset[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[ rand() % max_index ];
	};
	std::string str(length, 0);
	std::generate_n( str.begin(), length, randchar );
	return str;
}

using ::testing::TestWithParam;
using ::testing::Values;
using ::testing::Range;




//for not to use string you have to comment the following function otherwise the overload would be ambiguous
template<class T, class M>
inline
typename std::enable_if_t <
std::is_integral<T>::value, T >
randObject(const M _S) {
	return (rand() % (_S * 2) + 1);
}

template<class T, class M>
inline
typename std::enable_if_t <
std::is_floating_point<T>::value , T >
randObject(const M _S) {
	return _S * (static_cast<T> (rand() / static_cast<T> (RAND_MAX)));
}

/*
template<class T,class M>
inline
typename std::enable_if_t<std::is_integral<M>::value,std::string>
randObject(const M _S){
	return random_string(_S);
}*/



//change type to the type of random object you want to g
using TYPE 		=	long long;
using SIZE_TYPE = 	std::size_t;

class RandomVectorSortTest : public ::testing::TestWithParam<int> {

protected:
	SIZE_TYPE SIZE = 1000 ;
public:
	std::vector<TYPE> v;

	void SetUp() {
		srand(time(0));
		SIZE = GetParam();
		if (SIZE <= 0)
			return;
		v.resize(SIZE);
		size_t i = 0;
		while (i < SIZE) {
			v[i++] = static_cast<TYPE>(randObject<TYPE, SIZE_TYPE>(SIZE));

		}
	}
};

constexpr int START = 0;
constexpr int END   = 50000;
constexpr int RUNS  = 10; //change this
constexpr int STEP  = (END - START) / RUNS;

INSTANTIATE_TEST_CASE_P(
    size_list,
    RandomVectorSortTest,
//    Values(1 , 2 , 3 , 5 , 10 , 100,1000,10000 ,50000  )
    //Values(2 , 4 , 8 , 16 , 32, 64, 128, 256, 512, 1024, 2048, 2048 * 4, 155, 13, 25    )
    Range(START, END, STEP)
//Values( 0 , 1 , 2, 3, 6 )
);



#endif //DS_SORTING_TEST_UTILS_H_