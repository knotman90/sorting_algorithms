/**
 *  @file    quick_sort.h
 *  @author  Davide Spataro (knotman90)
 *
 *  @brief CSC 112, Implementation of the quicksort algorithm in different
 *         flavors (iterative, recursive suing different pivoting schemes).
 *
 *  @section DESCRIPTION
 *
 */

#ifndef DS_QUICK_SORT_H_
#define DS_QUICK_SORT_H_
#include <insertion_sort.h>
namespace DS {
/**
   @brief Return an Iterator to the Pivot element

   Return an Iterator to the Pivot element in the range [s,e]
   This particular implementation is the so called Lomuto partition scheme
*/
template<typename Iterator, typename CMP_FN>
inline const Iterator select_pivot(const Iterator s, const Iterator e, CMP_FN cmp) {
    return e - 1;
}


template<typename Iterator, typename CMP_FN>
Iterator partition(Iterator s, Iterator e, CMP_FN cmp) {

    const Iterator pivot_it = DS::select_pivot(s, e, cmp);
    swap(*pivot_it, *(e - 1)); //put pivot in the last position
    const auto pivot = *pivot_it;
    Iterator insert_it = s;
    for (Iterator j = s ; j < e ; j++)
        if (cmp(*j, pivot) ) {
            swap(*insert_it, *j);
            insert_it++;

        }
    swap(*insert_it, *pivot_it);
    return insert_it;
}

constexpr int TRIGGER_INSERTION = 7;
// CMP_FN has type: D -> D -> bool
template < typename Iterator, typename CMP_FN>
inline void quicksort(Iterator s, Iterator e, CMP_FN cmp) {

    if (std::distance(s, e) <= TRIGGER_INSERTION)
        DS::insertion_sort(s, e, cmp);
    else {
        Iterator p = DS::partition(s, e, cmp);
        quicksort(s, p, cmp);
        quicksort(p + 1, e, cmp);
    }
}


/*
//tail recursive version
// CMP_FN has type: D -> D -> bool
template < typename Container, typename CMP_FN>
inline void quicksort_tr(Container& v,  int s,const int e, CMP_FN cmp) {
    if(e - s <= TRIGGER_INSERTION)
        DS::insertionsort(v,s,e,cmp);
    else{
        while(s < e){
        const int p = partition(v,s,e,cmp);
        quicksort(v,s,p,cmp);
        s = p+1;
        }
    }
}*/

}//namespace DS

#endif //DS_QUICK_SORT_TESTS_H_