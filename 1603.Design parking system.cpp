class ParkingSystem final {
public:
    explicit ParkingSystem(int big, int medium, int small) noexcept : big_(big), medium_(medium), small_(small)  {}

    bool addCar(int carType) noexcept {
        if (carType == 3) {
            if (small_ > 0) {
                small_--;
                return true;
            } else {
                return false;
            }
        } else if (carType == 2) {
            if (medium_ > 0) {
                medium_--;
                return true;
            } else {
                return false;
            }
        } else {
            if (big_ > 0) {
                big_--;
                return true;
            } else {
                return false;
            }
        }
    }

private:
    int big_, medium_, small_;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */