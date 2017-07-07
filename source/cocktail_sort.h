/*
 Author: Davide Spataro
 */

#ifndef DS_COCKTAIL_SORT_H_
#define DS_COCKTAIL_SORT_H_

namespace DS {




/////////////////////////////////////////////////
/// @Brief Coctail sort
/// At each iterator the min or max element are at the
/// end of the range. The index of the last swap identifies the beginning
/// of a sorted sequence. We can stop there.
/////////////////////////////////////////////////
// Compare has type: D -> D -> bool
template < typename Iterator, typename Compare>
void cocktail_sort(Iterator s, Iterator e, Compare cmp) {
	const auto d = distance(s, e);
	if (d <= 1)
		return;

	Iterator lower_limit(s);
	Iterator upper_limit(e - 1);

	bool go = true;
	while (true ) {
		Iterator new_upper_limit(s);
		Iterator it1 (s);
		Iterator it2 (s + 1);
		for (; it2 <= upper_limit; ++it1, ++it2)
			if (cmp(*it2, *it1)) {
				std::swap(*it2, *it1);
				new_upper_limit = it1;
			}

			if(new_upper_limit==s)
				break; //sorted no swaps took place

		upper_limit = new_upper_limit;

//other way round
		//at least 1 element below new_upper_limit
		Iterator new_lower_limit(new_upper_limit);
		it1 = new_upper_limit;
		it2 = lower_limit-1;
		for (; it2 >= lower_limit; --it1, --it2){
			if (cmp(*it1, *it2)) { //opposite order w.t.r. to the previous round
				std::swap(*it1, *it2);
				new_lower_limit = it1;
			}
		}

		if(new_lower_limit == new_upper_limit)
			break;


	}
}

}// namespace DS

#endif //DS_BUBBLE_SORT_H_