# GitHub Report

This project contains a CLI program to obtains overall report from a specific [GitHub](http://github.com/) user.

## Requirements

- [cUrlpp](https://github.com/jpbarrette/curlpp/).
- [argparse](https://github.com/p-ranav/argparse).
- nlohmann's [json](https://github.com/nlohmann/json).
- C++17.

## Usage

Run `github_report` program with `-h` options to view the program usage.

## Build from Source

- Build and install each dependencies (see requirements for the detail).
- Create a new build directory.
  ```sh
  $ mkdir build && cd build
  ```
- Configure CMake.
  ```sh
  $ cmake ..
  ```
- Build and install.
  ```sh
  $ make -j8 && make install
  ```

## License

This project is licensed under the [MIT license](./LICENSE).
