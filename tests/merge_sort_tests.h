#ifndef DS_MERGE_SORT_TESTS_H_
#define DS_MERGE_SORT_TESTS_H_

#include <gtest/gtest.h>
#include <sorting_test_utils.h>
#include <merge_sort.h>
#include <vector>

TEST_P(RandomVectorSortTest, mergesort){
    TEST_BODY(v,
              DS::mergesort,
              ASCENDING,
              less<TYPE>()
            );
}

TEST_P(RandomVectorSortTest, mergesort_ascending){
        TEST_BODY(v,
              DS::mergesort,
              DESCENDING,
              greater<TYPE>()
            );
    
}



#endif //DS_MERGE_SORT_TESTS_H_