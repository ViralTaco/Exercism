namespace targets {

class Alien {
    public:
        // Constructor to initialize position
        Alien(int x, int y) {
            x_coordinate = x;
            y_coordinate = y;
        }

        // Returns current health
        int get_health() {
            return health;
        }

        // Reduces health by 1, ensures it doesn't drop below 0
        bool hit() {
            if (health > 0) {
                health--;
            }
            return true;
        }

        // Returns true if health is 0
        bool is_alive() {
            return health > 0;
        }

        // teleports alien to a new coordinate
        bool teleport(int x, int y) {
            x_coordinate = x;
            y_coordinate = y;
            return true;
        }

        // Checks if alien is at a specific position
        bool collision_detection(Alien other) {
            return x_coordinate == other.x_coordinate && 
                   y_coordinate == other.y_coordinate;
        }

        // Position coordinates
        int x_coordinate;
        int y_coordinate;

    private:
        // Internal state
        int health{3};
};

}  // namespace targets