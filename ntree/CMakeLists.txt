set(BINARY MyLib)
set(SOURCE_F nvector.h nvector.cpp)
add_library(${BINARY} STATIC ${SOURCE_F} )
target_link_libraries(${BINARY} )