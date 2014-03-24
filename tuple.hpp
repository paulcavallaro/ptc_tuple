#include <cstddef>

namespace ptc {

// Actual indexed tuple implementation
template <std::size_t _Idx, typename... _Elements>
struct _Tuple_impl;

// Base case
template <std::size_t _Idx>
struct _Tuple_impl<_Idx> {
};

// Recursive case
template<std::size_t _Idx, typename _Head, typename... _Tail>
struct _Tuple_impl<_Idx, _Head, _Tail...>
  : public _Tuple_impl<_Idx + 1, _Tail...> {

  typedef _Tuple_impl<_Idx + 1, _Tail...> _Inherited;

  _Head head;

  explicit
  _Tuple_impl(const _Head& __head, const _Tail&... __tail)
    : _Inherited(__tail...), head(__head) {}

};

// Tuple is straight forward delegating all work to the _Tuple_impl
template<typename... _Elements>
class tuple : public _Tuple_impl<0, _Elements...>
{
  typedef _Tuple_impl<0, _Elements...> _Inherited;

 public:
  tuple() : _Inherited() {}

  explicit
  tuple(const _Elements&... __elements)
    : _Inherited(__elements...) {}
};

// Gives the type of the ith element of a given tuple type.
template<std::size_t __i, typename _Tp>
struct tuple_element;

// Recursive case
template<std::size_t __i, typename _Head, typename... _Tail>
struct tuple_element<__i, tuple<_Head, _Tail...> >
  : tuple_element<__i - 1, tuple<_Tail...> > {};

// Base case
template<typename _Head, typename... _Tail>
struct tuple_element<0, tuple<_Head, _Tail...> >
{
  typedef _Head type;
};

// Bullshit coercion to get the right type we want
// We cast the actual tuple to the properly indexed _Tuple_impl
// base class and grab out the head
template<std::size_t __i, typename _Head, typename... _Tail>
_Head __get_helper(const _Tuple_impl<__i, _Head, _Tail...>& __t) {
  return __t.head;
}

// Can finally define ptc::get
template<std::size_t __i, typename... _Elements>
typename tuple_element<__i, tuple<_Elements...> >:: type
get(tuple<_Elements...>& __t) {
  return __get_helper<__i>(__t);
}

} // namespace ptc::
