#ifndef GITHUB_REPORT__UTILITY_HPP_
#define GITHUB_REPORT__UTILITY_HPP_

#include <nlohmann/json.hpp>

#include <list>

namespace github_report
{
  using Json = nlohmann::json;

  Json request_json(const std::string & url, std::list<std::string> headers = {});

  std::string get_string_or(
    const Json & json, const std::string & key, const std::string & default_value = "null");

  int get_integer_or(
    const Json & json, const std::string & key, const int & default_value = 0);
} // namespace github_report

#endif  // GITHUB_REPORT__UTILITY_HPP_