/*
 Author: Davide Spataro
 */

#ifndef DS_SELECTION_SORT_H_
#define DS_SELECTION_SORT_H_

namespace DS {

// Compare has type: D -> D -> bool
template < typename Iterator, typename Compare>
void selection_sort(Iterator s, Iterator e, Compare cmp) {

	for (auto it  = s ; it < e ; it++) {
		auto it_min = it;
		for (auto it1 = it + 1 ; it1 < e ; it1++)
			if (cmp(*it1, *it_min)) {
				it_min = it1;
			}
		std::swap(*it, *it_min);
	}
}


}// namespace DS

#endif //DS_SELECTION_SORT_H_

