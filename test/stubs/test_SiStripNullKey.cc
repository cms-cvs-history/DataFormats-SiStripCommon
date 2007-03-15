#include "DataFormats/SiStripCommon/test/stubs/test_SiStripNullKey.h"
#include "DataFormats/SiStripCommon/interface/SiStripNullKey.h"
#include "DataFormats/SiStripCommon/interface/SiStripConstants.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include <boost/cstdint.hpp>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <time.h>

// -----------------------------------------------------------------------------
// 
test_SiStripNullKey::test_SiStripNullKey( const edm::ParameterSet& pset ) 
{
  using namespace sistrip;
  LogTrace(mlDqmCommon_)
    << "[test_SiStripNullKey::" << __func__ << "]"
    << " Constructing object...";
}

// -----------------------------------------------------------------------------
// 
test_SiStripNullKey::~test_SiStripNullKey() {
  using namespace sistrip;
  LogTrace(mlDqmCommon_)
    << "[test_SiStripNullKey::" << __func__ << "]"
    << " Destructing object...";
}

// -----------------------------------------------------------------------------
// 
void test_SiStripNullKey::beginJob( const edm::EventSetup& setup ) {
  using namespace sistrip;
  
  // Tests for utility methods

  SiStripNullKey invalid;
  SiStripNullKey same(invalid);
  SiStripNullKey equal = invalid;
  SiStripNullKey equals; 
  equals = invalid;
  SiStripKey* base = static_cast<SiStripKey*>(&invalid); 

  std::stringstream ss;

  ss << "[SiStripNullKey::" << __func__ << "]"
     << " Tests for utility methods..." << std::endl;

  ss << ">>>> invalid: " << invalid << std::endl
     << ">>>> same:    " << same << std::endl
     << ">>>> equal:   " << equal << std::endl
     << ">>>> equals:  " << equals << std::endl
     << ">>>> base:    " << *base << std::endl;
  
  ss << ">>>> invalid.isInvalid: " << invalid.isInvalid() << std::endl
     << ">>>> invalid.isValid:   " << invalid.isValid() << std::endl;

  ss << ">>>> invalid.isEqual(invalid):      " << invalid.isEqual(invalid) << std::endl
     << ">>>> invalid.isConsistent(invalid): " << invalid.isConsistent(invalid) << std::endl
     << ">>>> invalid.isEqual(same):         " << invalid.isEqual(same) << std::endl
     << ">>>> invalid.isEqual(equal):        " << invalid.isEqual(equal) << std::endl
     << ">>>> invalid.isEqual(equals):       " << invalid.isEqual(equals) << std::endl;
  if ( base ) {
    ss << ">>>> base->isEqual(invalid):        " << base->isEqual(invalid) << std::endl
       << ">>>> base->isConsistent(invalid):   " << base->isConsistent(invalid) << std::endl;
  }
  
  LogTrace(mlDqmCommon_) << ss.str();

}

// -----------------------------------------------------------------------------
// 
void test_SiStripNullKey::analyze( const edm::Event& event, 
				  const edm::EventSetup& setup ) {
  using namespace sistrip;
  LogTrace(mlDqmCommon_) 
    << "[SiStripNullKey::" << __func__ << "]"
    << " Analyzing run/event "
    << event.id().run() << "/"
    << event.id().event();
}

