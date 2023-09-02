bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    if (targetCapacity > jug1Capacity + jug2Capacity){
        return false;
    }
    if (jug1Capacity == targetCapacity || jug2Capacity == targetCapacity || jug1Capacity + jug2Capacity == targetCapacity) {
        return true;
    }
    // j1 should be greater than j2
    if (jug2Capacity > jug1Capacity) {
        int tmp = jug1Capacity;
        jug1Capacity = jug2Capacity;
        jug2Capacity = tmp;
    }

    while (jug1Capacity % jug2Capacity != 0) {
        int tmp = jug2Capacity;
        jug2Capacity = jug1Capacity % jug2Capacity;
        jug1Capacity = tmp; 
    }

    if (jug2Capacity == 1 || targetCapacity % jug2Capacity == 0) {
        return true;
    }

    return false;
}
