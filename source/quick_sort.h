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


int partition(int *arr, const int left, const int right) {
    const int mid = left + (right - left) / 2;
    const int pivot = arr[mid];
    // move the mid point value to the front.
    std::swap(arr[mid],arr[left]);
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while(i <= j && arr[i] <= pivot) {
            i++;
        }

        while(i <= j && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i - 1],arr[left]);
    return i - 1;
}

template <typename Iterator, typename CMP_FN>
void quicksort2(Iterator s, Iterator e, CMP_FN cmp) {
  Iterator pivot_it = e - 1;
  std::swap(*s, *pivot_it);  // move pivot at the front
  Iterator i = s + 1, j = e;
  auto pivot = *s;
  while (i <= j) {
    while (*i <= pivot) i++;
    while (*j > pivot) j--;
    if (i < j) {
      std::swap(*i, *j);
      i++;
      j--;
    }
  }
  // Recursion

  if (s < j) quicksort2(s, j, cmp);

  if (i < e) quicksort2(i, e, cmp);
}

/**
   @brief Return an Iterator to the Pivot element

   Return an Iterator to the Pivot element in the range [s,e]
   This particular implementation is the so called Lomuto partition scheme
*/
template <typename Iterator, typename CMP_FN>
inline const Iterator select_pivot(const Iterator s, const Iterator e,
                                   CMP_FN cmp) {
  return e-1;
}

template <typename Iterator, typename CMP_FN>
Iterator partition(Iterator s, Iterator e, CMP_FN cmp) {
  const Iterator pivot_it = DS::select_pivot(s, e, cmp);
  std::swap(*pivot_it, *(e - 1));  // put pivot in the last position
  const auto pivot = *pivot_it;
  Iterator insert_it = s;
  for (Iterator j = s; j < e; j++)
    if (cmp(*j, pivot)) {
      std::swap(*insert_it, *j);
      insert_it++;
    }
  std::swap(*insert_it, *pivot_it);
  return insert_it;
}

constexpr int TRIGGER_INSERTION = 5;
// CMP_FN has type: D -> D -> bool
template <typename Iterator, typename CMP_FN>
void quicksort(Iterator s, Iterator e, CMP_FN cmp) {
  if (std::distance(s, e) <= TRIGGER_INSERTION)
    DS::insertion_sort(s, e, cmp);
  else {
    const Iterator p = DS::partition(s, e, cmp);
    quicksort(s, p, cmp);
    quicksort(p + 1, e, cmp);
  }
}
/*
Quicksort(A, p, r)
{
 while (p < r)
 {
  q: <- Partition(A, p, r)
  Quicksort(A, p, q)
  p: <- q+1
 }
}*/
// tail recursive version
// CMP_FN has type: D -> D -> bool
template <typename Iterator, typename CMP_FN>
void quicksort_tail_recursive(Iterator s, Iterator e, CMP_FN cmp) {
  if (std::distance(s, e) <= TRIGGER_INSERTION)
    DS::insertion_sort(s, e, cmp);
  else {
    while (s < e) {
      const Iterator p = DS::partition(s, e, cmp);
      quicksort_tail_recursive(s, p, cmp);
      s = p + 1;
    }
  }
}

}  // namespace DS

#endif  // DS_QUICK_SORT_TESTS_H_