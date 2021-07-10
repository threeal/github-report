#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Options.hpp>
#include <github_report/user.hpp>

#include <sstream>

namespace github_report
{

using nlohmann::json;

User::User(const std::string & username)
{
  curlpp::Cleanup cleaner;
  curlpp::Easy request;

  request.setOpt<curlpp::options::Url>(
    "https://api.github.com/users/" + username);

  request.setOpt<curlpp::options::HttpHeader>({
    "User-Agent: github-report"
  });

  std::stringstream ss;

  ss << request;

  auto obj = json::parse(ss.str());

  if (obj.at("name").is_string()) {
    obj.at("name").get_to(name);
  } else {
    name = "null";
  }

  if (obj.at("email").is_string()) {
    obj.at("email").get_to(email);
  } else {
    email = "null";
  }
}

std::ostream & operator<<(std::ostream & output, const User & user)
{
  return output <<
    "Name: " << user.name <<
    "\nEmail: " << user.email <<
    "\nStars: " << user.stars <<
    "Followers: " << user.followers <<
    "Following: " << user.following;
}

json User::dump()
{
  json obj;

  obj["name"] = name;
  obj["email"] = email;
  obj["stars"] = stars;
  obj["followers"] = followers;
  obj["following"] = following;

  return obj;
}

}  // namespace github_report
