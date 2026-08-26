class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;

        for (int i = 0; i < position.size(); i++) {
            double timeTaken =
                (double)(target - position[i]) / speed[i];

            cars.push_back({position[i], timeTaken});
        }

        sort(cars.begin(), cars.end(),
            [](const auto& a, const auto& b) {
                return a.first > b.first;
            });

        int fleets = 0;
        double maxTime = 0;

        for (const auto& car : cars) {
            double currentTime = car.second;

            if (currentTime > maxTime) {
                fleets++;
                maxTime = currentTime;
            }
        }

        return fleets;
    }
};