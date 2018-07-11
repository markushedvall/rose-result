#ifndef ROSE_RESULT_HPP
#define ROSE_RESULT_HPP

#include <cstdlib>

#include <nonstd/expected.hpp>

namespace rose {

  template<class T, class E>
  struct Result {

    nonstd::expected<T, E> expected;

    bool is_ok() const noexcept {
      return expected.has_value();
    }

    bool is_err() const noexcept {
      return !expected.has_value();
    }

    T ok() const noexcept {
      return *expected;
    }

    E err() const noexcept {
      return expected.error();
    }

    T unwrap() const noexcept {
      if (is_err()) {
        abort();
      }
      return ok();
    }

    static Result<T, E> ok(T result) noexcept {
      return {result};
    }

    static Result<T, E> err(E error) noexcept {
      return {nonstd::make_unexpected(error)};
    }

  };

  template<class E>
  struct Result<void, E> {

    nonstd::expected<void, E> expected;

    bool is_ok() const noexcept {
      return expected.has_value();
    }

    bool is_err() const noexcept {
      return !expected.has_value();
    }

    E err() const noexcept {
      return expected.error();
    }

    static Result<void, E> ok() noexcept {
      return {};
    }

    static Result<void, E> err(E error) noexcept {
      return {nonstd::make_unexpected(error)};
    }

  };

}

#endif
