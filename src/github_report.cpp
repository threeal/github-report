#include <argparse/argparse.hpp>
#include <curlpp/Exception.hpp>
#include <github_report/user.hpp>

#include <iostream>
#include <string>

int main(int argc, char ** argv)
{
  auto program = argparse::ArgumentParser("github_report", "0.1.0");

  program
    .add_argument("username")
    .help("username to be reported");

  program
    .add_argument("--json")
    .help("output as json instead")
    .default_value(false)
    .implicit_value(true);

  try {
    program.parse_args(argc, argv);

    try {
      std::cout << "Generating report..." << std::endl;

      auto username = program.get<std::string>("username");
      auto user = github_report::User(username);

      std::cout << std::endl;

      if (program.get<bool>("--json")) {
        std::cout << user.to_json().dump(2) << std::endl;
      } else {
        std::cout << user << std::endl;
      }
    } catch (const std::exception & e) {
      std::cout << e.what() << std::endl;
      return 1;
    }
  } catch (const std::exception & e) {
    std::cout << e.what() << std::endl;
    std::cout << program << std::endl;
    return 1;
  }

  return 0;
}
