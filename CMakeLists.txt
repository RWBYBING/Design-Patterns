cmake_minimum_required(VERSION 3.10)
project(design_patterns)

# Compiler Flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROGRAM_NAME calculator)

# Print Brief Info
message("PROJECT_NAME: ${PROJECT_NAME}")
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message("PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")

# Check the Binary Directory
if (PROJECT_BINARY_DIR STREQUAL PROJECT_SOURCE_DIR)
	message(WARNING "The binary directory of CMake cannot be the same as source directory!")
endif()

# Default Build Type
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
message("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

# Build Type Specific Flags
if (CMAKE_BUILD_TYPE STREQUAL Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g -std=c++17")
elseif (CMAKE_BUILD_TYPE STREQUAL Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -O3 -DNDEBUG -std=c++17")
endif()

# Windows _DNOMINMAX Problem Fix
if (WIN32)
	add_definitions(_DNOMINMAX -D_USE_MATH_DEFINES)
endif()

# Use Cache
if (NOT MSVC)
	find_program(CCACHE_PROGRAM ccache)
	if (CCACHE_PROGRAM)
		message(STATUS "Found CCache: ${CCACHE_PROGRAM}")
		set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_PROGRAM})
        set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ${CCACHE_PROGRAM})
    endif()
endif()


add_subdirectory("2. Singleton")
add_subdirectory("3. Factory Method")
add_subdirectory("4. Abstract Factory")
add_subdirectory("5. Builder")
add_subdirectory("6. Adapter")
add_subdirectory("7. Decorator")
add_subdirectory("8. Facade")
add_subdirectory("9. Proxy")
add_subdirectory("10. Bridge")
add_subdirectory("11. Observer")
add_subdirectory("12. Strategy")
add_subdirectory("13. Command")