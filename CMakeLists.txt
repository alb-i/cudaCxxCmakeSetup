cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

set(CUDA_PROJECT_NAME cudaProject)
set(MAIN_EXEC main)

project(${CUDA_PROJECT_NAME} LANGUAGES CUDA CXX)

include(CheckLanguage)

check_language(CUDA)

if(NOT DEFINED CMAKE_CUDA_STANDARD)
    set(CMAKE_CUDA_STANDARD 17)
    set(CMAKE_CUDA_STANDARD_REQUIRED ON)
endif()

FILE(GLOB MY_INC_DIR "inc" "inc/other_authors")
include_directories("${MY_INC_DIR}")


FILE(GLOB MY_SRC src/*.cxx src/*.cu)
FILE(GLOB MY_HEADERS inc/*.h)

add_executable(${MAIN_EXEC} ${MY_SRC} ${MY_HEADERS})


# BOOST libraries

add_definitions( -DBOOST_ALL_NO_LIB )

# TODO: setup components

find_package(Boost 1.67.0 COMPONENTS program_options regex thread system filesystem chrono date_time atomic ) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    target_link_libraries(${MAIN_EXEC} ${Boost_LIBRARIES})
endif()






