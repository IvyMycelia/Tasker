cmake_minimum_required(VERSION 3.20)
project(TASKER C)

set(CMAKE_C_STANDARD 11)

# === SOURCES ===
file(GLOB SOURCES "src/*.c")

add_executable(TASKER ${SOURCES})


# === INCLUDE HEADERS ===
target_include_directories(TASKER PRIVATE "include")


# === THIRD-PARTIES ===
# Non-Applicable

# === OUTPUT BINARY ===
set_target_properties(TASKER PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY          "${CMAKE_SOURCE_DIR}/bin"
	RUNTIME_OUTPUT_DIRECTORY_DEBUG    "${CMAKE_SOURCE_DIR}/bin/debug"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE  "${CMAKE_SOURCE_DIR}/bin/release"
)
