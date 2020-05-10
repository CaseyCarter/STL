
// Copyright (C) 2005-2016 Daniel James
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/unordered/detail/implementation.hpp>
#include <boost/unordered/unordered_map_fwd.hpp>

namespace _Boost {
  namespace unordered {
    namespace detail {
      template <typename A, typename K, typename M, typename H, typename P>
      struct map
      {
        typedef _Boost::unordered::detail::map<A, K, M, H, P> types;

        typedef std::pair<K const, M> value_type;
        typedef H hasher;
        typedef P key_equal;
        typedef K const const_key_type;

        typedef
          typename ::_Boost::unordered::detail::rebind_wrap<A, value_type>::type
            value_allocator;
        typedef _Boost::unordered::detail::allocator_traits<value_allocator>
          value_allocator_traits;

        typedef _Boost::unordered::detail::pick_node<A, value_type> pick;
        typedef typename pick::node node;
        typedef typename pick::bucket bucket;
        typedef typename pick::link_pointer link_pointer;

        typedef _Boost::unordered::detail::table<types> table;
        typedef _Boost::unordered::detail::map_extractor<value_type> extractor;

        typedef typename _Boost::unordered::detail::pick_policy<K>::type policy;

        typedef _Boost::unordered::iterator_detail::iterator<node> iterator;
        typedef _Boost::unordered::iterator_detail::c_iterator<node> c_iterator;
        typedef _Boost::unordered::iterator_detail::l_iterator<node> l_iterator;
        typedef _Boost::unordered::iterator_detail::cl_iterator<node>
          cl_iterator;

        typedef _Boost::unordered::node_handle_map<node, K, M, A> node_type;
        typedef _Boost::unordered::insert_return_type_map<node, K, M, A>
          insert_return_type;
      };

      template <typename K, typename M, typename H, typename P, typename A>
      class instantiate_map
      {
        typedef _Boost::unordered_map<K, M, H, P, A> container;
        container x;
        typename container::node_type node_type;
        typename container::insert_return_type insert_return_type;
      };

      template <typename K, typename M, typename H, typename P, typename A>
      class instantiate_multimap
      {
        typedef _Boost::unordered_multimap<K, M, H, P, A> container;
        container x;
        typename container::node_type node_type;
      };
    }
  }
}
