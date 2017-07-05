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

#ifndef DS_INTRO_SORT_H_
#define DS_INTRO_SORT_H_
#include <quick_sort.h>
#include <heap_sort.h>
namespace DS {


// Compare has type: D -> D -> bool
template <typename Iterator, typename Compare>
void intro_sort_hoare_helper(Iterator s, Iterator e, Compare cmp, unsigned int max_depth) {
  if (std::distance(s, e) <= TRIGGER_INSERTION)
    DS::shell_sort_A154393(s, e, cmp);
  else if (max_depth == 0)
    heap_sort(s, e, cmp);
  else {
    const Iterator p = DS::partition_hoare(s, e, cmp);
    intro_sort_hoare_helper(s, p, cmp, max_depth - 1);
    intro_sort_hoare_helper(p + 1, e, cmp, max_depth - 1);
  }
}

// Compare has type: D -> D -> bool
template <typename Iterator, typename Compare>
void intro_sort_lomuto_helper(Iterator s, Iterator e, Compare cmp, unsigned int max_depth) {
  if (std::distance(s, e) <= TRIGGER_INSERTION)
    DS::shell_sort_A154393(s, e, cmp);
  else if (max_depth == 0)
    heap_sort(s, e, cmp);
  else {
    const Iterator p = DS::partition_lomuto(s, e, cmp);
    intro_sort_lomuto_helper(s, p, cmp, max_depth - 1);
    intro_sort_lomuto_helper(p + 1, e, cmp, max_depth - 1);
  }
}

// Compare has type: D -> D -> bool
template <typename Iterator, typename Compare>
void intro_sort_lomuto(Iterator s, Iterator e, Compare cmp) {
  unsigned int max_depth = floor(log(distance(s, e))) * 3;
  intro_sort_lomuto_helper(s, e, cmp, max_depth);
}

// Compare has type: D -> D -> bool
template <typename Iterator, typename Compare>
void intro_sort_hoare(Iterator s, Iterator e, Compare cmp) {
  unsigned int max_depth = floor(log(distance(s, e))) * 3;
  intro_sort_lomuto_helper(s, e, cmp, max_depth);
}




}  // namespace DS

#endif  // DS_INTRO_SORT_H_