////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2016 ArangoDB GmbH, Cologne, Germany
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

#ifndef ARANGODB_APPLICATION_FEATURES_V8SECURITY_FEATURE_H
#define ARANGODB_APPLICATION_FEATURES_V8SECURITY_FEATURE_H 1

#include "ApplicationFeatures/ApplicationFeature.h"
#include <regex>

namespace arangodb {

class V8SecurityFeature final : public application_features::ApplicationFeature {
 public:
  explicit V8SecurityFeature(application_features::ApplicationServer& server);

  void collectOptions(std::shared_ptr<options::ProgramOptions>) override final;
  void validateOptions(std::shared_ptr<options::ProgramOptions>) override final;
  void start() override final;
  
  /// @brief tests if the value of the startup option should be exposed to end
  /// users via JavaScript actions. will use _startupOptionsFilter*
  bool shouldExposeStartupOption(std::string const& name) const;
  
  /// @brief tests if the value of the environment variable should be exposed to end
  /// users via JavaScript actions. will use _environmentVariablesFilter*
  bool shouldExposeEnvironmentVariable(std::string const& name) const;

 private:
  /// @brief regular expression string for startup options filtering
  std::string _startupOptionsFilter;
  /// @brief regular expression generated from _startupOptionsFilter
  std::regex _startupOptionsFilterRegex;
 
  /// @brief regular expression string for environment variables filtering
  std::string _environmentVariablesFilter;
  /// @brief regular expression generated from _environmentVariablesFilter
  std::regex _environmentVariablesFilterRegex;
};

}  // namespace arangodb

#endif
