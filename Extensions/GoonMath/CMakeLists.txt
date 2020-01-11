# Target name
set(target GoonMath)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/main.cpp
)

set(INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/vector.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/util.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/vectorial.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/bitwise.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/simd/simd2f.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/simd/simd4f.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/internal/vector2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/internal/vector2_simd.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/internal/vector3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/internal/vector3_simd.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/internal/vector4.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes/gm/internal/vector4_simd.h
)

add_executable(GoonMath ${SOURCES} ${INCLUDES})

target_include_directories(GoonMath
PUBLIC
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Includes
)

target_link_libraries(GoonMath
PUBLIC
PRIVATE
)