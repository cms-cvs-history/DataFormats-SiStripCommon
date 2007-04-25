#ifndef SISTRIPCLUSTER_CLASSES_H
#define SISTRIPCLUSTER_CLASSES_H

#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/SiStripCluster/interface/SiStripCluster.h"
#include "DataFormats/SiStripCommon/test/stubs/SiStripRefGetter.h"
namespace {
  namespace {
    edm::Wrapper< edm::SiStripLazyGetter<SiStripCluster> > dummy1;
    edm::Wrapper< edm::SiStripRefGetter< SiStripCluster, edm::SiStripLazyGetter<SiStripCluster> > > dummy2;
  }
}

#endif // SISTRIPCLUSTER_CLASSES_H
