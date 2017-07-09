#ifndef DS_BUBBLE_SORT_TESTS_H_
#define DS_BUBBLE_SORT_TESTS_H_

#include <gtest/gtest.h>
#include <sorting_test_utils.h>
#include <comb_sort.h>



TEST_P(RandomVectorSortTest, comb_sort) {
    TEST_BODY(v,
              DS::comb_sort,
              ASCENDING,
              std::less<TYPE>()
             );
}

TEST_P(RandomVectorSortTest, comb_sort_ascending) {
    TEST_BODY(v,
              DS::comb_sort,
              DESCENDING,
              std::greater<TYPE>()
             );
}
}





#endif //DS_BUBBLE_SORT_TESTS_H_