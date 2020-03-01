#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

struct Student {
	string s_name;
	int s_points;
};

struct Season {
    string name;
    double averageTemperature;
};

int main() {
    /*vector<Student> arr{
        { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 }, // Dan has the most points (8).
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 }
    };

    auto highestPoints = max_element(arr.begin(), arr.end(), [](Student s1, Student s2) {
        return s1.s_points < s2.s_points;
    });

    cout << highestPoints->s_name << " is the best student.\n";*/

    vector<Season> seasons{
        { "Spring", 285.0 },
        { "Summer", 296.0 },
        { "Fall", 288.0 },
        { "Winter", 263.0 }
    };

    sort(seasons.begin(), seasons.end(), [](const Season& s1, const Season& s2) {
        return (s1.averageTemperature < s2.averageTemperature);
    });

    for (const auto& season : seasons) {
        cout << season.name << '\n';
    }

	return 0;
}