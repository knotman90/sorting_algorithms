#ifndef _DS_UTILS_H
#define _DS_UTILS_H

#include <random>
#include <algorithm> //generate_n

//add this to the test to print the content
//DS::print(ALL(v));
#define TEST_BODY(CONTAINER_NAME, SORT_FN , ASCENDING_ORDER, CMP_FN)    \
    std::cout<<"Input size = "<<(CONTAINER_NAME).size()<<std::endl;     \
    ASSERT_EQ((CONTAINER_NAME).size(),SIZE);                            \
    (SORT_FN)( ((CONTAINER_NAME).begin()) , ((CONTAINER_NAME).end()), (CMP_FN));\
    ASSERT_EQ((CONTAINER_NAME).size(),SIZE); \
    ASSERT_EQ(checksorting(v,ASCENDING_ORDER),true);

//change type to the type of random object you want to g
typedef int TYPE;
typedef std::size_t SIZE_TYPE;

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


//for not to use string you have to comment the following function otherwise the overload would be ambiguous
template<typename T, typename M, typename RANDOM_GENERATOR>
inline
typename std::enable_if_t <
std::is_integral<T>::value, T >
randObject(const M _S, RANDOM_GENERATOR& random) {
	std::uniform_int_distribution<> unii_dst(-_S, _S);
	return unii_dst(random);
}

template<typename T, typename M, typename RANDOM_GENERATOR>
inline
typename std::enable_if_t <
std::is_floating_point<T>::value , T >
randObject(const M _S, RANDOM_GENERATOR& random) {
	std::uniform_real_distribution<> unir_dst(-_S, _S);
	unir_dst(random);
}

/*
template<class T,class M>
inline
typename std::enable_if_t<std::is_integral<M>::value,std::string>
randObject(const M _S){
	return random_string(_S);
}*/



template<typename Container>
void populateRandom(Container&v, const size_t SIZE) {
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	if (SIZE <= 0)
		return;
	v.reserve(SIZE);
	for (size_t i = 0; i < SIZE ; i++)
		v.push_back(static_cast<TYPE>(randObject<TYPE, SIZE_TYPE>(SIZE, gen)));
}


template<typename Container>
void populateUniform(Container&v, const size_t SIZE) {
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	if (SIZE <= 0)
		return;
	v.reserve(SIZE);
	const TYPE obj = static_cast<TYPE>(randObject<TYPE, SIZE_TYPE>(SIZE, gen));
	for (size_t i = 0; i < SIZE ; i++)
		v.push_back(obj);
}








#endif //_DS_UTILS_H