#include "Car.h"


bool Car::init() {
    if(!Node::init()) {
        return false;
    }
    
    return true;
}
