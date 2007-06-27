#ifndef DataFormats_SiStripCommon_SiStripRefGetter_H
#define DataFormats_SiStripCommon_SiStripRefGetter_H

#include <algorithm>
#include <vector>
#include <utility>

#include "boost/concept_check.hpp"
#include "boost/iterator/indirect_iterator.hpp"

#include "DataFormats/Common/interface/traits.h"
#include "DataFormats/Common/interface/DetSet.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/SiStripCommon/interface/SiStripLazyGetter.h"

#include "FWCore/Utilities/interface/EDMException.h"
#include "FWCore/Utilities/interface/GCCPrerequisite.h"

namespace edm {

  //------------------------------------------------------------

  template <class T> class SiStripRefGetter;

  //------------------------------------------------------------

  /// Returns pointer to T within record.
  template<typename T>
    struct FindValue : public std::binary_function< const SiStripRefGetter<T>&, typename std::vector<T>::const_iterator, const T* > {
      typedef FindValue<T> self;
      typename self::result_type operator()(typename self::first_argument_type container, typename self::second_argument_type iter) const {
        return &(*iter);
      }
    };

  //------------------------------------------------------------

  template <class T>
  class SiStripRefGetter 
  {

    BOOST_CLASS_REQUIRE(T, boost, LessThanComparableConcept);

  public:

    typedef std::vector< RegionIndex<T> > register_type;
    typedef std::vector<T> record_type;
    typedef typename record_type::const_iterator record_iterator;
    typedef std::pair<typename record_type::const_iterator, typename record_type::const_iterator> record_pair;
    typedef Ref< SiStripRefGetter<T>, T, FindValue<T> > value_ref;
    typedef Ref< SiStripLazyGetter<T>, RegionIndex<T>, FindRegion<T> > region_ref;
    typedef std::vector<region_ref> collection_type;
    typedef boost::indirect_iterator<typename collection_type::const_iterator> const_iterator;

    SiStripRefGetter() : sets_() {}
    
    template <typename THandle>
      SiStripRefGetter(const THandle& iHandle, const std::vector<uint32_t>& iRegions) : sets_() {
        sets_.reserve(iRegions.size());
        for (std::vector<uint32_t>::const_iterator iRegion = iRegions.begin();
	    iRegion != iRegions.end();
            ++iRegion) {
          //the last 'false' says to not get the data right now
          sets_.push_back(region_ref(iHandle, *iRegion, false));
        }
      }

    /// Add a new region
    template <typename THandle>
      void add(const THandle& iHandle, const uint32_t& iRegion) {
      sets_.push_back(region_ref(iHandle, iRegion, false));
    }

    //Reserve memory for sets_ collection
    void reserve(uint32_t);

    /// Swap contents of class
    void swap(SiStripRefGetter& other);

    /// Return true if we contain no 'region_ref's (one per Region).
    bool empty() const;

    /// Return the number of contained 'region_ref's (one per Region).
    uint32_t size() const;

    /// Return an iterator to the RegionIndex<T> for a given Region id, or end() 
    /// if there is no such Region.
    const_iterator find(uint32_t region) const;

    /// Return a reference to the RegionIndex<T> for a given Region id, or throw 
    /// an edm::Exception if there is no such Region.
    const RegionIndex<T>& operator[](uint32_t region) const;

    /// Returns start end end iterators for values of a given det-id
    record_pair find(uint32_t,uint32_t) const;

    /// Return an iterator to the first RegionIndex<T>.
    const_iterator begin() const;

    /// Return the off-the-end iterator.
    const_iterator end() const;

  private:

    collection_type   sets_;

  };
  
  template <class T>
    inline
    void
    SiStripRefGetter<T>::reserve(uint32_t size) 
    {
      sets_.reserve(size);
    }
  
  template <class T>
    inline
    void
    SiStripRefGetter<T>::swap(SiStripRefGetter<T>& other) 
    {
      sets_.swap(other.sets_);
    }
  
  template <class T>
    inline
    bool
    SiStripRefGetter<T>::empty() const 
    {
      return sets_.empty();
    }
  
  template <class T>
    inline
    uint32_t
    SiStripRefGetter<T>::size() const
    {
      return sets_.size();
    }
  
  template <class T>
    inline
    typename SiStripRefGetter<T>::const_iterator
    SiStripRefGetter<T>::find(uint32_t region) const
    {
      if (size() < region+1) return sets_.end();
      return sets_.begin()+region;
    }
  
  template <class T>
    inline
    const RegionIndex<T>&
    SiStripRefGetter<T>::operator[](uint32_t region) const 
    {
      const_iterator it = find(region);
      if (it == end()) sistripdetail::_throw_range(region);
      return *it;
    }

  template <class T>
    inline
    typename SiStripRefGetter<T>::record_pair
    SiStripRefGetter<T>::find(uint32_t region, uint32_t detid) const 
    {
      const RegionIndex<T>& index = (*this)[region];
      return index.find(detid);
    } 
  
  template <class T>
    inline
    typename SiStripRefGetter<T>::const_iterator
    SiStripRefGetter<T>::begin() const
    {
      return sets_.begin();
    }
  
  template <class T>
    inline
    typename SiStripRefGetter<T>::const_iterator
    SiStripRefGetter<T>::end() const
    {
      return sets_.end();
    }
  
  template <class T>
    inline
    void
    swap(SiStripRefGetter<T>& a, SiStripRefGetter<T>& b) 
    {
      a.swap(b);
    }
  
  //------------------------------------------------------------
  
  //helper function to make it easier to create a edm::Ref
  
  template<class HandleT>
    typename HandleT::element_type::value_ref
    makeRefToSiStripRefGetter(const HandleT& iHandle, typename HandleT::element_type::record_iterator iter) {
    return typename HandleT::element_type::value_ref(iHandle,iter);
  }
  
  //------------------------------------------------------------
  
#if ! GCC_PREREQUISITE(3,4,4)
  // Has swap function
  template <class T>
  struct has_swap<edm::SiStripRefGetter<T> > {
    static bool const value = true;
  };

#endif

}
  
#endif

