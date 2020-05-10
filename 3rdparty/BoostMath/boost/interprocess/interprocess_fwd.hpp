//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2005-2012. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_INTERPROCESS_FWD_HPP
#define BOOST_INTERPROCESS_FWD_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost/config.hpp>
#endif
#ifndef BOOST_CSTDINT_HPP
#  include <boost/cstdint.hpp>
#endif
#
#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost/interprocess/detail/std_fwd.hpp>

//! \file
//! This header file forward declares the basic interprocess types:
//!   - _Boost::interprocess::offset_ptr;
//!   - _Boost::interprocess::permissions;
//!   - _Boost::interprocess::mapped_region;
//!   - _Boost::interprocess::file_mapping;
//!   - _Boost::interprocess::shared_memory_object;
//!   - _Boost::interprocess::windows_shared_memory;
//!   - _Boost::interprocess::xsi_shared_memory;
//!
//! The following synchronization mechanisms and locks:
//!   - _Boost::interprocess::null_mutex;
//!   - _Boost::interprocess::interprocess_mutex;
//!   - _Boost::interprocess::interprocess_recursive_mutex;
//!   - _Boost::interprocess::interprocess_semaphore;
//!   - _Boost::interprocess::named_mutex;
//!   - _Boost::interprocess::named_recursive_mutex;
//!   - _Boost::interprocess::named_semaphore;
//!   - _Boost::interprocess::interprocess_sharable_mutex;
//!   - _Boost::interprocess::interprocess_condition;
//!   - _Boost::interprocess::scoped_lock;
//!   - _Boost::interprocess::sharable_lock;
//!   - _Boost::interprocess::upgradable_lock;
//!
//! The following mutex families:
//!   - _Boost::interprocess::mutex_family;
//!   - _Boost::interprocess::null_mutex_family;
//!
//! The following allocators:
//!   - _Boost::interprocess::allocator;
//!   - _Boost::interprocess::node_allocator;
//!   - _Boost::interprocess::private_node_allocator;
//!   - _Boost::interprocess::cached_node_allocator;
//!   - _Boost::interprocess::adaptive_pool;
//!   - _Boost::interprocess::private_adaptive_pool;
//!   - _Boost::interprocess::cached_adaptive_pool;
//!
//! The following allocation algorithms:
//!   - _Boost::interprocess::simple_seq_fit;
//!   - _Boost::interprocess::rbtree_best_fit;
//!
//! The following index types:
//!   - _Boost::interprocess::flat_map_index;
//!   - _Boost::interprocess::iset_index;
//!   - _Boost::interprocess::iunordered_set_index;
//!   - _Boost::interprocess::map_index;
//!   - _Boost::interprocess::null_index;
//!   - _Boost::interprocess::unordered_map_index;
//!
//! The following managed memory types:
//!   - _Boost::interprocess::segment_manager;
//!   - _Boost::interprocess::basic_managed_external_buffer
//!   - _Boost::interprocess::managed_external_buffer
//!   - _Boost::interprocess::wmanaged_external_buffer
//!   - _Boost::interprocess::basic_managed_shared_memory
//!   - _Boost::interprocess::managed_shared_memory
//!   - _Boost::interprocess::wmanaged_shared_memory
//!   - _Boost::interprocess::basic_managed_windows_shared_memory
//!   - _Boost::interprocess::managed_windows_shared_memory
//!   - _Boost::interprocess::wmanaged_windows_shared_memory
//!   - _Boost::interprocess::basic_managed_xsi_shared_memory
//!   - _Boost::interprocess::managed_xsi_shared_memory
//!   - _Boost::interprocess::wmanaged_xsi_shared_memory
//!   - _Boost::interprocess::fixed_managed_shared_memory
//!   - _Boost::interprocess::wfixed_managed_shared_memory
//!   - _Boost::interprocess::basic_managed_heap_memory
//!   - _Boost::interprocess::managed_heap_memory
//!   - _Boost::interprocess::wmanaged_heap_memory
//!   - _Boost::interprocess::basic_managed_mapped_file
//!   - _Boost::interprocess::managed_mapped_file
//!   - _Boost::interprocess::wmanaged_mapped_file
//!
//! The following exception types:
//!   - _Boost::interprocess::interprocess_exception
//!   - _Boost::interprocess::lock_exception
//!   - _Boost::interprocess::bad_alloc
//!
//! The following stream types:
//!   - _Boost::interprocess::basic_bufferbuf
//!   - _Boost::interprocess::basic_ibufferstream
//!   - _Boost::interprocess::basic_obufferstream
//!   - _Boost::interprocess::basic_bufferstream
//!   - _Boost::interprocess::basic_vectorbuf
//!   - _Boost::interprocess::basic_ivectorstream
//!   - _Boost::interprocess::basic_ovectorstream
//!   - _Boost::interprocess::basic_vectorstream
//!
//! The following smart pointer types:
//!   - _Boost::interprocess::scoped_ptr
//!   - _Boost::interprocess::intrusive_ptr
//!   - _Boost::interprocess::shared_ptr
//!   - _Boost::interprocess::weak_ptr
//!
//! The following interprocess communication types:
//!   - _Boost::interprocess::message_queue_t;
//!   - _Boost::interprocess::message_queue;

