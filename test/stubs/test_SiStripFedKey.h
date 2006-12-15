#ifndef DataFormats_SiStripCommon_test_SiStripFedKey_H
#define DataFormats_SiStripCommon_test_SiStripFedKey_H

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

/**
   @class test_SiStripFedKey 
   @author R.Bainbridge
   @brief Simple class that tests SiStripFedKey.
*/
class test_SiStripFedKey : public edm::EDAnalyzer {

 public:
  
  test_SiStripFedKey( const edm::ParameterSet& );
  ~test_SiStripFedKey();
  
  void beginJob( edm::EventSetup const& );
  void analyze( const edm::Event&, const edm::EventSetup& );
  void endJob() {;}

 private:

  bool frontEnd_;
  
};

#endif // DataFormats_SiStripCommon_test_SiStripFedKey_H
