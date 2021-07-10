#include <github_report/user.hpp>

#include <sstream>

namespace github_report
{

User::User(const std::string & username)
{
  auto json = request_json(
    "https://api.github.com/users/" + username,
    {
      "User-Agent: github-report"
    });

  if (json.contains("name") && json.at("name").is_string()) {
    json.at("name").get_to(name);
  } else {
    name = "null";
  }

  if (json.contains("email") && json.at("email").is_string()) {
    json.at("email").get_to(email);
  } else {
    email = "null";
  }

  if (json.contains("stars") && json.at("stars").is_number()) {
    json.at("stars").get_to(stars);
  } else {
    stars = 0;
  }

  if (json.contains("followers") && json.at("followers").is_number()) {
    json.at("followers").get_to(followers);
  } else {
    followers = 0;
  }

  if (json.contains("following") && json.at("following").is_number()) {
    json.at("following").get_to(following);
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

Json User::to_json() const
{
  Json json;

  json["name"] = name;
  json["email"] = email;
  json["stars"] = stars;
  json["followers"] = followers;
  json["following"] = following;

  return json;
}

}  // namespace github_report