#include <boost/interprocess/detail/config_begin.hpp>
#include <boost/interprocess/detail/workaround.hpp>

#if !defined(BOOST_INTERPROCESS_DOXYGEN_INVOKED)

#include <cstddef>

//////////////////////////////////////////////////////////////////////////////
//                        Standard predeclarations
//////////////////////////////////////////////////////////////////////////////

namespace _Boost{  namespace intrusive{ }  }
namespace _Boost{  namespace interprocess{ namespace bi = _Boost::intrusive; }  }

namespace _Boost { namespace interprocess {

//////////////////////////////////////////////////////////////////////////////
//                            permissions
//////////////////////////////////////////////////////////////////////////////

class permissions;

//////////////////////////////////////////////////////////////////////////////
//                            shared_memory
//////////////////////////////////////////////////////////////////////////////

class shared_memory_object;

#if defined (BOOST_INTERPROCESS_WINDOWS)
class windows_shared_memory;
#endif   //#if defined (BOOST_INTERPROCESS_WINDOWS)

#if defined(BOOST_INTERPROCESS_XSI_SHARED_MEMORY_OBJECTS)
class xsi_shared_memory;
#endif   //#if defined (BOOST_INTERPROCESS_WINDOWS)

//////////////////////////////////////////////////////////////////////////////
//              file mapping / mapped region
//////////////////////////////////////////////////////////////////////////////

class file_mapping;
class mapped_region;

//////////////////////////////////////////////////////////////////////////////
//                               Mutexes
//////////////////////////////////////////////////////////////////////////////

class null_mutex;

class interprocess_mutex;
class interprocess_recursive_mutex;

class named_mutex;
class named_recursive_mutex;

class interprocess_semaphore;
class named_semaphore;

//////////////////////////////////////////////////////////////////////////////
//                         Mutex families
//////////////////////////////////////////////////////////////////////////////

struct mutex_family;
struct null_mutex_family;

//////////////////////////////////////////////////////////////////////////////
//                   Other synchronization classes
//////////////////////////////////////////////////////////////////////////////

class interprocess_sharable_mutex;
class interprocess_condition;

//////////////////////////////////////////////////////////////////////////////
//                              Locks
//////////////////////////////////////////////////////////////////////////////

template <class Mutex>
class scoped_lock;

template <class SharableMutex>
class sharable_lock;

template <class UpgradableMutex>
class upgradable_lock;

//////////////////////////////////////////////////////////////////////////////
//                      STL compatible allocators
//////////////////////////////////////////////////////////////////////////////

template<class T, class SegmentManager>
class allocator;

template<class T, class SegmentManager, std::size_t NodesPerBlock = 64>
class node_allocator;

template<class T, class SegmentManager, std::size_t NodesPerBlock = 64>
class private_node_allocator;

template<class T, class SegmentManager, std::size_t NodesPerBlock = 64>
class cached_node_allocator;

template< class T, class SegmentManager, std::size_t NodesPerBlock = 64
        , std::size_t MaxFreeBlocks = 2, unsigned char OverheadPercent = 5 >
class adaptive_pool;

template< class T, class SegmentManager, std::size_t NodesPerBlock = 64
        , std::size_t MaxFreeBlocks = 2, unsigned char OverheadPercent = 5 >
class private_adaptive_pool;

template< class T, class SegmentManager, std::size_t NodesPerBlock = 64
        , std::size_t MaxFreeBlocks = 2, unsigned char OverheadPercent = 5 >
class cached_adaptive_pool;


//////////////////////////////////////////////////////////////////////////////
//                            offset_ptr
//////////////////////////////////////////////////////////////////////////////

static const std::size_t offset_type_alignment = 0;

#if !defined(BOOST_INTERPROCESS_DOXYGEN_INVOKED)
#  ifdef BOOST_HAS_INTPTR_T
      using ::_Boost::uintptr_t;
#  else
      typedef std::size_t uintptr_t;
#  endif
#endif

template < class T, class DifferenceType = std::ptrdiff_t
         , class OffsetType = uintptr_t, std::size_t Alignment = offset_type_alignment>
class offset_ptr;

//////////////////////////////////////////////////////////////////////////////
//                    Memory allocation algorithms
//////////////////////////////////////////////////////////////////////////////

//Single segment memory allocation algorithms
template<class MutexFamily, class VoidMutex = offset_ptr<void> >
class simple_seq_fit;

template<class MutexFamily, class VoidMutex = offset_ptr<void>, std::size_t MemAlignment = 0>
class rbtree_best_fit;

//////////////////////////////////////////////////////////////////////////////
//                         Index Types
//////////////////////////////////////////////////////////////////////////////

template<class IndexConfig> class flat_map_index;
template<class IndexConfig> class iset_index;
template<class IndexConfig> class iunordered_set_index;
template<class IndexConfig> class map_index;
template<class IndexConfig> class null_index;
template<class IndexConfig> class unordered_map_index;

//////////////////////////////////////////////////////////////////////////////
//                         Segment manager
//////////////////////////////////////////////////////////////////////////////

template <class CharType
         ,class MemoryAlgorithm
         ,template<class IndexConfig> class IndexType>
class segment_manager;

//////////////////////////////////////////////////////////////////////////////
//                  External buffer managed memory classes
//////////////////////////////////////////////////////////////////////////////

template <class CharType
         ,class MemoryAlgorithm
         ,template<class IndexConfig> class IndexType>
class basic_managed_external_buffer;

typedef basic_managed_external_buffer
   <char
   ,rbtree_best_fit<null_mutex_family>
   ,iset_index>
managed_external_buffer;

typedef basic_managed_external_buffer
   <wchar_t
   ,rbtree_best_fit<null_mutex_family>
   ,iset_index>
wmanaged_external_buffer;

//////////////////////////////////////////////////////////////////////////////
//                      managed memory classes
//////////////////////////////////////////////////////////////////////////////

template <class CharType
         ,class MemoryAlgorithm
         ,template<class IndexConfig> class IndexType>
class basic_managed_shared_memory;

typedef basic_managed_shared_memory
   <char
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
managed_shared_memory;

typedef basic_managed_shared_memory
   <wchar_t
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
wmanaged_shared_memory;


//////////////////////////////////////////////////////////////////////////////
//                      Windows shared memory managed memory classes
//////////////////////////////////////////////////////////////////////////////

#if defined (BOOST_INTERPROCESS_WINDOWS)

template <class CharType
         ,class MemoryAlgorithm
         ,template<class IndexConfig> class IndexType>
class basic_managed_windows_shared_memory;

typedef basic_managed_windows_shared_memory
   <char
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
managed_windows_shared_memory;

typedef basic_managed_windows_shared_memory
   <wchar_t
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
wmanaged_windows_shared_memory;

#endif   //#if defined (BOOST_INTERPROCESS_WINDOWS)

#if defined(BOOST_INTERPROCESS_XSI_SHARED_MEMORY_OBJECTS)

template <class CharType
         ,class MemoryAlgorithm
         ,template<class IndexConfig> class IndexType>
class basic_managed_xsi_shared_memory;

typedef basic_managed_xsi_shared_memory
   <char
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
managed_xsi_shared_memory;

typedef basic_managed_xsi_shared_memory
   <wchar_t
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
wmanaged_xsi_shared_memory;

#endif //#if defined(BOOST_INTERPROCESS_XSI_SHARED_MEMORY_OBJECTS)

//////////////////////////////////////////////////////////////////////////////
//                      Fixed address shared memory
//////////////////////////////////////////////////////////////////////////////

typedef basic_managed_shared_memory
   <char
   ,rbtree_best_fit<mutex_family, void*>
   ,iset_index>
fixed_managed_shared_memory;

typedef basic_managed_shared_memory
   <wchar_t
   ,rbtree_best_fit<mutex_family, void*>
   ,iset_index>
wfixed_managed_shared_memory;

//////////////////////////////////////////////////////////////////////////////
//                      Heap memory managed memory classes
//////////////////////////////////////////////////////////////////////////////

template
   <class CharType
   ,class MemoryAlgorithm
   ,template<class IndexConfig> class IndexType>
class basic_managed_heap_memory;

typedef basic_managed_heap_memory
   <char
   ,rbtree_best_fit<null_mutex_family>
   ,iset_index>
managed_heap_memory;

typedef basic_managed_heap_memory
   <wchar_t
   ,rbtree_best_fit<null_mutex_family>
   ,iset_index>
wmanaged_heap_memory;

//////////////////////////////////////////////////////////////////////////////
//                         Mapped file managed memory classes
//////////////////////////////////////////////////////////////////////////////

template
   <class CharType
   ,class MemoryAlgorithm
   ,template<class IndexConfig> class IndexType>
class basic_managed_mapped_file;

typedef basic_managed_mapped_file
   <char
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
managed_mapped_file;

typedef basic_managed_mapped_file
   <wchar_t
   ,rbtree_best_fit<mutex_family>
   ,iset_index>
wmanaged_mapped_file;

//////////////////////////////////////////////////////////////////////////////
//                            Exceptions
//////////////////////////////////////////////////////////////////////////////

class interprocess_exception;
class lock_exception;
class bad_alloc;

//////////////////////////////////////////////////////////////////////////////
//                            Bufferstream
//////////////////////////////////////////////////////////////////////////////

//bufferstream
template <class CharT
         ,class CharTraits = std::char_traits<CharT> >
class basic_bufferbuf;

template <class CharT
         ,class CharTraits = std::char_traits<CharT> >
class basic_ibufferstream;

template <class CharT
         ,class CharTraits = std::char_traits<CharT> >
class basic_obufferstream;

template <class CharT
         ,class CharTraits = std::char_traits<CharT> >
class basic_bufferstream;

//////////////////////////////////////////////////////////////////////////////
//                            Vectorstream
//////////////////////////////////////////////////////////////////////////////

template <class CharVector
         ,class CharTraits = std::char_traits<typename CharVector::value_type> >
class basic_vectorbuf;

template <class CharVector
         ,class CharTraits = std::char_traits<typename CharVector::value_type> >
class basic_ivectorstream;

template <class CharVector
         ,class CharTraits = std::char_traits<typename CharVector::value_type> >
class basic_ovectorstream;

template <class CharVector
         ,class CharTraits = std::char_traits<typename CharVector::value_type> >
class basic_vectorstream;

//////////////////////////////////////////////////////////////////////////////
//                             Smart pointers
//////////////////////////////////////////////////////////////////////////////

template<class T, class Deleter>
class scoped_ptr;

template<class T, class VoidPointer>
class intrusive_ptr;

template<class T, class VoidAllocator, class Deleter>
class shared_ptr;

template<class T, class VoidAllocator, class Deleter>
class weak_ptr;

//////////////////////////////////////////////////////////////////////////////
//                                  IPC
//////////////////////////////////////////////////////////////////////////////

template<class VoidPointer>
class message_queue_t;

typedef message_queue_t<offset_ptr<void> > message_queue;

}}  //namespace _Boost { namespace interprocess {

#endif   //#if !defined(BOOST_INTERPROCESS_DOXYGEN_INVOKED)

#include <boost/interprocess/detail/config_end.hpp>

#endif //#ifndef BOOST_INTERPROCESS_FWD_HPP
