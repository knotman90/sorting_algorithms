/*
 Author: Davide Spataro
 */

#ifndef DS_BUBBLE_SORT_H_
#define DS_BUBBLE_SORT_H_

namespace DS {

// Compare has type: D -> D -> bool
template < typename Iterator, typename Compare>
void bubblesort(Iterator s, Iterator e, Compare cmp) {
	if (std::distance(s, e) <= 0)
		return;
	auto it1 = s;
	for (; it1 != e; it1++) {
		auto it2 = s;
		for (; it2 != it1; it2++)
			if (cmp(*it1, *it2))
				std::swap(*it1, *it2);
	}
}

}// namespace DS

#endif //DS_BUBBLE_SORT_H_