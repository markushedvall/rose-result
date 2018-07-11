from conans import ConanFile, CMake, tools


class RoseResultConan(ConanFile):
    name = "rose-result"
    version = "0.1.0"
    license = "MIT OR Apache-2.0"
    url = "https://github.com/markushedvall/rose-result"
    description = "Simple Result<T, E> API for returning errors"
    build_requires = "gtest/1.8.0@bincrafters/stable"
    settings = "os", "compiler", "arch", "build_type"
    generators = "cmake"
    exports_sources = "include/*", "test/*", "CMakeLists.txt"
    no_copy_source = True
    requires = "expected-lite/0.1.0@markushedvall/stable"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.test()

    def package(self):
        self.copy("*.hpp")

    def package_id(self):
        self.info.header_only()
