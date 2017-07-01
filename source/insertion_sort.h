/*
 Author: Davide Spataro
 */

#ifndef DS_INSERTION_SORT_H_
#define DS_INSERTION_SORT_H_

namespace DS {

// CMP_FN has type: D -> D -> bool
template < typename Iterator, typename CMP_FN>
void insertion_sort(Iterator s, Iterator e, CMP_FN cmp) {
	if (std::distance(s, e) <= 1)
		return;
	for (auto it = s + 1 ; it < e ; it++) {
		auto it_curr = it;
		auto it_prec = it - 1;
		while ( it_prec >= s && cmp(*it_curr, *it_prec)  ) {
			std::swap(*it_curr, *it_prec);
			it_prec--;
			it_curr--;
		}
	}
}

}// namespace DS

#endif //DS_INSERTION_SORT_H_