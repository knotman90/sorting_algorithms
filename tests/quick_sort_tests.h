#ifndef DS_QUICK_SORT_TESTS_H_
#define DS_QUICK_SORT_TESTS_H_

#include <gtest/gtest.h>
#include <vector>
#include <sorting_test_utils.h>
#include <quick_sort.h>


TEST_P(RandomVectorSortTest, quicksort_lomuto){
    std::cout<<"Input size = "<<v.size()<<std::endl;
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::quicksort_lomuto(begin(v),end(v),DS::lt<TYPE>);
    //std::cout<<std::endl;  DS::print(ALL(v));
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,ASCENDING),true);
}

TEST_P(RandomVectorSortTest, quicksort_lomuto_ascending){
    std::cout<<"Input size = "<<v.size()<<std::endl;
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::quicksort_lomuto(begin(v),end(v),DS::gt<TYPE>);
    //std::cout<<std::endl;DS::print(ALL(v));
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,DESCENDING),true);
}


TEST_P(RandomVectorSortTest, quicksort_hoare){
    std::cout<<"Input size = "<<v.size()<<std::endl;
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::quicksort_hoare(begin(v),end(v),DS::lt<TYPE>);
    //std::cout<<std::endl;  DS::print(ALL(v));
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,ASCENDING),true);
}

TEST_P(RandomVectorSortTest, quicksort_hoare_ascending){
    std::cout<<"Input size = "<<v.size()<<std::endl;
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::quicksort_hoare(begin(v),end(v),DS::gt<TYPE>);
    //std::cout<<std::endl;DS::print(ALL(v));
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,DESCENDING),true);
}

TEST_P(RandomVectorSortTest, quicksort_tail_recursive){
    std::cout<<"Input size = "<<v.size()<<std::endl;
    ASSERT_EQ(v.size(),SIZE);
    //DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::quicksort_tail_recursive(begin(v),end(v),DS::lt<TYPE>);
    //std::cout<<std::endl;  DS::print(ALL(v));
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,ASCENDING),true);
}


TEST_P(RandomVectorSortTest, quicksort_tail_recursive_ascending){
    std::cout<<"Input size = "<<v.size()<<std::endl;
    ASSERT_EQ(v.size(),SIZE);
   // if(v.size()<1000)
   // DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::quicksort_tail_recursive(begin(v),end(v),DS::gt<TYPE>);
    //    if(v.size()<1000){
    //std::cout<<std::endl;DS::print(ALL(v));}
    ASSERT_EQ(v.size(),SIZE);
    ASSERT_EQ(checksorting(v,DESCENDING),true);
}


/*
TEST(BasicTestQuick, quicksort_lomuto_basic){
    std::vector<int> v ;//= {-9 ,1 ,5 ,12, 13, 13, 2 ,3,100,101,101,1011,-8};
    
    for(int i=30;i>=0 ; i--){
      //  v.push_back(i);
    } 
    populateRandom(v,50);
    for(int i=0;i<=50 ; i++){
        //v.push_back(i);

    } 
  //  ASSERT_EQ(v.size(),8);
    DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::quicksort_hoare(begin(v),begin(v),end(v),DS::gt<TYPE>);
    DS::print(ALL(v));
    //ASSERT_EQ(v.size(),8);
    ASSERT_EQ(checksorting(v,DESCENDING),true);
}*/
/*
TEST(BasicTestQuick, quicksort_hoare_basic){
    std::vector<int> v = {-9 ,1 ,5 ,12, 13, 13, 2 ,3,100,101,101,1011,-8};
  //  ASSERT_EQ(v.size(),8);
    DS::print(ALL(v));
    //std::cout<<"begin"<<std::distance(begin(v),end(v))<<std::endl;
    DS::quicksort_hoare (begin(v),end(v),DS::gt<TYPE>);
    DS::print(ALL(v));
    //ASSERT_EQ(v.size(),8);
    ASSERT_EQ(checksorting(v,DESCENDING),true);
}
*/



#endif //DS_QUICK_SORT_TESTS_H_