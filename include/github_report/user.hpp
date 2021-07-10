#ifndef GITHUB_REPORT__USER_HPP_
#define GITHUB_REPORT__USER_HPP_

#include <nlohmann/json.hpp>

#include <string>

namespace github_report
{

class User
{
public:
  User(const std::string & username);

  friend std::ostream & operator<<(std::ostream & output, const User & user);

  nlohmann::json to_json();

  std::string name;
  std::string email;

  int stars;
  int followers;
  int following;
};

}  // namespace github_report

#endif  // GITHUB_REPORT__USER_HPP_
