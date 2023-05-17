#include <iostream>
#include <vector>

class Vehicle {
public:
    int id;
    double position;
    double speed;

    Vehicle(int id, double position, double speed) : id(id), position(position), speed(speed) {}
};

class AdaptiveCruiseControl {
public:
    void updateSpeed(Vehicle &vehicle, const std::vector<Vehicle> &vehicles_ahead, double safe_distance) {
        double min_distance = -1;
        Vehicle *closest_vehicle = nullptr;

        for (const auto &veh : vehicles_ahead) {
            double distance = veh.position - vehicle.position;
            if (distance > 0 && (min_distance < 0 || distance < min_distance)) {
                min_distance = distance;
                closest_vehicle = const_cast<Vehicle *>(&veh);
            }
        }

        if (closest_vehicle) {
            if (min_distance <= safe_distance) {
                vehicle.speed = std::max(0.0, closest_vehicle->speed - (safe_distance - min_distance));
            } else {
                vehicle.speed = closest_vehicle->speed;
            }
        }
    }
};

int main() {
    Vehicle my_vehicle(1, 0, 60);
    std::vector<Vehicle> vehicles_ahead = { Vehicle(2, 100, 50), Vehicle(3, 200, 70) };
    double safe_distance = 20;

    AdaptiveCruiseControl acc;
    acc.updateSpeed(my_vehicle, vehicles_ahead, safe_distance);

    std::cout << "Updated speed: " << my_vehicle.speed << " km/h" << std::endl;

    return 0;
}
