#ifndef DS_MERGE_SORT_TESTS_H_
#define DS_MERGE_SORT_TESTS_H_

#include <gtest/gtest.h>
#include <sorting_test_utils.h>
#include <merge_sort.h>
//#include <common.h>
#include<vector>

TEST_P(RandomVectorSortTest, mergesort){
    std::cout<<"Input size = "<<v.size()<<std::endl;
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::mergesort(begin(v),end(v),DS::lt<TYPE>);
    //std::cout<<std::endl;  DS::print(ALL(v));
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,ASCENDING),true);
}

TEST_P(RandomVectorSortTest, mergesort_ascending){
    std::cout<<"Input size = "<<v.size()<<std::endl;
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::mergesort(begin(v),end(v),DS::gt<TYPE>);
    //std::cout<<std::endl;DS::print(ALL(v));
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,DESCENDING),true);
}
/*
TEST(BasicTestMerge, mergesort_basic){
    std::vector<int> v = {9 ,1 ,5 ,12, 13, 13, 2 ,3,100,101,101,1011};
  //  ASSERT_EQ(v.size(),8);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::mergesort(begin(v),end(v),DS::gt<TYPE>);
    DS::print(ALL(v));
    //ASSERT_EQ(v.size(),8);
    ASSERT_EQ(checksorting(v,DESCENDING),true);
}*/



#endif //DS_MERGE_SORT_TESTS_H_