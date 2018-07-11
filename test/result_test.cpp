#include <string>

#include <gtest/gtest.h>
#include <rose/result.hpp>

using rose::Result;

TEST(Result, int_ok) {
  auto res = Result<int, std::string>::ok(42);
  EXPECT_TRUE(res.is_ok());
  EXPECT_TRUE(!res.is_err());
  EXPECT_TRUE(res.ok() == 42);
  EXPECT_TRUE(res.unwrap() == 42);
}

TEST(Result, int_err) {
  auto res = Result<int, std::string>::err("error");
  EXPECT_TRUE(!res.is_ok());
  EXPECT_TRUE(res.is_err());
  EXPECT_TRUE(res.err() == "error");

  // Abort on unwrapping an error
  // res.unwrap();
}

TEST(Result, void_ok) {
  auto res = Result<void, std::string>::ok();
  EXPECT_TRUE(res.is_ok());
  EXPECT_TRUE(!res.is_err());
}

TEST(Result, void_err) {
  auto res = Result<void, std::string>::err("error");
  EXPECT_TRUE(!res.is_ok());
  EXPECT_TRUE(res.is_err());
  EXPECT_TRUE(res.err() == "error");
}
