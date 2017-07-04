#ifndef DS_SHELL_SORT_TESTS_H_
#define DS_SHELL_SORT_TESTS_H_

#include <gtest/gtest.h>
#include <sorting_test_utils.h>
#include <shell_sort.h>
#include <algorithm>
/*
TEST(RandomVectorSortTest, shellsort){
    std::vector<int> v ;
    v.resize(100);
    int n = {0};
    std::generate(v.begin(), v.end(), [&n]{ return n++; });
    std::random_shuffle(v.begin(), v.end());
    DS::print(ALL(v));
    std::array<int,3> s={10,5,1};
    DS::shell_sort(begin(v),end(v),DS::lt<int>,DS::sedgewick);
    DS::print(ALL(v));
    ASSERT_EQ(checksorting(v,ASCENDING),true);
}*/

//A154393 gap sequence ---------------------------------
TEST_P(RandomVectorSortTest, shell_sort_A154393_sort){
    std::cout<<"Input size = "<<v.size()<<std::endl;ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::shell_sort_A154393(begin(v),end(v),DS::lt<TYPE>);
    //DS::print(ALL(v));
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,ASCENDING),true);
}

TEST_P(RandomVectorSortTest, shell_sort_A154393_ascending){
    std::cout<<"Input size = "<<v.size()<<std::endl;ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::shell_sort_A154393(begin(v),end(v),DS::gt<TYPE>);
    //DS::print(ALL(v));
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,DESCENDING),true);
}

//sadewick gap sequence ---------------------------------
TEST_P(RandomVectorSortTest, shell_sort_sedgewick_sort){
    std::cout<<"Input size = "<<v.size()<<std::endl;ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::shell_sort_sedgewick(begin(v),end(v),DS::lt<TYPE>);
    //DS::print(ALL(v));
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,ASCENDING),true);
}

TEST_P(RandomVectorSortTest, shell_sort_sedgewick_ascending){
    std::cout<<"Input size = "<<v.size()<<std::endl;ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::shell_sort_sedgewick(begin(v),end(v),DS::gt<TYPE>);
    //DS::print(ALL(v));
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,DESCENDING),true);
}


//shell_sort_sedgewick_incerpi gap sequence ---------------------------------
TEST_P(RandomVectorSortTest, shell_sort_sedgewick_incerpi_sort){
    std::cout<<"Input size = "<<v.size()<<std::endl;ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::shell_sort_sedgewick_incerpi(begin(v),end(v),DS::lt<TYPE>);
    //DS::print(ALL(v));
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,ASCENDING),true);
}

TEST_P(RandomVectorSortTest, shell_sort_sedgewick_incerpi_ascending){
    std::cout<<"Input size = "<<v.size()<<std::endl;ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::shell_sort_sedgewick_incerpi(begin(v),end(v),DS::gt<TYPE>);
    //DS::print(ALL(v));
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,DESCENDING),true);
}




#endif //DS_SHELL_SORT_TESTS_H_