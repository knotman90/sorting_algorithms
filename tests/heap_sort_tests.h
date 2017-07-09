#ifndef DS_HEAP_SORT_TESTS_H_
#define DS_HEAP_SORT_TESTS_H_

#include <gtest/gtest.h>
#include <sorting_test_utils.h>
#include <heap_sort.h>

/*
TEST_P(RandomVectorSortTest, heapsort){
    DS::a();
}
*/
TEST_P(RandomVectorSortTest, heapsort) {
    TEST_BODY(v,
              DS::heap_sort,
              ASCENDING,
              std::less<TYPE>()
             );

}

TEST_P(RandomVectorSortTest, heapsort_ascending) {
    TEST_BODY(v,
              DS::heap_sort,
              DESCENDING,
              std::greater<TYPE>()
             )
}



#endif //DS_HEAP_SORT_TESTS_H_