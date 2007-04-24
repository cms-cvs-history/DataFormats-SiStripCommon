#ifndef DataFormats_SiStripCommon_SiStripLazyGetter_h
#define DataFormats_SiStripCommon_SiStripLazyGetter_h

#include <algorithm>
#include <vector>

#include "boost/concept_check.hpp"
#include "boost/iterator/transform_iterator.hpp"
#include "boost/shared_ptr.hpp"

#include "DataFormats/Common/interface/traits.h"
#include "DataFormats/Common/interface/DetSet.h"
#include "DataFormats/Common/interface/Ref.h"

#include "FWCore/Utilities/interface/EDMException.h"
#include "FWCore/Utilities/interface/GCCPrerequisite.h"

namespace edm {

  //------------------------------------------------------------

  template <class T> class SiStripLazyGetter;

  //------------------------------------------------------------
  // Helper function, to regularize throwing of exceptions.
  //------------------------------------------------------------

  namespace lgdetail
  {
    // Throw an edm::Exception with an appropriate message
    inline
    void _throw_range(uint32_t i)
  {
      throw edm::Exception(errors::InvalidReference)
      << "SiStripLazyGetter::operator[] called with index not in collection;\n"
      << "index value: " << i;
  }
  }

  template< typename T>
    class SiStripLazyUnpacker {
    public:
    typedef std::pair<uint32_t,std::vector<DetSet<T> > > Record;
    SiStripLazyUnpacker(uint32_t nregions) :
      record_(), unpacked_()
      {
	unpacked_.assign(nregions,false);
	record().reserve(nregions);
	for (uint32_t iregion=0;iregion<nregions;iregion++) {
	  record().push_back(Record(iregion,std::vector< DetSet<T> >()));
	}
      }
    virtual ~SiStripLazyUnpacker() {}
    virtual void fill(uint32_t&) = 0;
    std::vector<Record>& record() {return record_;}
    std::vector<bool>& unpacked() {return unpacked_;}
    private:
    SiStripLazyUnpacker() {}
    std::vector<Record> record_;
    std::vector<bool> unpacked_;
  };
  
  template<typename T>
    struct LazyAdapter : public std::unary_function<const typename SiStripLazyUnpacker<T>::Record&, const typename SiStripLazyUnpacker<T>::Record& > {
      LazyAdapter(boost::shared_ptr<SiStripLazyUnpacker<T> > iGetter): getter_(iGetter) {}
      const typename SiStripLazyUnpacker<T>::Record& operator()(const typename SiStripLazyUnpacker<T>::Record& irecord) const {
	if(getter_&&!getter_->unpacked()[irecord.first]) {
	  getter_->fill(const_cast<uint32_t&>(irecord.first));
	}
	return irecord;
      }
      private:
      boost::shared_ptr<SiStripLazyUnpacker<T> > getter_;
    };
  

  template <class T>
  class SiStripLazyGetter 
  {

    BOOST_CLASS_REQUIRE(T, boost, LessThanComparableConcept);

  public:

    typedef std::vector< typename SiStripLazyUnpacker<T>::Record > collection_type;
    typedef typename SiStripLazyUnpacker<T>::Record const&  const_reference;
    typedef boost::transform_iterator< LazyAdapter<T>, typename collection_type::const_iterator > const_iterator;
    typedef typename collection_type::size_type size_type;

    SiStripLazyGetter() {}
    
    SiStripLazyGetter(boost::shared_ptr< SiStripLazyUnpacker<T> > iGetter) :
      getter_(iGetter) {}

    void swap(SiStripLazyGetter& other);

    /// Return true if SiStripLazyUnpacker contains no DetSets.
    bool empty() const;

    /// Return the number of Regions.
    size_type size() const;

    /// Return an iterator to the SiStripLazyUnpacker<T>::Record for a 
    /// given Region id, or end() if there is no such Region.
    const_iterator find(uint32_t region) const;

    /// Return a reference to the SiStripLazyUnpacker<T>::Record for a 
    /// given Region id, or throw an edm::Exception if there is no such 
    /// Region.
    /// **DO NOT MODIFY THE id OF THE PAIR OR THE REFERENCED DetSets!**
    const_reference operator[](uint32_t region) const;

    /// Return an iterator to the first SiStripLazyUnpacker<T>::Record.
    const_iterator begin() const;

    /// Return the off-the-end iterator.
    const_iterator end() const;

  private:
    boost::shared_ptr< SiStripLazyUnpacker<T> > getter_;
  };

  template <class T>
  inline
  void
  SiStripLazyGetter<T>::swap(SiStripLazyGetter<T>& other) 
  {
    std::swap(getter_,other.getter_);
  }

  template <class T>
  inline
  bool
  SiStripLazyGetter<T>::empty() const 
  {
    return getter_->record().empty();
  }

  template <class T>
  inline
  typename SiStripLazyGetter<T>::size_type
  SiStripLazyGetter<T>::size() const
  {
    return getter_->record().size();
  }

  template <class T>
  inline
  typename SiStripLazyGetter<T>::const_iterator
  SiStripLazyGetter<T>::find(uint32_t region) const
  {
    typename collection_type::const_iterator it;
    if (size() < region+1) it = getter_->record().end();
    else it = getter_->record().begin()+region;
    LazyAdapter<T> adapter(getter_);
    return boost::make_transform_iterator(it,adapter);
  }

  template <class T>
  inline
  typename SiStripLazyGetter<T>::const_reference
  SiStripLazyGetter<T>::operator[](uint32_t region) const 
  {
    const_iterator it = this->find(region);
    if (it == this->end()) lgdetail::_throw_range(region);
    return *it;
  }

  template <class T>
  inline
  typename SiStripLazyGetter<T>::const_iterator
  SiStripLazyGetter<T>::begin() const
  {
    LazyAdapter<T> adapter(getter_);
    return boost::make_transform_iterator(getter_->record().begin(),adapter);
  }

  template <class T>
  inline
  typename SiStripLazyGetter<T>::const_iterator
  SiStripLazyGetter<T>::end() const
  {
    LazyAdapter<T> adapter(getter_);
    return boost::make_transform_iterator(getter_->record().end(),adapter);
  }

  template <class T>
  inline
  void
  swap(SiStripLazyGetter<T>& a, SiStripLazyGetter<T>& b) 
  {
    a.swap(b);
  }

#if ! GCC_PREREQUISITE(3,4,4)
  // has swap function
  template <class T>
  struct has_swap<edm::SiStripLazyGetter<T> > {
    static bool const value = true;
  };
#endif
}
#endif

