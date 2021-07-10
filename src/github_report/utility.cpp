#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Options.hpp>
#include <github_report/utility.hpp>

#include <sstream>

namespace github_report
{

Json request_json(const std::string & url, const std::list<std::string> & headers)
{
  curlpp::Cleanup cleaner;
  curlpp::Easy request;

  request.setOpt<curlpp::options::Url>(url);
  request.setOpt<curlpp::options::HttpHeader>(headers);

  std::stringstream ss;
  ss << request;

  return Json::parse(ss.str());
}

std::string get_string_or(
  const Json & json, const std::string & key, const std::string & default_value)
{
  if (json.contains(key)) {
    auto & ref = json.at(key);
    if (ref.is_string()) {
      return ref.get<std::string>();
    }
  }

  return default_value;
}

int get_integer_or(
  const Json & json, const std::string & key, const int & default_value)
{
  if (json.contains(key)) {
    auto & ref = json.at(key);
    if (ref.is_number()) {
      return ref.get<int>();
    }
  }

  return default_value;
}

}  // namespace github_report
