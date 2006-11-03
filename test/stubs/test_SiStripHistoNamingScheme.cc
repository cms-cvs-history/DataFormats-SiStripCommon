#include "DataFormats/SiStripCommon/test/stubs/test_SiStripHistoNamingScheme.h"
#include "DataFormats/SiStripCommon/interface/SiStripHistoNamingScheme.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;
using namespace sistrip;

// -----------------------------------------------------------------------------
// 
test_SiStripHistoNamingScheme::test_SiStripHistoNamingScheme( const edm::ParameterSet& pset )
{
  LogTrace(mlDqmCommon_)
    << "[test_SiStripHistoNamingScheme::" << __func__ << "]"
    << " Constructing object...";
}

// -----------------------------------------------------------------------------
// 
test_SiStripHistoNamingScheme::~test_SiStripHistoNamingScheme() {
  LogTrace(mlDqmCommon_)
    << "[test_SiStripHistoNamingScheme::" << __func__ << "]"
    << " Destructing object...";
}

// -----------------------------------------------------------------------------
// 
void test_SiStripHistoNamingScheme::beginJob( const edm::EventSetup& setup ) {

  // sistrip::View
  {
    LogTrace(mlDqmCommon_) 
      << "[SiStripHistoNamingScheme::" << __func__ << "]"
      << " Checking sistrip::View...";
    bool first = true;
    for ( uint32_t cntr = 0; cntr <= sistrip::invalid_; cntr++ ) {
      sistrip::View in = static_cast<sistrip::View>(cntr);
      string str = SiStripHistoNamingScheme::view(in);
      sistrip::View out = SiStripHistoNamingScheme::view(str);
      if ( out != sistrip::UNKNOWN_VIEW ||
	   ( out == sistrip::UNKNOWN_VIEW && first ) ) {
	first = false;
	stringstream ss;
	ss << "[test_SiStripHistoNamingScheme::" << __func__ << "]" 
	   << " cntr: " << setw(8) << cntr
	   << "  in: " << setw(8) << in
	   << "  out: " << setw(8) << out
	   << "  str: " << str;
	LogTrace(mlDqmCommon_) << ss.str();
      }
    }
  }

  // sistrip::Task
  vector<sistrip::Task> tasks;
  {
    LogTrace(mlDqmCommon_) 
      << "[SiStripHistoNamingScheme::" << __func__ << "]"
      << " Checking sistrip::Task...";
    bool first = true;
    for ( uint32_t cntr = 0; cntr <= sistrip::invalid_; cntr++ ) {
      sistrip::Task in = static_cast<sistrip::Task>(cntr);
      string str = SiStripHistoNamingScheme::task(in);
      sistrip::Task out = SiStripHistoNamingScheme::task(str);
      if ( out != sistrip::UNKNOWN_TASK ||
	   ( out == sistrip::UNKNOWN_TASK && first ) ) {
	first = false;
	stringstream ss;
	ss << "[test_SiStripHistoNamingScheme::" << __func__ << "]" 
	   << " cntr: " << setw(8) << cntr
	   << "  in: " << setw(8) << in
	   << "  out: " << setw(8) << out
	   << "  str: " << str;
	LogTrace(mlDqmCommon_) << ss.str();
	if ( out != sistrip::UNKNOWN_TASK ) { tasks.push_back(in); }
      }
    }
  }

  // sistrip::KeyType
  vector<sistrip::KeyType> key_types;
  {
    LogTrace(mlDqmCommon_) 
      << "[SiStripHistoNamingScheme::" << __func__ << "]"
      << " Checking sistrip::KeyType...";
    bool first = true;
    for ( uint32_t cntr = 0; cntr <= sistrip::invalid_; cntr++ ) {
      sistrip::KeyType in = static_cast<sistrip::KeyType>(cntr);
      string str = SiStripHistoNamingScheme::keyType(in);
      sistrip::KeyType out = SiStripHistoNamingScheme::keyType(str);
      if ( out != sistrip::UNKNOWN_KEY ||
	   ( out == sistrip::UNKNOWN_KEY && first ) ) {
	first = false;
	stringstream ss;
	ss << "[test_SiStripHistoNamingScheme::" << __func__ << "]" 
	   << " cntr: " << setw(8) << cntr
	   << "  in: " << setw(8) << in
	   << "  out: " << setw(8) << out
	   << "  str: " << str;
	LogTrace(mlDqmCommon_) << ss.str();
	if ( out != sistrip::UNKNOWN_KEY ) { key_types.push_back(in); }
      }
    }
  }

  // sistrip::Granularity
  vector<sistrip::Granularity> grans; 
  {
    LogTrace(mlDqmCommon_) 
      << "[SiStripHistoNamingScheme::" << __func__ << "]"
      << " Checking sistrip::Granularity...";
    bool first = true;
    for ( uint32_t cntr = 0; cntr <= sistrip::invalid_; cntr++ ) {
      sistrip::Granularity in = static_cast<sistrip::Granularity>(cntr);
      string str = SiStripHistoNamingScheme::granularity(in);
      sistrip::Granularity out = SiStripHistoNamingScheme::granularity(str);
      if ( out != sistrip::UNKNOWN_GRAN ||
	   ( out == sistrip::UNKNOWN_GRAN && first ) ) {
	first = false;
	stringstream ss;
	ss << "[test_SiStripHistoNamingScheme::" << __func__ << "]" 
	   << " cntr: " << setw(8) << cntr
	   << "  in: " << setw(8) << in
	   << "  out: " << setw(8) << out
	   << "  str: " << str;
	LogTrace(mlDqmCommon_) << ss.str();
	if ( out != sistrip::UNKNOWN_GRAN ) { grans.push_back(in); }
      }
    }
  }

  // sistrip::SummaryHisto
  {
    LogTrace(mlDqmCommon_) 
      << "[SiStripHistoNamingScheme::" << __func__ << "]"
      << " Checking sistrip::SummaryHisto...";
    bool first = true;
    for ( uint32_t cntr = 0; cntr <= sistrip::invalid_; cntr++ ) {
      sistrip::SummaryHisto in = static_cast<sistrip::SummaryHisto>(cntr);
      string str = SiStripHistoNamingScheme::summaryHisto(in);
      sistrip::SummaryHisto out = SiStripHistoNamingScheme::summaryHisto(str);
      if ( out != sistrip::UNKNOWN_SUMMARY_HISTO ||
	   ( out == sistrip::UNKNOWN_SUMMARY_HISTO && first ) ) {
	first = false;
	stringstream ss;
	ss << "[test_SiStripHistoNamingScheme::" << __func__ << "]" 
	   << " cntr: " << setw(8) << cntr
	   << "  in: " << setw(8) << in
	   << "  out: " << setw(8) << out
	   << "  str: " << str;
	LogTrace(mlDqmCommon_) << ss.str();
      }
    }
  }

  // sistrip::SummaryType
  {
    LogTrace(mlDqmCommon_) 
      << "[SiStripHistoNamingScheme::" << __func__ << "]"
      << " Checking sistrip::SummaryType...";
    bool first = true;
    for ( uint32_t cntr = 0; cntr <= sistrip::invalid_; cntr++ ) {
      sistrip::SummaryType in = static_cast<sistrip::SummaryType>(cntr);
      string str = SiStripHistoNamingScheme::summaryType(in);
      sistrip::SummaryType out = SiStripHistoNamingScheme::summaryType(str);
      if ( out != sistrip::UNKNOWN_SUMMARY_TYPE ||
	   ( out == sistrip::UNKNOWN_SUMMARY_TYPE && first ) ) {
	first = false;
	stringstream ss;
	ss << "[test_SiStripHistoNamingScheme::" << __func__ << "]" 
	   << " cntr: " << setw(8) << cntr 
	   << "  in: " << setw(8) << in
	   << "  out: " << setw(8) << out
	   << "  str: " << str;
	LogTrace(mlDqmCommon_) << ss.str();
      }
    }
  }

  // HistoTitle
  {
    LogTrace(mlDqmCommon_) 
      << "[SiStripHistoNamingScheme::" << __func__ << "]"
      << " Checking HistoTitle...";
    uint32_t cntr = 0;
    vector<sistrip::Task>::const_iterator itask = tasks.begin(); 
    for ( ; itask != tasks.end(); itask++ ) {
      vector<sistrip::KeyType>::const_iterator ikey = key_types.begin(); 
      for ( ; ikey != key_types.end(); ikey++ ) {
	vector<sistrip::Granularity>::const_iterator igran = grans.begin(); 
	for ( ; igran != grans.end(); igran++ ) {
	  for ( uint16_t iextra = 0; iextra < 2; iextra++ ) { 
	    string extra = "";
	    if ( iextra ) { extra = "SomeInfo"; }

	    stringstream ss;
	    ss << "[test_SiStripHistoNamingScheme::" << __func__ << "]" 
	       << " Task/KeyType/Gran/Extra: " << *itask << "/" << *ikey << "/" << *igran << "/" << iextra << endl
	       << "  Task:      " << SiStripHistoNamingScheme::task(*itask) << endl
	       << "  KeyType:   " << SiStripHistoNamingScheme::keyType(*ikey) << endl
	       << "  Gran:      " << SiStripHistoNamingScheme::granularity(*igran) << endl
	       << "  ExtraInfo: ";
	    if ( extra == "" ) { ss << "(none)" << endl; }
	    else { ss << extra << endl; }
	    
	    HistoTitle in( *itask, *ikey, cntr, *igran, 0, extra );
	    string str = SiStripHistoNamingScheme::histoTitle(in);
	    HistoTitle out = SiStripHistoNamingScheme::histoTitle(str);
	    ss << "  IN: " << in << endl;
	    ss << "  STR: " << str << endl;
	    ss << "  OUT: " << out << endl;
	    LogTrace(mlDqmCommon_) << ss.str();
	    cntr++;

	  }
	}
      }      
    }
  }

}

// -----------------------------------------------------------------------------
// 
void test_SiStripHistoNamingScheme::analyze( const edm::Event& event, 
					     const edm::EventSetup& setup ) {
  LogTrace(mlDqmCommon_) 
    << "[SiStripHistoNamingScheme::" << __func__ << "]"
    << " Analyzing run/event "
    << event.id().run() << "/"
    << event.id().event();
}


