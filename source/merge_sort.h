
/*
Author: Davide Spataro
*/

#ifndef DS_MERGE_SORT_H_
#define DS_MERGE_SORT_H_

#include <vector>
#include <insertion_sort.h>
namespace DS {
//-------MERGSORT---------------------

// CMP_FN has type: D -> D -> bool
//[s1,e1] and [e1+1,e2] are two ordered sequences. This methods reaggarne the whole
// interval [s1,e2] in a sorted sequence
template < typename Container, typename Iterator, typename CMP_FN>
void merge(Container& scratch,  Iterator s1,  Iterator e1,  Iterator e2, CMP_FN cmp, Iterator scratch_s) {
	Iterator s2 = e1 + 1;
	Iterator startv = s1;
	Iterator starts = scratch_s;
	while (s1 <= e1 && s2 <= e2) {
		if ( cmp(*s1, *s2) ) {
			*scratch_s = *s1;
			s1++;
		} else {
			*scratch_s = *s2;
			s2++;
		}
		scratch_s++;
	}

	while (s1 <= e1) {
		*scratch_s = *s1;
		s1++;
		scratch_s++;
	}
	while (s2 <= e2) {
		*scratch_s = *s2;
		s2++;
		scratch_s++;
	}

	const auto nit = std::distance(startv, e2);
	for (auto i = 0 ; i <= nit ; i++, startv++, starts++)
		*startv = *starts;

//print(ALL(scratch));
}


constexpr int TRIGGER_INSERTIONSORT = 4;

// CMP_FN has type: D -> D -> bool
//range is [s,e] (e is in the range)
template < typename Container, typename Iterator, typename CMP_FN>
void mergesort_helper(Container& scratch, Iterator s, Iterator e, CMP_FN cmp, Iterator scratch_s) {
	if (std::distance(s, e) <= TRIGGER_INSERTIONSORT)
		DS::insertion_sort( s, e + 1, cmp);
	else { // if (distance(s,e)>TRIGGER_INSERTIONSORT) {
		Iterator midpoint = s;
		Iterator scratch_s_ori = scratch_s;
		std::advance(midpoint, std::distance(s, e) / 2);
		//sort the first half
		mergesort_helper(scratch, s , midpoint, cmp, scratch_s);

		//move the scratch iterator
		std::advance(scratch_s, std::distance(s, midpoint + 1));
		//sort the second half
		mergesort_helper(scratch, midpoint + 1	, e , cmp, scratch_s);
		
		merge(scratch, s, midpoint, e, cmp, scratch_s_ori);
	}
}


// CMP_FN has type: D -> D -> bool
template < typename Iterator, typename CMP_FN>
void mergesort(Iterator s, Iterator e, CMP_FN cmp) {//(Container& v, const int s, const int e, CMP_FN cmp) {
	using type = typename std::iterator_traits<Iterator>::value_type;
	std::vector<type> scratch(std::distance(s, e));
	mergesort_helper(scratch, s, e - 1, cmp, scratch.begin());
}

}//namespace DS

#endif //DS_MERGE_SORT_H_
