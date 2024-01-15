// https://leetcode.com/problems/design-parking-system/description/

class ParkingSystem {
public:
    map<int, int> capacity;
    map<int, int> currCap;
    ParkingSystem(int big, int medium, int small) {
        capacity[1] = big;
        capacity[2] = medium;
        capacity[3] = small;

        currCap[1] = 0;
        currCap[2] = 0;
        currCap[3] = 0;
    }
    
    bool addCar(int carType) {
        if(currCap[carType] < capacity[carType]) {
            currCap[carType]++;
            return true;
        }

        return false;
    }
};
