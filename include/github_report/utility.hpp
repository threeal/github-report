#ifndef GITHUB_REPORT__UTILITY_HPP_
#define GITHUB_REPORT__UTILITY_HPP_

#include <nlohmann/json.hpp>

#include <list>

namespace github_report
{
  using Json = nlohmann::json;

  Json request_json(const std::string & url, const std::list<std::string> & headers = {});
} // namespace github_report

#endif  // GITHUB_REPORT__UTILITY_HPP_