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

  name = get_string_or(json, "name");
  email = get_string_or(json, "email");
  stars = get_integer_or(json, "stars");
  followers = get_integer_or(json, "followers");
  following = get_integer_or(json, "following");
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
