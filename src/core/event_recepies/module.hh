#pragma once

#include "core/event_recepies/intel/icl/icl_governor.hh"
#include "core/event_recepies/intel/skl/skl_governor.hh"
#include "core/event_recepies/tma_recepies.hh"

namespace pmu_recepies = optkit::core::recepies;
namespace freq_governors = optkit::core::governors;

using optkit::core::recepies::operator<<;