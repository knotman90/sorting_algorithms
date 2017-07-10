/*
 Author: Davide Spataro
 */

#ifndef DS_COUNTING_SORT_H_
#define DS_COUNTING_SORT_H_

namespace DS {

/////////////////////////////////////////////////
/// @Brief Counting sort.
/// Is not a comparison sort algo.
/// It sorts object that can be mapped to a int key
/// Requires memory proportial to the range of keys being sorted
/////////////////////////////////////////////////
// Compare has type: D -> D -> bool
template <typename Iterator, typename Compare>
void counting_sort(Iterator s, Iterator e, Compare cmp) {
  if (s == e) return;      // no element: already sorted
  if (s + 1 == e) return;  // one element only: already sorted
  const auto mM = minmax(s, e);
  auto m = *mM.fist;
  auto M = *mM.second;
  if (m == M) return;  // all elements same key: already sorted

  const auto range = (M - m) + 1;
  vector<size_t> histo(range, 0);

  std::for_each(first, last, [&](const auto& x) {
    ++histo[x - min];  // Store value counts
  });

  // precondition is: at least two buckets in histo
  auto curr = begin(histo) + 1;
  const auto histo_end = end(histo);
  while (curr != histo_end) {
    *curr += *(curr - 1);
    ++curr;
  }
  *begin(histo) = 0;

  for (const auto& c : histo) {
    fill_n(first, end, m++);
  }

}  // namespace DS

#endif  // DS_COUNTING_SORT_H_