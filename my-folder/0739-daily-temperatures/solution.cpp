class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*
        iterate through the array in reverse
        at the first day, loop until a larger number is found
        */
        int numDays = temperatures.size();

        vector<int> warmerDays(numDays, 0);
        for (int day = numDays - 1; day >= 0; --day) {
            if (day == numDays - 1) {
                warmerDays[day] = 0;
            }
            else {
                /* Cases:
                - current day is colder than next day
                    - num days = 1
                - current day is warmer or same as next day
                    - next day's num warmer is 0, num days = 0
                    - next day's num warmer is a certain number
                        - 
                */
                if (temperatures[day] < temperatures[day + 1])
                    warmerDays[day] = 1;
                else {
                    // warmer than next day
                    int nextDayNumDaysTillWarmer = warmerDays[day + 1];
                    if (nextDayNumDaysTillWarmer == 0) {
                        // nothing warmer
                        warmerDays[day] = 0;
                    }
                    else {
                        int k;
                        for (k = day + 1 + nextDayNumDaysTillWarmer; k < numDays; ++k) {
                            if (temperatures[k] > temperatures[day]) {
                                warmerDays[day] = k - day;
                                break;
                            }
                            if (warmerDays[k] == 0) {
                                warmerDays[day] = 0;
                                break;
                            }
                        }
                        if (k >= numDays) {
                            // never happens
                            warmerDays[day] = 0;
                        }
                    }
                }
            }
        }


        return warmerDays;
    }
};
