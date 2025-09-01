cmake_minimum_required (VERSION 3.26)

project (OOP2_Project_Shlomo-Rubin-328617428)
set (MY_AUTHORS "Shlomo Rubin")

include (cmake/CompilerSettings.cmake)

set(SOURCES 
    "src/main.cpp" 
    "src/Game.cpp" 
    "src/MenuState.cpp" 
    "src/Player.cpp" 
    "src/PlayState.cpp"  
    )

set(HEADERS
    "include/Game.h"
    "include/GameObject.h"
    "include/IGameState.h"
    "include/MenuState.h"
    "include/Player.h"
    "include/PlayState.h"
)

add_executable (${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS} "src/LevelManager.cpp" "include/LevelManager.h" "include/Platform.h" "src/Platform.cpp" "include/Obstacle.h" "src/Obstacle.cpp" "include/Goal.h" "src/Goal.cpp" "include/GameOverState.h" "src/GameOverState.cpp")

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
if (NOT MSVC)
    target_link_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
endif()

add_subdirectory (include)
add_subdirectory (src)
add_subdirectory (resources)

include (cmake/Zip.cmake)

set (SFML_LOCATION "C:/SFML/SFML-2.6.1")
set (SFML_DIR "${SFML_LOCATION}/lib/cmake/SFML")

find_package (SFML 2.6 COMPONENTS graphics REQUIRED)

set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)

target_link_libraries (${CMAKE_PROJECT_NAME} sfml-graphics sfml-main)

add_custom_command(TARGET OOP2_Project_Shlomo-Rubin-328617428 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        $<TARGET_FILE_DIR:OOP2_Project_Shlomo-Rubin-328617428>/resources
)


include (cmake/SFML.cmake)

