#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <print>

int main(int argc, char *argv[]) {
  std::print(std::cerr, "Logs from your program will appear here");

  if (argc != 3) {
    std::print(std::cerr, "Expected two arguments");
    return EXIT_FAILURE;
  }

  std::string database_file_path = argv[1];
  std::string command = argv[2];

  if (command == ".dbinfo") {
    std::ifstream database_file(database_file_path, std::ios::binary);
    if (!database_file) {
      std::print(std::cerr, "Failed to open the database file");
      return EXIT_FAILURE;
    }
    database_file.seekg(16); // Skip the first 16 bytes of the header
    char buffer[2];
    database_file.read(buffer, 2);
    auto const page_size = ntohs(std::bit_cast<uint16_t>(buffer));
    std::print("database page size: {}", page_size);
  }
  return EXIT_SUCCESS;
}
