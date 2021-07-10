#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Options.hpp>
#include <nlohmann/json.hpp>

#include <iostream>
#include <sstream>

using nlohmann::json;

int main(int argc, char ** argv)
{
  if (argc < 2) {
    std::cout << "Usage: ./github_report <username>" << std::endl;
    return 1;
  }

  std::string username(argv[1]);

  try {
    std::cout << "generating report..." << std::endl;
    curlpp::Cleanup cleaner;
    curlpp::Easy request;

    request.setOpt<curlpp::options::Url>(
      "https://api.github.com/users/" + username);

    request.setOpt<curlpp::options::HttpHeader>({
      "User-Agent: github-report"
    });

    std::stringstream ss;

    ss << request;

    auto json = json::parse(ss.str());

    std::cout << json.dump(2) << std::endl;
  } catch (curlpp::LogicError & e) {
    std::cout << e.what() << std::endl;
    return 1;
  } catch (curlpp::RuntimeError & e) {
    std::cout << e.what() << std::endl;
    return 1;
  }

  return 0;
}
