#include<iostream>

class ACC {
    double vehicle_speed;
    double vehicle_front_speed;
    double distance_to_vehicle_front;
    double desired_distance;
public:
    ACC(double desired_distance) : desired_distance(desired_distance) {}

    void update(double vehicle_speed, double vehicle_front_speed, double distance_to_vehicle_front) {
        this->vehicle_speed = vehicle_speed;
        this->vehicle_front_speed = vehicle_front_speed;
        this->distance_to_vehicle_front = distance_to_vehicle_front;
    }

    double control() {
        if (distance_to_vehicle_front < desired_distance) {
            if (vehicle_speed > vehicle_front_speed) {
                return -1;  // decelerate
            } else {
                return 0;   // maintain speed
            }
        } else {
            return 1;  // accelerate
        }
    }
};

int main() {
    ACC acc(20.0);  // Maintain 20 meter distance to the vehicle in front

    // In a real scenario, the following data would be continuously updated from sensors
    acc.update(60.0, 10.0, 15.0);  // Current speed, front vehicle speed, and distance to front vehicle

    double control_output = acc.control();

    if (control_output < 0) {
        std::cout << "Decelerate" << std::endl;
    } else if (control_output > 0) {
        std::cout << "Accelerate" << std::endl;
    } else {
        std::cout << "Maintain current speed" << std::endl;
    }

    return 0;
}
