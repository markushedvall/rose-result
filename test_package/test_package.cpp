#include <string>

#include <rose/result.hpp>

using rose::Result;

int main() {
  auto res = Result<int, std::string>::ok(42);
}
