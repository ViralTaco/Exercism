#include "vehicle_purchase.h"

namespace vehicle_purchase {

// Only "car" and "truck" require a license.
bool needs_license(std::string kind) {
    return kind == "car" || kind == "truck";
}

// Recommends the lexicographically first vehicle followed by a fixed phrase.
std::string choose_vehicle(std::string option1, std::string option2) {
    std::string choice = (option1 < option2) ? option1 : option2;
    return choice + " is clearly the better choice.";
}

// Estimates resell price based on vehicle age brackets:
// < 3 years: 80% | 3-10 years: 70% | >= 10 years: 50%
double calculate_resell_price(double original_price, double age) {
    double percentage{0.0};
    
    if (age < 3) {
        percentage = 0.80;
    } else if (age < 10) {
        percentage = 0.70;
    } else {
        percentage = 0.50;
    }
    
    return original_price * percentage;
}

}  // namespace vehicle_purchase