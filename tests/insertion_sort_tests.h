#ifndef DS_INSERTION_SORT_TESTS_H_
#define DS_INSERTION_SORT_TESTS_H_

#include <gtest/gtest.h>
#include <sorting_test_utils.h>
#include <insertion_sort.h>

TEST_P(RandomVectorSortTest, insertion_sort) {
    TEST_BODY(v,
              DS::insertion_sort,
              ASCENDING,
              std::less<TYPE>()
             );

}

TEST_P(RandomVectorSortTest, insertion_sort_ascending) {
    TEST_BODY(v,
              DS::insertion_sort,
              DESCENDING,
              std::greater<TYPE>()
             )
}

TEST_P(RandomVectorSortTest, maybeis_insertion_sort) {
    TEST_BODY(v,
              DS::maybeis_insertion_sort,
              ASCENDING,
              std::less<TYPE>()
             )
}


TEST_P(RandomVectorSortTest, maybeis_insertion_ascending) {
    TEST_BODY(v,
              DS::maybeis_insertion_sort,
              DESCENDING,
              std::greater<TYPE>()
             )

}


#endif //DS_INSERTION_SORT_TESTS_H_