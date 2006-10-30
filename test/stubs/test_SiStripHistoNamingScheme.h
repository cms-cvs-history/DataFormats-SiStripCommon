#ifndef DataFormats_SiStripCommon_test_SiStripHistoNamingScheme_H
#define DataFormats_SiStripCommon_test_SiStripHistoNamingScheme_H

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

/**
   @class test_SiStripHistoNamingScheme 
   @author R.Bainbridge
   @brief Simple class that tests SiStripHistoNamingScheme.
*/
class test_SiStripHistoNamingScheme : public edm::EDAnalyzer {

 public:
  
  test_SiStripHistoNamingScheme( const edm::ParameterSet& );
  ~test_SiStripHistoNamingScheme();
  
  void beginJob( edm::EventSetup const& );
  void analyze( const edm::Event&, const edm::EventSetup& );
  void endJob() {;}
  
};

#endif // DataFormats_SiStripCommon_test_SiStripHistoNamingScheme_H

