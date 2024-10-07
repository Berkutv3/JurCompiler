cmake_minimum_required(VERSION 3.27)
project(gcc_starter VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include(CTest)
enable_testing()

# Codigo para añadir librerias Qt
#set(Qt6_DIR "C:/Qt/6.5.2/mingw_64/lib/cmake/Qt6")
#find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Codigo para añadir librerias boost
#set(BOOST_ROOT "C:/Program Files/Boost/boost_1_84_0/")
#find_package(Boost REQUIRED COMPONENTS)

#Codigo para añadir todos los archivos de src
file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

#Compiler enable feature and flags 
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wextra -Wshadow -Wunused  -Wdouble-promotion 
                    -Wnull-dereference -Wconversion -Wduplicated-cond -Wduplicated-branches 
                    -Wnon-virtual-dtor -Wuninitialized  -Wlogical-op -Wformat=2 -Wmisleading-indentation
                    -Wformat-overflow -pedantic)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
