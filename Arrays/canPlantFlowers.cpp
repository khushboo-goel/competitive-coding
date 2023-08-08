bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0) {
        return true;
    }
    int length = flowerbed.size();
    if (length == 0) {
        return false;
    }

    if (length == 1 && n == 1) {
        if (flowerbed[0] == 0) {
            return true;
        }
        return false;
    }

    long count = 0;
    for (int i = 0; i < length ; i++) {
        if ( i == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
            count++;
            i++;
        } 
        else if (i == length - 1 && flowerbed[i - 1] == 0 && flowerbed[i] == 0) {
            count++;
            i++;
        } else if ( (i != 0 && i != length -1 ) && flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
            count++;
            i++;
        }
    }

    if (count >= n) {
        return true;
    }

    return false;
}

// https://leetcode.com/problems/can-place-flowers/description/?envType=study-plan-v2&envId=leetcode-75
