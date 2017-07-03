/*
 Author: Davide Spataro
 */

#ifndef DS_HEAP_SORT_H_
#define DS_HEAP_SORT_H_

namespace DS {

/////////////////////////////////////////////////
/// @Brief Binary Heap: return the index 
///	of the left child of the element with index idx
/// Note that it can computed as (idx<<1) 
/// Compiler should be able to generate  one istruction inlined
/////////////////////////////////////////////////
template<class INDEX , std::enable_if<
							std::is_integral<INDEX>::value,INDEX> >
inline INDEX left_child(const INDEX idx){
	return (static_cast<INDEX>(2))*idx;
}


/////////////////////////////////////////////////
/// @Brief Binary Heap: return the index 
///	of the right child of the element with index idx
// Note that it can computed as (idx<<1)|1
//Compiler should be able to generate  one istruction inlined
/////////////////////////////////////////////////
template<class INDEX , std::enable_if<
							std::is_integral<INDEX>::value,INDEX> >
inline INDEX right_child(const INDEX idx){
	return left_child(idx)+static_cast<INDEX>(1);
}


/////////////////////////////////////////////////
/// @Brief Binary Heap: return the index 
///	of the parent of the element with index idx
/// Note that it can computed as (idx>>1) 
/// Compiler should be able to generate  one istruction inlined
/////////////////////////////////////////////////
template<class INDEX , std::enable_if<
							std::is_integral<INDEX>::value,INDEX> >
inline INDEX parent(const INDEX idx){
	return idx/(static_cast<INDEX>(2));
}


// CMP_FN has type: D -> D -> bool
template < typename Iterator, typename CMP_FN>
void heap_sort(Iterator s, Iterator e, CMP_FN cmp) {
	
}

void a(){
	parent(1);
}

}// namespace DS

#endif //DS_HEAP_SORT_H_