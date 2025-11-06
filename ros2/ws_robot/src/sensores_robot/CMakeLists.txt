cmake_minimum_required(VERSION 3.5)
project(sensores_robot)

# Encontrar dependências
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Adicionar os nós C++ que você escreveu
add_executable(sensores_distancia_node src/sensores_distancia_node.cpp)
ament_target_dependencies(sensores_distancia_node rclcpp std_msgs)

add_executable(sensores_reflectancia_node src/sensores_reflectancia_node.cpp)
ament_target_dependencies(sensores_reflectancia_node rclcpp std_msgs)

# Instalar os binários compilados
install(TARGETS
  sensores_distancia_node
  sensores_reflectancia_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
