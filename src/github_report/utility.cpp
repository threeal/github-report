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

}  // namespace github_report
