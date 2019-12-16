# Target name
set(target SRFramework)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.cpp
)

set(INCLUDES
)

add_executable(SRFramework ${SOURCES} ${INCLUDES})

target_include_directories(SRFramework
PUBLIC
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(SRFramework
PUBLIC
PRIVATE
)