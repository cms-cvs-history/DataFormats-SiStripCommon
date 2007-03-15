#ifndef DataFormats_SiStripCommon_test_SiStripHistoTitle_H
#define DataFormats_SiStripCommon_test_SiStripHistoTitle_H

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

/**
   @class test_SiStripHistoTitle 
   @author R.Bainbridge
   @brief Simple class that tests SiStripHistoTitle.
*/
class test_SiStripHistoTitle : public edm::EDAnalyzer {

 public:
  
  test_SiStripHistoTitle( const edm::ParameterSet& );
  ~test_SiStripHistoTitle();
  
  void beginJob( edm::EventSetup const& );
  void analyze( const edm::Event&, const edm::EventSetup& );
  void endJob() {;}
  
};

#endif // DataFormats_SiStripCommon_test_SiStripHistoTitle_H

