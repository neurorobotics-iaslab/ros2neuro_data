#ifndef ROS2NEURO_NEURODATA_TOOLS_HPP
#define ROS2NEURO_NEURODATA_TOOLS_HPP

#include "rclcpp/rclcpp.hpp"
#include "ros2neuro_data/NeuroData.hpp"
#include "ros2neuro_msgs/msg/neuro_data_int32.hpp"                                        
#include "ros2neuro_msgs/msg/neuro_data_float.hpp"
#include "ros2neuro_msgs/msg/neuro_data_info.hpp"
#include "ros2neuro_msgs/msg/neuro_frame.hpp"

namespace rosneuro {

class NeuroDataTools {

    public:

        static bool ConfigureNeuroMessage(const NeuroFrame& frame, ros2neuro_msgs::msg::NeuroFrame& msg);
        static bool ConfigureNeuroFrame(const ros2neuro_msgs::msg::NeuroFrame& msg, NeuroFrame& frame);

        static bool FromNeuroInfo(const NeuroDataInfo& info, ros2neuro_msgs::msg::NeuroDataInfo& msg);
        static bool ToNeuroInfo(const ros2neuro_msgs::msg::NeuroDataInfo& msg, NeuroDataInfo& info);

        static bool FromNeuroFrame(const NeuroFrame& frame, ros2neuro_msgs::msg::NeuroFrame& msg);
        static bool ToNeuroFrame(const ros2neuro_msgs::msg::NeuroFrame& msg, NeuroFrame& frame);

        static bool FromNeuroData(const NeuroData<float>& data, ros2neuro_msgs::msg::NeuroDataFloat& msg);
        static bool FromNeuroData(const NeuroData<int32_t>& data, ros2neuro_msgs::msg::NeuroDataInt32& msg);

        // TODO
        static bool ToNeuroData(const ros2neuro_msgs::msg::NeuroDataFloat& msg, NeuroData<float>& data);
        static bool ToNeuroData(const ros2neuro_msgs::msg::NeuroDataInt32& msg, NeuroData<int32_t>& data);
/*
        static void ConfigureDataLayout(size_t ns, size_t nch, std_msgs::MultiArrayLayout& layout);
        */

    private:
        NeuroDataTools(void) {};

};

}

#endif
