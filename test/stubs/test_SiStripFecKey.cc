#include "DataFormats/SiStripCommon/test/stubs/test_SiStripFecKey.h"
#include "DataFormats/SiStripCommon/interface/SiStripFecKey.h"
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
test_SiStripFecKey::test_SiStripFecKey( const edm::ParameterSet& pset )
{
  LogTrace(mlDqmCommon_)
    << "[test_SiStripFecKey::" << __func__ << "]"
    << " Constructing object...";
}

// -----------------------------------------------------------------------------
// 
test_SiStripFecKey::~test_SiStripFecKey() {
  LogTrace(mlDqmCommon_)
    << "[test_SiStripFecKey::" << __func__ << "]"
    << " Destructing object...";
}

// -----------------------------------------------------------------------------
// 
void test_SiStripFecKey::beginJob( const edm::EventSetup& setup ) {
  LogTrace(mlDqmCommon_) 
    << "[SiStripFecKey::" << __func__ << "]";
  
  uint32_t cntr = 0;
  uint32_t start = time(NULL);
  for ( uint16_t icrate = 0; icrate <= sistrip::FEC_CRATE_MAX+1; icrate++ ) {
    if ( icrate > 1 && icrate < sistrip::FEC_CRATE_MAX ) { continue; }
    for ( uint16_t islot = 0; islot <= sistrip::CRATE_SLOT_MAX+1; islot++ ) {
      if ( islot > 1 && islot < sistrip::CRATE_SLOT_MAX ) { continue; }
      for ( uint16_t iring = 0; iring <= sistrip::FEC_RING_MAX+1; iring++ ) {
	if ( iring > 1 && iring < sistrip::FEC_RING_MAX ) { continue; }
	for ( uint16_t iccu = 0; iccu <= sistrip::CCU_ADDR_MAX+1; iccu++ ) {
	  if ( iccu > 1 && iccu < sistrip::CCU_ADDR_MAX ) { continue; }
	  for ( uint16_t imod = 0; imod <= sistrip::CCU_CHAN_MAX+1; imod++ ) {
	    for ( uint16_t ichan = 0; ichan <= sistrip::APV_I2C_MAX+1; ichan++ ) {
	      
	      if ( !(cntr%10000) ) {
		edm::LogVerbatim(mlDqmCommon_)
		  << "[SiStripFecKey::" << __func__ << "]"
		  << " Cntr: " << cntr;
	      }
	      cntr++;
	      
	      uint32_t fec_key = SiStripFecKey::key( icrate,
						     islot,
						     iring,
						     iccu,
						     imod,
						     ichan );
	      SiStripFecKey::Path fec_path = SiStripFecKey::path( fec_key );
	      
	      stringstream ss;
	      ss << "[SiStripFecKey::" << __func__ << "]"
		 << "  Crate/FEC/Ring/CCU/Module/Channel: "
		 << icrate << "/"
		 << islot << "/"
		 << iring << "/"
		 << iccu << "/"
		 << imod << "/"
		 << ichan;
	      ss << fec_path;
	      LogTrace(mlDqmCommon_) << ss.str();
	      
	    }
	  }
	}
      }
    }
  }
  
  edm::LogInfo(mlDqmCommon_)
    << "[SiStripFecKey::" << __func__ << "]"
    << " Processed " << cntr
    << " FecKeys in " << (time(NULL)-start)
    << " seconds at an average rate of " << (cntr*1.) / ((time(NULL)-start)*1.)
    << " per second...";

}

// -----------------------------------------------------------------------------
// 
void test_SiStripFecKey::analyze( const edm::Event& event, 
				  const edm::EventSetup& setup ) {
  LogTrace(mlDqmCommon_) 
    << "[SiStripFecKey::" << __func__ << "]"
    << " Analyzing run/event "
    << event.id().run() << "/"
    << event.id().event();
}


