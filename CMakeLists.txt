cmake_minimum_required(VERSION 3.18)
project(SemestralkaPOS)

set(CMAKE_CXX_STANDARD 17)

add_executable(SemestralkaPOS main.cpp socket/my_socket.cpp hra/vzor.cpp utility/subor_handler.cpp utility/konvertor.cpp utility/subor_handler.cpp hra/hra.cpp)
target_link_libraries(SemestralkaPOS wsock32 ws2_32)