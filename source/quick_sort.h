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
   Partition the array around a pivot element p.
   p gets its final position in the array so that all the elements
   lower than it lie on lower indices. Same goes for greater indices that
   lie on greater indices.
   This particular implementation is the so called Lomuto partition scheme
*/
template <typename Iterator, typename Compare>
inline const Iterator partition_lomuto(Iterator s, Iterator e, Compare cmp) {
  const Iterator pivot_it = e - 1; //the last element
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

/* Partition the elements of A, such that you first have elements smaller than
 * "pivot", followed by eleemnts larger than "pivot". Return the last poistion of an
 * element smaller or equal to "pivot".
 */
template <typename Iterator, typename Compare>
inline const Iterator partition_hoare(Iterator s, Iterator e, Compare cmp) {
  const Iterator pivot_it = s + distance(s, e - 1) / 2;
  const auto pivot = *pivot_it;
  // move the mid point value to the front.
  std::swap(*pivot_it, *s);
  Iterator i = s + 1;
  Iterator j = e - 1;
  while (i <= j) {
    while (i <= j && cmp(*i, pivot))
      i++;

    while (i <= j && !cmp(*j, pivot))
      j--;

    if (i < j)
      std::swap(*i, *j);
  }
  std::swap(*(i - 1), *s);
 // std::cout<<"pivot is"<<*(i-1)<<"\n" ;
  return (i - 1);
}

constexpr int TRIGGER_INSERTION = 16;
// Compare has type: D -> D -> bool
template <typename Iterator, typename Compare>
void quicksort_hoare(/*const Iterator begin,*/const Iterator s, const Iterator e, Compare cmp) {
 /*  auto index= [](auto begin, auto it) {
    return distance(it,begin);
   };
   static int i=0;
  for(int k=0;k<i;k++)
    std::cout<<"\t";
  std::cout<<index(begin,s)<<" - "<<index(begin,e)<<"\n";
  i++;*/
  if (std::distance(s, e) <= TRIGGER_INSERTION)
    DS::insertion_sort(s, e, cmp);
  else {
    const Iterator p = DS::partition_hoare(s, e, cmp);
    quicksort_hoare(/*begin,*/s, p, cmp);
    quicksort_hoare(/*begin,*/p + 1, e, cmp);
  }
  //i--;
}

// Compare has type: D -> D -> bool
template <typename Iterator, typename Compare>
void quicksort_lomuto(Iterator s, Iterator e, Compare cmp) {
  if (std::distance(s, e) <= TRIGGER_INSERTION)
    DS::insertion_sort(s, e, cmp);
  else {
    const Iterator p = DS::partition_lomuto(s, e, cmp);
    quicksort_lomuto(s, p, cmp);
    quicksort_lomuto(p + 1, e, cmp);
  }
}

// tail recursive version
// Compare has type: D -> D -> bool
template <typename Iterator, typename Compare>
void quicksort_tail_recursive(Iterator s, Iterator e, Compare cmp) {
  if (std::distance(s, e) <= TRIGGER_INSERTION)
    DS::insertion_sort(s, e, cmp);
  else {
    while (s < e) {
      const Iterator p = DS::partition_hoare(s, e, cmp);
      quicksort_tail_recursive(s, p, cmp);
      s = p + 1;
    }
  }
}

/*template <typename Iterator, typename Compare>
void quicksort_tail_recursive(Iterator s, Iterator e, Compare cmp)
{
  static int i=0;
  i++;
  if (std::distance(s, e) <= TRIGGER_INSERTION)
    DS::insertion_sort(s, e, cmp);
  else {
    while (s < e) {
      std::cout<<"here"<<i<<"\n";
      const Iterator p = DS::partition_lomuto(s, e, cmp);

      if (distance(s, p) <= distance(p, e))
      {
        quicksort_tail_recursive(s, p, cmp);
        s = p;
      } else {
        quicksort_tail_recursive(p, e, cmp);
        e = p - 1;
      }
    }

  }

}*/





using namespace std;


}  // namespace DS

#endif  // DS_QUICK_SORT_TESTS_H_