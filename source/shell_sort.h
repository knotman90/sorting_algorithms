/*
 Author: Davide Spataro
 */

#ifndef DS_SHELL_SORT_H_
#define DS_SHELL_SORT_H_

namespace DS {

static const std::ptrdiff_t sedgewick_incerpi_sequence[] = {
    70223210512, 30095661648, 13166851971, 5138283696, 2085837936, 852913488,
    343669872,   114556624,   49095696,    21479367,   8382192,    3402672,
    1391376,     463792,      198768,      86961,      33936,      13776,
    4592,        1968,        861,         336,        112,        48,
    21,          7,           3,           1};

static const std::ptrdiff_t sedgewick_sequence[] = {1270932914164,
                                           423644304721,
                                           141214768240,
                                           47071589413,
                                           15690529804,
                                           5230176601,
                                           1743392200,
                                           581130733,
                                           193710244,
                                           64570081,
                                           21523360,
                                           7174453,
                                           2391484,
                                           797161,
                                           265720,
                                           88573,
                                           29524,
                                           9841,
                                           3280,
                                           1093,
                                           364,
                                           121,
                                           40,
                                           13,
                                           4,
                                           1,
                                           0};

static const std::ptrdiff_t A154393_sequence[] = {5977203382848010,
                                                  1259504788813791,
                                                  265400424550505,
                                                  55924666344750,
                                                  11784338112247,
                                                  2483172990911,
                                                  523249458736,
                                                  110258103799,
                                                  23233383508,
                                                  4895689348,
                                                  1031612713,
                                                  217378076,
                                                  45806244,
                                                  9651787,
                                                  2034035,
                                                  428481,
                                                  90358,
                                                  19001,
                                                  4025,
                                                  836,
                                                  182,
                                                  34,
                                                  9,
                                                  1};

static const std::ptrdiff_t fibonacci_sequence[] = {
    0,       1,       1,       2,       3,        5,        8,       13,
    21,      34,      55,      89,      144,      233,      377,     610,
    987,     1597,    2584,    4181,    6765,     10946,    17711,   28657,
    46368,   75025,   121393,  196418,  317811,   514229,   832040,  1346269,
    2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169};

// Compare has type: D -> D -> bool
template <typename Gap , typename Iterator, typename Compare>
void insertion_sort_gap(Iterator s, Iterator e, Compare cmp, const Gap& gap) {
	
	if (std::distance(s, e) <= gap)
		return;
	for (auto it = s + gap ; it < e ; it++) {
		auto it_curr = it;
		auto it_prec = it - gap;
		while ( it_prec >= s && cmp(*it_curr, *it_prec)  ) {
			std::swap(*it_curr, *it_prec);
			it_prec-=gap;
			it_curr-=gap;
		}
	}
}

// Compare has type: D -> D -> bool
template <typename Gap_Sequence , typename Iterator, typename Compare>
void shell_sort(Iterator s, Iterator e, Compare cmp, const Gap_Sequence& gap_sequence) {
	for(const auto gap : gap_sequence)
		DS::insertion_sort_gap(s,e,cmp,gap);
}


//----shellsort on build-in gap sequences
template < typename Iterator, typename Compare>
void shell_sort_A154393(Iterator s, Iterator e, Compare cmp) {
	return shell_sort(s,e,cmp,A154393_sequence);
}

//----shellsort on build-in gap sequences
template < typename Iterator, typename Compare>
void shell_sort_sedgewick(Iterator s, Iterator e, Compare cmp) {
	return shell_sort(s,e,cmp,sedgewick_sequence);
}

//----shellsort on build-in gap sequences
template < typename Iterator, typename Compare>
void shell_sort_sedgewick_incerpi(Iterator s, Iterator e, Compare cmp) {
	return shell_sort(s,e,cmp,sedgewick_incerpi_sequence);
}

//----shellsort on build-in gap sequences
template < typename Iterator, typename Compare>
void shell_sort_fibonacci(Iterator s, Iterator e, Compare cmp) {
	return shell_sort(s,e,cmp,fibonacci_sequence);
}





}// namespace DS

#endif //DS_SHELL_SORT_H_