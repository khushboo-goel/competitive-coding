/* The knows API is defined for you.
      bool knows(int a, int b); */

int findCelebrity(int n) {
    // vector<int> inbound(n, 0);
    // vector<int> outbound(n, 0);

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (i != j) {
    //             if (knows(i, j)) {
    //                 outbound[i] ++;
    //                 inbound[j] ++;
    //             }
    //         }
    //     }
    // }

    // int countCeleb = 0;
    // int celebIndex = -1;
    // for (int i = 0; i < n; i++) {
    //     if (inbound[i] == n - 1 && outbound[i] == 0) {
    //         countCeleb++;
    //         celebIndex = i;
    //     }
    // }

    // return countCeleb == 1 ? celebIndex : -1;

    int i = 0, j = 1;
    int celebIndex = 0;

   for (int i = 0; i < n; i++) {
       if (knows(celebIndex, i)) {
           celebIndex = i;
       }
   }

    bool isCeleb = true;
    for (int i = 0; i < n; i++) {
        if (celebIndex == i) continue;
        if (!knows(i, celebIndex) || knows(celebIndex, i)) {
            isCeleb = false;
            break;
        }
    }

    return isCeleb ? celebIndex : - 1;
}

// https://leetcode.com/problems/find-the-celebrity/description/
