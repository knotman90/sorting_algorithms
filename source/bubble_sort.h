/*
 Author: Davide Spataro
 */

#ifndef DS_BUBBLE_SORT_H_
#define DS_BUBBLE_SORT_H_
#include<common.h>
namespace DS {

// Compare has type: D -> D -> bool
template < typename Iterator, typename Compare>
void bubblesort_naive(Iterator s, Iterator e, Compare cmp) {
	if (std::distance(s, e) <= 1)
		return;
	bool go = true;
	while (go) {
		go = false;
		Iterator it2(s), it3(s + 1);
		for (; it3 != e; it2++, it3++)
			if (cmp(*it3, *it2)) {
				std::swap(*it3, *it2);
				go = true;
			}
	}

}

/////////////////////////////////////////////////
/// @Brief Bubble sort improved.
/// At each iterator the min or max element are at the
/// end of the range. The index of the last swap identifies the beginning
/// of a sorted sequence. We can stop there.
/////////////////////////////////////////////////
// Compare has type: D -> D -> bool
template < typename Iterator, typename Compare>
void bubblesort_improved(Iterator s, Iterator e, Compare cmp) {
	const auto d = distance(s, e);
	if (d <= 1)
		return;

	Iterator upper_limit(e - 1);
	while (upper_limit != s) {
		Iterator new_upper_limit(s);
		Iterator it1 (s);
		Iterator it2 (s + 1);
		for (; it2 <= upper_limit; ++it1, ++it2)
			if (cmp(*it2, *it1)) {
				std::swap(*it2, *it1);
				new_upper_limit = it1;
			}

		upper_limit = new_upper_limit;
	}
}

}// namespace DS

#endif //DS_BUBBLE_SORT_H_