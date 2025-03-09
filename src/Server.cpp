#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <fmt/core.h>

static constexpr size_t MAGIC_STRING_WITH_NULL_SIZE = 16;
static constexpr size_t PAGE_SIZE_VALUE_SIZE = 2;
static constexpr size_t DB_HEADER_SIZE = 100;

int main(int argc, char *argv[]) {
  std::println(std::cerr, "Logs from your program will appear here");

  if (argc != 3) {
    std::println(std::cerr, "Expected two arguments");
    return EXIT_FAILURE;
  }

  std::string database_file_path = argv[1];
  std::string command = argv[2];

  if (command == ".dbinfo") {
    std::ifstream database_file(database_file_path, std::ios::binary);
    if (!database_file) {
      std::println(std::cerr, "Failed to open the database file");
      return EXIT_FAILURE;
    }
    // Skip the first 16 bytes of the header
    database_file.seekg(MAGIC_STRING_WITH_NULL_SIZE);
    char buffer[2];
    database_file.read(buffer, PAGE_SIZE_VALUE_SIZE);
    auto const page_size = ntohs(std::bit_cast<uint16_t>(buffer));
    fmt::println("database page size: {}", page_size);

    database_file.seekg(DB_HEADER_SIZE);

    auto const /*b_tree_page_type*/_ = database_file.get();
    database_file.read(buffer, 2);
    // auto const first_freeblock_on_page = ntohs(std::bit_cast<uint16_t>(buffer));
    database_file.read(buffer, 2);
    auto const number_of_cells_on_page = ntohs(std::bit_cast<uint16_t>(buffer));
    fmt::println("number of tables: {}", number_of_cells_on_page);

  }
  return EXIT_SUCCESS;
}
