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
  following(0),
  repos({})
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

  try {
    auto json = request_json("https://api.github.com/users/" + username + "/repos");
    if (json.is_array()) {
      for (const auto & obj : json) {
        Repo repo;

        repo.name = get_string_or(obj, "name", repo.name);

        repos.push_back(repo);
      }
    }
  } catch (const std::exception & e) {
    std::cout << "Warning! " << e.what() << std::endl;
  }
}

std::ostream & operator<<(std::ostream & output, const User & user)
{
  output <<
    "Name: " << user.name <<
    "\nEmail: " << user.email <<
    "\nStars: " << user.stars <<
    " Followers: " << user.followers <<
    " Following: " << user.following;

  output << "\n\nRepositories:";
  for (const auto & repo : user.repos) {
    output << "\n- " << repo;
  }

  return output;
}

Json User::to_json() const
{
  Json json;

  json["name"] = name;
  json["email"] = email;
  json["stars"] = stars;
  json["followers"] = followers;
  json["following"] = following;

  for (const auto & repo : repos) {
    json["repos"].push_back(repo.to_json());
  }

  return json;
}

}  // namespace github_report
