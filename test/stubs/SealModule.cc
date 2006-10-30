#include "FWCore/Framework/interface/MakerMacros.h"
#include "PluginManager/ModuleDef.h"
DEFINE_SEAL_MODULE();

#include "DataFormats/SiStripCommon/test/stubs/test_SiStripHistoNamingScheme.h"
DEFINE_ANOTHER_FWK_MODULE(test_SiStripHistoNamingScheme);

#include "DataFormats/SiStripCommon/test/stubs/test_SiStripFecKey.h"
DEFINE_ANOTHER_FWK_MODULE(test_SiStripFecKey);

#include "DataFormats/SiStripCommon/test/stubs/test_SiStripFedKey.h"
DEFINE_ANOTHER_FWK_MODULE(test_SiStripFedKey);


