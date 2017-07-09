#ifndef DS_BUBBLE_SORT_TESTS_H_
#define DS_BUBBLE_SORT_TESTS_H_

#include <gtest/gtest.h>
#include <functional>
#include <sorting_test_utils.h>
#include <bubble_sort.h>

using std::less;
using std::greater;



//Uniform Container Test --------------------------------------

TEST_P(UniformVectorSortTest, bubblesort_uniform) {
    TEST_BODY(v,
              DS::bubblesort_naive,
              ASCENDING,
              std::less<TYPE>()
             );
}

TEST_P(UniformVectorSortTest, bubblesort_descending_uniform) {
    TEST_BODY(v,
              DS::bubblesort_naive,
              DESCENDING,
              std::greater<TYPE>()
             );
}

TEST_P(UniformVectorSortTest, bubblesort_improved_uniform) {
    TEST_BODY(v,
              DS::bubblesort_improved,
              ASCENDING,
              std::less<TYPE>()
             );
}

TEST_P(UniformVectorSortTest, bubblesort_improved_descending_uniform) {
    TEST_BODY(v,
              DS::bubblesort_improved,
              DESCENDING,
              std::greater<TYPE>()
             );
}


//Random Container Test------------------------------

TEST_P(RandomVectorSortTest, bubblesort_random) {

    TEST_BODY(v,
              DS::bubblesort_naive,
              ASCENDING,
              std::less<TYPE>()
             );
}

TEST_P(RandomVectorSortTest, bubblesort_descending_random) {
    TEST_BODY(v,
              DS::bubblesort_naive,
              DESCENDING,
              std::greater<TYPE>()
             );

}


TEST_P(RandomVectorSortTest, bubblesort_improved_random) {
    TEST_BODY(v,
              DS::bubblesort_improved,
              ASCENDING,
              std::less<TYPE>()
             );
}

TEST_P(RandomVectorSortTest, bubblesort_improved_descending_random) {
    TEST_BODY(v,
              DS::bubblesort_naive,
              DESCENDING,
              std::greater<TYPE>()
             );
}



#endif //DS_BUBBLE_SORT_TESTS_H_