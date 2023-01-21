class TrafficLight {
    int road1 = 1;
    int road2 = 0;
public:
    TrafficLight() {
        
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        if(roadId == 1 && road1 == 0){
            road2 = 0;
            road1 = 1;
            turnGreen();
            crossCar();
        }else if(roadId == 1 && road1 == 1){
            crossCar();
        }else if(roadId = 2 && road2 == 0){
            road2 = 1;
            road1 = 0;
            turnGreen();
            crossCar();
        }else if(roadId = 2 && road2 == 1){
            crossCar();
        }
    }
};