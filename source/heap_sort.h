/*
 Author: Davide Spataro
 */

#ifndef DS_HEAP_SORT_H_
#define DS_HEAP_SORT_H_

#include <type_traits>
namespace DS {

#define LEFT_CHILD(BEGIN, IDX)  (std::advance(IDX, std::distance(BEGIN, IDX) + 1))
#define RIGHT_CHILD(BEGIN, IDX) (std::advance(IDX, std::distance(BEGIN, IDX) + 2))
/////////////////////////////////////////////////
/// @Brief Binary Heap: return the index
/// of the left child of the element with index idx
/// Note that it can computed as (idx<<1)
/// Compiler should be able to generate  one istruction inlined
/////////////////////////////////////////////////
template <typename Iterator>
inline Iterator left_child(const Iterator begin, const Iterator end,
                           Iterator idx) {
  const auto d_idx_beg = distance(begin, idx);
  if (distance(idx, end - 2) >= d_idx_beg)
    return idx + (d_idx_beg + 1);
  else
    return end;
}

/////////////////////////////////////////////////
/// @Brief Binary Heap: return the index
/// of the right child of the element with index idx
// Note that it can computed as (idx<<1)|1
//Compiler should be able to generate  one istruction inlined
/////////////////////////////////////////////////
template <class Iterator>
inline Iterator right_child(const Iterator begin, const Iterator end,
                            Iterator idx) {
  const auto d_idx_beg = distance(begin, idx);
  if (distance(idx, end - 3) >= d_idx_beg)
    return idx + (d_idx_beg + 2);
  else
    return end;
}

/////////////////////////////////////////////////
/// @Brief Binary Heap: return the index
/// of the parent of the element with index idx
/// Note that it can computed as (idx>>1)
/// Compiler should be able to generate  one istruction inlined
/////////////////////////////////////////////////
template <class Iterator>
inline Iterator parent(Iterator begin, Iterator idx) {
  return begin + std::distance(begin + 1, idx) / 2;
}

/////////////////////////////////////////////////
/// @Brief Given an iterator to an element
/// idx of the heap that might not satisfy the heap property
/// but with valid heaps rooted at its children it enforces
/// the heap property on the whole dataset rooted at idx
/// !cmp is used because the we need reversed ordere.
/// LT should produce and ascending order.
/////////////////////////////////////////////////
template <typename Iterator, typename Compare>
void sift_down_l(const Iterator begin, const Iterator end, Iterator idx,
                 Compare cmp) {
  const Iterator left (left_child(begin, end, idx));
  const Iterator right (right_child(begin, end, idx));
  Iterator candidate (idx);
  if (left < end && !cmp(*left, *idx)) candidate = left;

  if (right < end && !cmp(*right, *candidate)) candidate = right;

  if (candidate != idx) {
    std::swap(*candidate, *idx);
    sift_down_l(begin, end, candidate, cmp);
  }
}

template <typename Iterator, typename Compare>
inline void sift_down(const Iterator begin, const Iterator end, Iterator idx,
                      Compare cmp) {
  bool go = true;
  while (go) {
    const Iterator left(left_child(begin, end, idx));
    const Iterator right(right_child(begin, end, idx));
    Iterator candidate(idx);
    // this if relies on if short circuiting cmp has to be guarded for segfault
    if (left < end && !cmp(*left, *idx))
      candidate = left;
    //this if relies on if short circuiting cmp has to be guarded for segfault
    if (right < end && !cmp(*right, *candidate))
      candidate = right;

    if (candidate != idx) {
      std::swap(*candidate, *idx);
      idx = candidate;
    } else
      break;
  }
}

/////////////////////////////////////////////////
/// @Brief Transform a range of elements [begin,end[
/// into a binary heap. The heap property is encapsulated in cmp
/// Assume [begin,end[ contains at least one element
/////////////////////////////////////////////////
template <typename Iterator, typename Compare>
inline void make_heap(const Iterator begin, const Iterator end, Compare cmp) {
  const auto d = distance(begin, end) / 2;
  for (Iterator s = begin + d; s >= begin; s--)
    sift_down(begin, end, s, cmp);

}


/////////////////////////////////////////////////
/// @Brief Heap sort implementation (inspiration from Cormen et al Book)
// Compare has type: D -> D -> bool
/////////////////////////////////////////////////
template <typename Iterator, typename Compare>
void heap_sort(Iterator s, Iterator e, Compare cmp) {
  auto d = std::distance(s, e);
  if (d <= 1)
    return;

  DS::make_heap(s, e, cmp);
  while (d--) {
    e--;
    std::swap(*s, *e);
    sift_down(s, e, s, cmp);
  }
}
/*
void a(){
        std::vector<int> b = {10,2,3,4,5,6,7,8,9};
std::srand ( unsigned ( std::time(0) ) );
        DS::print(begin(b),end(b));

        for(auto s = begin(b)+1; s!= b.end(); s++)
                std::cout<<*s<<" "<<*(parent(begin(b),s))<<std::endl;

        for(auto s = begin(b); s<begin(b)+std::distance(begin(b),end(b))/2; s++)
                std::cout<<*s<<" "<<*(left_child(begin(b),end(b),s))<<" "<<*(right_child(begin(b),end(b),s))<<std::endl;
        std::cout<<"sift_down\n";

        sift_down(b.begin(),b.end(), b.begin(),DS::gt<int>);

        DS::print(begin(b),end(b));

        std::cout<<"make_heap\n";
        b.clear();
        int n = 0;
        b.resize(15);
    std::generate(b.begin(), b.end(), [&n]{ return n++; });
        DS::print(begin(b),end(b));
        std::random_shuffle(begin(b),end(b));
        make_heap(begin(b),end(b),DS::lt<int>);
        DS::print(begin(b),end(b));
std::cout<<"heap sorting\n";
        heap_sort(begin(b),end(b),DS::lt<int>);
        DS::print(begin(b),end(b));
}
*/
}// namespace DS

#endif //DS_HEAP_SORT_H_