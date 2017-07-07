/*
 Author: Davide Spataro
 */

#ifndef DS_INSERTION_SORT_H_
#define DS_INSERTION_SORT_H_

#include <shell_sort.h> // insertion_sort_gap
namespace DS {

template < typename Iterator, typename Compare>
void insertion_sort(Iterator s, Iterator e, Compare cmp) {
	DS::insertion_sort_gap(s,e,cmp,1);
}

// Compare has type: D -> D -> bool
template < typename Iterator, typename Compare>
void maybeis_insertion_sort(Iterator s, Iterator e, Compare cmp) {
	if (std::distance(s, e) <= 1)
		return;
	auto it1 = s + 1;
	for (; it1 != e; it1++) {
		auto it2 = s;
		for (; it2 != it1; it2++)
			if (cmp(*it1, *it2))
				std::swap(*it1, *it2);
	}
}

// Compare has type: D -> D -> bool
/*template < typename Iterator, typename Compare>
void insertion_sort(Iterator s, Iterator e, Compare cmp) {
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
}*/

}// namespace DS

#endif //DS_INSERTION_SORT_H_