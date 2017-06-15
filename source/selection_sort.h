

/*
 Author: Davide Spataro
 */

#ifndef DS_SELECTION_SORT_H_
#define DS_SELECTION_SORT_H_

namespace DS {

// CMP_FN has type: D -> D -> bool
template < typename Iterator, typename CMP_FN>
void selection_sort(Iterator s, Iterator e, CMP_FN cmp) {

	for (auto it  = s ; it < e ; it++) {
		auto it_min = it;
		for (auto it1 = it + 1 ; it1 < e ; it1++)
			if (cmp(*it1, *it_min)) {
				it_min = it1;
			}
		swap(*it, *it_min);
	}
}


}// namespace DS

#endif //DS_SELECTION_SORT_H_

