#include <github_report/user.hpp>

#include <iostream>
#include <sstream>

namespace github_report
{

User::User(const std::string & username)
: name("null"),
  email("null"),
  stars(0),
  followers(0),
  following(0)
{
  try {
    auto json = request_json("https://api.github.com/users/" + username);

    name = get_string_or(json, "name", name);
    email = get_string_or(json, "email", email);
    followers = get_integer_or(json, "followers", followers);
    following = get_integer_or(json, "following", following);
  } catch (const std::exception & e) {
    std::cout << "Warning! " << e.what() << std::endl;
  }

  try {
    auto json = request_json("https://api.github.com/users/" + username + "/starred");
    if (json.is_array()) {
      stars = json.size();
    }
  } catch (const std::exception & e) {
    std::cout << "Warning! " << e.what() << std::endl;
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
