# CMakeList.txt : CMake project for curs_students, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("curs_students")

# Add source to this project's executable.
add_executable (curs_students "main.cpp"  "Student/Student/Student.cpp" "Student/Student/Student.h" "Student/jsonLoader.cpp"  "Student/Crypto/Crypto.cpp"  "Student/Crypto/Crypto.h")

#Add include directories
include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(curs_students PRIVATE nlohmann_json::nlohmann_json)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET curs_students PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
