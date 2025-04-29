cmake_minimum_required(VERSION 3.8)
project(ros_px4_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)

#Executável Nó trajetoria
add_executable(trajetoria)

#vincula as dependencia do nó trajetoria
ament_target_dependencies(trajetoria rclcpp geometry_msgs std_msgs) 

#faz ligação dos arquivos usados em trajetoria
target_sources(
  trajetoria

  PRIVATE

    src/Trajetoria_fixa/Trajetoria_fixa.cpp
    src/Trajetoria_fixa/Trajetoria_fixa.h
)

install(TARGETS
  trajetoria  
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
