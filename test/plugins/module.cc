#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_SEAL_MODULE();

#include "DataFormats/SiStripCommon/test/plugins/test_SiStripFecKey.h"
DEFINE_ANOTHER_FWK_MODULE(test_SiStripFecKey);

#include "DataFormats/SiStripCommon/test/plugins/test_SiStripFedKey.h"
DEFINE_ANOTHER_FWK_MODULE(test_SiStripFedKey);

#include "DataFormats/SiStripCommon/test/plugins/test_SiStripNullKey.h"
DEFINE_ANOTHER_FWK_MODULE(test_SiStripNullKey);

#include "DataFormats/SiStripCommon/test/plugins/test_SiStripKey.h"
DEFINE_ANOTHER_FWK_MODULE(test_SiStripKey);

#include "DataFormats/SiStripCommon/test/plugins/test_SiStripEnumsAndStrings.h"
DEFINE_ANOTHER_FWK_MODULE(test_SiStripEnumsAndStrings);

#include "DataFormats/SiStripCommon/test/plugins/test_SiStripHistoTitle.h"
DEFINE_ANOTHER_FWK_MODULE(test_SiStripHistoTitle);

#include "DataFormats/SiStripCommon/test/plugins/test_Template.h"
DEFINE_ANOTHER_FWK_MODULE(test_Template);
