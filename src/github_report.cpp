#include <curlpp/Exception.hpp>
#include <github_report/user.hpp>

#include <iostream>

int main(int argc, char ** argv)
{
  if (argc < 2) {
    std::cout << "Usage: ./github_report <username>" << std::endl;
    return 1;
  }

  std::string username(argv[1]);

  try {
    std::cout << "Generating report..." << std::endl;
    std::cout << github_report::User(username) << std::endl;
  } catch (curlpp::LogicError & e) {
    std::cout << e.what() << std::endl;
    return 1;
  } catch (curlpp::RuntimeError & e) {
    std::cout << e.what() << std::endl;
    return 1;
  }

  return 0;
}
