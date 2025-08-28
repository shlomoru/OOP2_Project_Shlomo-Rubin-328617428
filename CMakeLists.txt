# CMakeList.txt : CMake project for OOP2_Project_Shlomo-Rubin-328617428, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.26)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("OOP2_Project_Shlomo-Rubin-328617428")
set (MY_AUTHORS "SHLOMO-RUBIN")

include (cmake/CompilerSettings.cmake)

# Add source to this project's executable.
add_executable (OOP2_Project_Shlomo-Rubin-328617428 "src/main.cpp" "include/GameObject.h" "include/Player.h" "src/Player.cpp" "include/IGameState.h" "include/Game.h" "src/Game.cpp" "include/MenuState.h" "src/MenuState.cpp" "include/PlayState.h" "src/PlayState.cpp")

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
if (NOT MSVC)
    target_link_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OOP2_Project_Shlomo-Rubin-328617428 PROPERTY CXX_STANDARD 20)
endif()

add_subdirectory (include)
add_subdirectory (src)
add_subdirectory (resources)

include (cmake/Zip.cmake)

set(SFML_LOCATION "C:/SFML/SFML-2.6.1")
set(SFML_DIR "C:/SFML/SFML-2.6.1/lib/cmake/SFML")

find_package (SFML 2.6 COMPONENTS graphics REQUIRED)

set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)

target_link_libraries (OOP2_Project_Shlomo-Rubin-328617428 sfml-graphics sfml-main)

include (cmake/SFML.cmake)



# TODO: Add tests and install targets if needed.
