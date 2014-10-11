# Add executable called "helloDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.
set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_BUILD_TYPE "Debug")
add_executable (simple_list simple_list.c)

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
#target_link_libraries (helloDemo LINK_PUBLIC Hello)