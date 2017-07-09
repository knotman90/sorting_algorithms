#ifndef DS_BUBBLE_SORT_TESTS_H_
#define DS_BUBBLE_SORT_TESTS_H_

#include <gtest/gtest.h>
#include <sorting_test_utils.h>
#include <cocktail_sort.h>
//#include <common.h>


TEST_P(RandomVectorSortTest, cocktail) {
    TEST_BODY(v,
              DS::cocktail_sort,
              ASCENDING,
              std::less<TYPE>()
             );

}

TEST_P(RandomVectorSortTest, cocktail_ascending) {
    TEST_BODY(v,
              DS::cocktail_sort,
              DESCENDING,
              std::greater<TYPE>()
             );
}





#endif //DS_BUBBLE_SORT_TESTS_H_