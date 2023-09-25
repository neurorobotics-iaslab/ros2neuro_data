cmake_minimum_required(VERSION 3.8)
project(ros2neuro_data)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ros2neuro_msgs REQUIRED)  
find_package(std_msgs REQUIRED)

# include directories
include_directories(include)

# ---- add the library
add_library(${PROJECT_NAME} SHARED
  src/NeuroData.cpp
  src/NeuroDataTools.cpp)
ament_target_dependencies(${PROJECT_NAME} rclcpp ros2neuro_msgs)
ament_export_libraries(${PROJECT_NAME})
ament_export_include_directories(include)
ament_export_dependencies(ros2neuro_msgs)

# ---- CPP Nodes:
add_executable(test_neurodata_tools src/test_neurodata_tools.cpp)
target_link_libraries(test_neurodata_tools ${PROJECT_NAME})
ament_target_dependencies(test_neurodata_tools rclcpp ros2neuro_msgs)

add_executable(test_neurodata src/test_neurodata.cpp)
target_link_libraries(test_neurodata ${PROJECT_NAME})
ament_target_dependencies(test_neurodata rclcpp ros2neuro_msgs)

add_executable(test_neurodata_operations src/test_neurodata_operations.cpp)
target_link_libraries(test_neurodata_operations ${PROJECT_NAME})
ament_target_dependencies(test_neurodata_operations rclcpp ros2neuro_msgs)

# ---- install
install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(TARGETS
  test_neurodata_tools
  test_neurodata
  test_neurodata_operations
  DESTINATION lib/${PROJECT_NAME})

# ---- to remove unused-parameters warnings
if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${PROJECT_NAME}  PRIVATE -Wno-unused-parameter)
    target_compile_options(test_neurodata PRIVATE -Wno-unused-parameter)
    target_compile_options(test_neurodata_tools PRIVATE -Wno-unused-parameter)
    target_compile_options(test_neurodata_operations PRIVATE -Wno-unused-parameter)
    target_compile_options(test_neurodata_tools PRIVATE -Wno-sign-compare)
    target_compile_options(test_neurodata_operations PRIVATE -Wno-sign-compare)
    target_compile_options(test_neurodata_tools PRIVATE -Wno-vla)
    target_compile_options(test_neurodata_operations PRIVATE -Wno-vla)
endif()


ament_package()

