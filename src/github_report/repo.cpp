#include <github_report/repo.hpp>

namespace github_report
{

Repo::Repo()
: name("null")
{
}

std::ostream & operator<<(std::ostream & output, const Repo & repo)
{
  return output << repo.name;
}

Json Repo::to_json() const
{
  Json json;

  json["name"] = name;

  return json;
}

}  // namespace github_report
