/*
 Author: Davide Spataro
 */

#ifndef DS_HEAP_SORT_H_
#define DS_HEAP_SORT_H_

#include <type_traits>
namespace DS {

/////////////////////////////////////////////////
/// @Brief Binary Heap: return the index 
///	of the left child of the element with index idx
/// Note that it can computed as (idx<<1) 
/// Compiler should be able to generate  one istruction inlined
/////////////////////////////////////////////////
template<typename Iterator >//, std::enable_if< std::is_integral<INDEX>::value,INDEX> >
inline Iterator left_child(const Iterator begin , Iterator idx){
	 std::advance(idx, std::distance(begin,idx)+1 );
	 return idx;
	
}


/////////////////////////////////////////////////
/// @Brief Binary Heap: return the index 
///	of the right child of the element with index idx
// Note that it can computed as (idx<<1)|1
//Compiler should be able to generate  one istruction inlined
/////////////////////////////////////////////////
template<class Iterator >//, std::enable_if<std::is_integral<INDEX>::value,INDEX> >
inline Iterator right_child(const Iterator begin, Iterator idx){
	return left_child(begin,idx)+1;
}


/////////////////////////////////////////////////
/// @Brief Binary Heap: return the index 
///	of the parent of the element with index idx
/// Note that it can computed as (idx>>1) 
/// Compiler should be able to generate  one istruction inlined
/////////////////////////////////////////////////
template<class Iterator >//, std::enable_if<std::is_integral<INDEX>::value,INDEX> >
inline Iterator parent( Iterator begin, Iterator idx){
	auto d = std::distance(begin+1,idx)/2;
	std::advance(begin,d);
	return begin;
}


/////////////////////////////////////////////////
/// @Brief Transform a range of elements [begin,end[ 
///	into a binary heap. The heap property is encapsulated in cmp
/////////////////////////////////////////////////
template<typename Iterator, typename CMP_FN>
void build_heap(const Iterator begin, const Iterator end, CMP_FN cmp){


/////////////////////////////////////////////////
/// @Brief Given an iterator to an element 
///	idx of the heap that might not satisfy the heap property
/// but with valid heaps rooted at its children it enforces 
/// the heap property on the whole dataset rooted at idx
/////////////////////////////////////////////////
template<typename Iterator, typename CMP_FN>
void heapify(const Iterator begin, const Iterator end, Iterator idx, CMP_FN cmp){
	Iterator left = left_child(begin,idx);
	Iterator right = right_child(begin,idx);
	Iterator candidate = idx;
	if(left < end && cmp(*left,*idx))
		candidate = left;

	if(right < end && cmp(*right,*candidate))
		candidate=right;

	if(candidate != idx){
		std::swap(*candidate,*idx);
		heapify(begin,end,candidate,cmp);
	}
}

// CMP_FN has type: D -> D -> bool
/*template < typename Iterator, typename CMP_FN>
void heap_sort(Iterator s, Iterator e, CMP_FN cmp) {
	
}*/

void a(){
	
	vector<int> b = {10,2,3,4,5,6,7,8,9};
	for(const auto el : b)
		std::cout<<el<<" ";
std::cout<<std::endl;
	for(auto s = begin(b)+1; s!= b.end(); s++)
		std::cout<<*s<<" "<<*(parent(begin(b),s))<<std::endl;

	for(auto s = begin(b); s<begin(b)+std::distance(begin(b),end(b))/2; s++)
		std::cout<<*s<<" "<<*(left_child(begin(b),s))<<" "<<*(right_child(begin(b),s))<<std::endl;
	heapify(b.begin(),b.end(), b.begin(),DS::lt<int>);
	for(const auto el : b)
		std::cout<<el<<" ";
		std::cout<<std::endl;
	
}

}// namespace DS

#endif //DS_HEAP_SORT_H_