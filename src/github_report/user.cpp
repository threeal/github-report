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

  if (obj.contains("name") && obj.at("name").is_string()) {
    obj.at("name").get_to(name);
  } else {
    name = "null";
  }

  if (obj.contains("email") && obj.at("email").is_string()) {
    obj.at("email").get_to(email);
  } else {
    email = "null";
  }

  if (obj.contains("stars") && obj.at("stars").is_number()) {
    obj.at("stars").get_to(stars);
  } else {
    stars = 0;
  }

  if (obj.contains("followers") && obj.at("followers").is_number()) {
    obj.at("followers").get_to(followers);
  } else {
    followers = 0;
  }

  if (obj.contains("following") && obj.at("following").is_number()) {
    obj.at("following").get_to(following);
  } else {
    following = 0;
  }
}

std::ostream & operator<<(std::ostream & output, const User & user)
{
  return output <<
    "Name: " << user.name <<
    "\nEmail: " << user.email <<
    "\nStars: " << user.stars <<
    " Followers: " << user.followers <<
    " Following: " << user.following;
}

json User::to_json()
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
