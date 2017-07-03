#ifndef DS_HEAP_SORT_TESTS_H_
#define DS_HEAP_SORT_TESTS_H_

#include <gtest/gtest.h>
#include <sorting_test_utils.h>
#include <heap_sort.h>
//#include <common.h>

TEST_P(RandomVectorSortTest, heapsort){
    DS::a();
}
/*
TEST_P(RandomVectorSortTest, bubblesort){
    std::cout<<"Input size = "<<v.size()<<std::endl;
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::bubblesort(begin(v),end(v),DS::lt<TYPE>);
    //DS::print(ALL(v));
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,ASCENDING),true);
}

TEST_P(RandomVectorSortTest, bubblesort_ascending){
    std::cout<<"Input size = "<<v.size()<<std::endl;ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::bubblesort(begin(v),end(v),DS::gt<TYPE>);
    //DS::print(ALL(v));
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,DESCENDING),true);
}
*/


#endif //DS_HEAP_SORT_TESTS_H_