# CMakeList.txt : CMake project for XEv, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (XEv "XEv.cpp"  "src/lexer.cpp" "src/include/lexer.h")

# TODO: Add tests and install targets if needed.
