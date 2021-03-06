////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2017 ArangoDB GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Jan Steemann
////////////////////////////////////////////////////////////////////////////////

#ifndef ARANGOD_VOC_BASE_API_TTL_H
#define ARANGOD_VOC_BASE_API_TTL_H 1

#include "Basics/Result.h"

namespace arangodb {
namespace velocypack {
class Builder;
class Slice;
}

namespace methods {

/// Common code for TTL statistics and mode
struct Ttl {
  // return the TTL feature statistics
  static arangodb::Result getStatistics(arangodb::velocypack::Builder& out);
  
  // return the TTL feature's current properties
  static arangodb::Result getProperties(arangodb::velocypack::Builder& out);
  
  // set the TTL feature's current properties
  static arangodb::Result setProperties(arangodb::velocypack::Slice properties, arangodb::velocypack::Builder& out);
};
}  // namespace methods
}  // namespace arangodb

#endif
