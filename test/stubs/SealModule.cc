#include "FWCore/Framework/interface/MakerMacros.h"
#include "PluginManager/ModuleDef.h"
DEFINE_SEAL_MODULE();

#include "DataFormats/SiStripCommon/test/stubs/test_SiStripFecKey.h"
DEFINE_ANOTHER_FWK_MODULE(test_SiStripFecKey);

#include "DataFormats/SiStripCommon/test/stubs/test_SiStripFedKey.h"
DEFINE_ANOTHER_FWK_MODULE(test_SiStripFedKey);

#include "DataFormats/SiStripCommon/test/stubs/test_SiStripNullKey.h"
DEFINE_ANOTHER_FWK_MODULE(test_SiStripNullKey);

#include "DataFormats/SiStripCommon/test/stubs/test_SiStripEnumsAndStrings.h"
DEFINE_ANOTHER_FWK_MODULE(test_SiStripEnumsAndStrings);

#include "DataFormats/SiStripCommon/test/stubs/test_SiStripHistoTitle.h"
DEFINE_ANOTHER_FWK_MODULE(test_SiStripHistoTitle);

