#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Options.hpp>

#include <iostream>

int main(int argc, char ** argv)
{
  if (argc < 2) {
    std::cout << "Usage: ./github_report <username>" << std::endl;
    return 1;
  }

  std::string username(argv[1]);

  try {
    curlpp::Cleanup cleaner;
    curlpp::Easy request;

    request.setOpt<curlpp::options::Url>(
      "https://api.github.com/users/" + username);

    request.setOpt<curlpp::options::HttpHeader>({
      "User-Agent: github-report"
    });

    std::cout << request << std::endl;
  } catch (curlpp::LogicError & e) {
    std::cout << e.what() << std::endl;
    return 1;
  } catch (curlpp::RuntimeError & e) {
    std::cout << e.what() << std::endl;
    return 1;
  }

  return 0;
}
