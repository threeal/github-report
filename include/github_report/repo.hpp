#ifndef GITHUB_REPORT__REPO_HPP_
#define GITHUB_REPORT__REPO_HPP_

#include <string>

#include "./utility.hpp"

namespace github_report
{

class Repo
{
public:
  Repo();

  friend std::ostream & operator<<(std::ostream & output, const Repo & repo);

  Json to_json() const;

  std::string name;
};

}  // namespace github_report

#endif  // GITHUB_REPORT__REPO_HPP_
