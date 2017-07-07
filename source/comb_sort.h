/*
 Author: Davide Spataro
 */

#ifndef DS_COMBO_SORT_H_
#define DS_COMBO_SORT_H_

namespace DS {

/////////////////////////////////////////////////
/// @Brief Combo sort.
/// Uses an idea similar to shell sort in order to
/// address the problem or "turtles".
/////////////////////////////////////////////////
// Compare has type: D -> D -> bool
template < typename Iterator, typename Compare>
void comb_sort(Iterator s, Iterator e, Compare cmp) {
	using std::swap;
	auto d = distance(s, e);
	if (d <= 1)
		return;
	
	auto gap = d;
	const double k = 1.3; //gap shrink factor 
	bool go = true;
	while (go) {
		gap = floor((double)gap / k);
		if (gap < 1) {
			go = false; //is no swap take place we are done
			gap = 1; //force gap to one
		}
		//std::cout<<gap<<std::endl;
		Iterator it1(s);
		Iterator it2(s);
		while (distance(it2, e) > gap) {
			it2 += gap; //always gap position ahead of it1
			if (cmp(*it2, *it1)) {
				swap(*it2, *it1);
				go = true; //gap=1 && we gotta continue;
			}
			it1 += gap;
		}
	}

}
}// namespace DS

#endif //DS_COMBO_SORT_H_