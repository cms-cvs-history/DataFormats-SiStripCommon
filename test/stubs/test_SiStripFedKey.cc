#include "DataFormats/SiStripCommon/test/stubs/test_SiStripFedKey.h"
#include "DataFormats/SiStripCommon/interface/SiStripFedKey.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <time.h>

using namespace std;
using namespace sistrip;

// -----------------------------------------------------------------------------
// 
test_SiStripFedKey::test_SiStripFedKey( const edm::ParameterSet& pset ) :
  frontEnd_( pset.getUntrackedParameter<bool>("FrontEnd",true) )
{
  LogTrace(mlDqmCommon_)
    << "[test_SiStripFedKey::" << __func__ << "]"
    << " Constructing object...";
}

// -----------------------------------------------------------------------------
// 
test_SiStripFedKey::~test_SiStripFedKey() {
  LogTrace(mlDqmCommon_)
    << "[test_SiStripFedKey::" << __func__ << "]"
    << " Destructing object...";
}

// -----------------------------------------------------------------------------
// 
void test_SiStripFedKey::beginJob( const edm::EventSetup& setup ) {

  uint32_t cntr = 0;
  uint32_t start = time(NULL);
  
  if ( frontEnd_ ) {

    for ( uint16_t ifed = 0; ifed <= sistrip::FED_ID_LAST+1; ifed++ ) {
      if ( ifed > 1 && ifed < sistrip::FED_ID_LAST-1 ) { continue; }
      for ( uint16_t ife = 0; ife <= sistrip::FEUNITS_PER_FED+1; ife++ ) {
	if ( ife > 1 && ife < sistrip::FEUNITS_PER_FED ) { continue; }
	for ( uint16_t ichan = 0; ichan <= sistrip::FEDCH_PER_FEUNIT+1; ichan++ ) {
	  if ( ichan > 1 && ichan < sistrip::FEDCH_PER_FEUNIT ) { continue; }
	  for ( uint16_t iapv = 0; iapv <= sistrip::APVS_PER_FEDCH+1; iapv++ ) {
	    if ( iapv > 1 && iapv < sistrip::APVS_PER_FEDCH ) { continue; }

	    // Some debug
	    if ( !(cntr%1000) ) {
	      edm::LogVerbatim(mlDqmCommon_)
		<< "[SiStripFedKey::" << __func__ << "]"
		<< " Cntr: " << cntr;
	    }
	    cntr++;

	    // Generate keys
	    SiStripFedKey::Path in( ifed,
				    ife,
				    ichan,
				    iapv );
	    uint32_t fed_key = SiStripFedKey::key( in );
	    SiStripFedKey::Path out = SiStripFedKey::path( fed_key );
	  
	    stringstream ss;
	    ss << "[SiStripFedKey::" << __func__ << "]" << endl
	       << " FedId/FeUnit/FeChan/APV: "
	       << ifed << "/"
	       << ife << "/"
	       << ichan << "/"
	       << iapv << endl;
	    ss << " in:  " << in << endl;
	    ss << " out: " << out;
	    LogTrace(mlDqmCommon_) << ss.str();
	  
	  
	  }
	}
      }
    }
  
  } else { // Not FrontEnd...

    for ( uint16_t ifed = 0; ifed <= sistrip::FED_ID_LAST+1; ifed++ ) {
      if ( ifed > 1 && ifed < sistrip::FED_ID_LAST-1 ) { continue; }
      for ( uint16_t ichan = 0; ichan <= sistrip::FEDCH_PER_FED+1; ichan++ ) {
	if ( ichan > 1 && ichan < sistrip::FEDCH_PER_FED-1 ) { continue; }
	for ( uint16_t iapv = 0; iapv <= sistrip::APVS_PER_FEDCH+1; iapv++ ) {
	  if ( iapv > 1 && iapv < sistrip::APVS_PER_FEDCH ) { continue; }
	  
	  // Some debug
	  if ( !(cntr%1000) ) {
	    edm::LogVerbatim(mlDqmCommon_)
	      << "[SiStripFedKey::" << __func__ << "]"
	      << " Cntr: " << cntr;
	  }
	  cntr++;

	  // Generate keys
	  SiStripFedKey::Path in( ifed,
				  ichan,
				  iapv );
	  uint32_t fed_key = SiStripFedKey::key( in );
	  SiStripFedKey::Path out = SiStripFedKey::path( fed_key );
	  
	  stringstream ss;
	  ss << "[SiStripFedKey::" << __func__ << "]" << endl
	     << " FedId/FedCh/APV: "
	     << ifed << "/"
	     << ichan << "/"
	     << iapv << endl;
	  ss << " in:  " << in << endl;
	  ss << " out: " << out;
	  LogTrace(mlDqmCommon_) << ss.str();
	  
	  
	}
      }
    }

  }

  edm::LogInfo(mlDqmCommon_)
    << "[SiStripFedKey::" << __func__ << "]"
    << " Processed " << cntr
    << " FecKeys in " << (time(NULL)-start)
    << " seconds at an average rate of " << (cntr*1.) / ((time(NULL)-start)*1.)
    << " per second...";
  
}

// -----------------------------------------------------------------------------
// 
void test_SiStripFedKey::analyze( const edm::Event& event, 
				  const edm::EventSetup& setup ) {
  LogTrace(mlDqmCommon_) 
    << "[SiStripFedKey::" << __func__ << "]"
    << " Analyzing run/event "
    << event.id().run() << "/"
    << event.id().event();
}


