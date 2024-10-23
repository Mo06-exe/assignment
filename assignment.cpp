#include <iostream>
#include <cmath>
#include <vector>

const int Y = 5;

// Function to calculate the distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Function to calculate speed based on height
double speed(int y) {
    return std::sqrt(2 * 10 * (Y - y));
}

// Function to calculate average speed
double average_speed(double s1, double s2) {
    return (s1 + s2) / 2.0;
}

int main() {
    std::vector<std::vector<int>> path1 = {
        {0, 5},
        {0, 4},
        {1, 3},
        {2, 3},
        {3, 2},
        {4, 1},
        {4, 0},
        {5, 0}
    };

    std::vector<std::vector<int>> path2 = {
        {0, 5},
        {0, 4},
        {1, 4},
        {2, 3},
        {3, 3},
        {4, 2},
        {4, 1},
        {5, 0}
    };

    double t1 = 0;
    double t2 = 0;

    // Calculate time for path1
    for (size_t i = 0; i < path1.size() - 1; ++i) {
        double s1 = speed(path1[i][1]);
        double s2 = speed(path1[i + 1][1]);
        t1 += distance(path1[i][0], path1[i][1], path1[i + 1][0], path1[i + 1][1]) / average_speed(s1, s2);
    }

    std::cout << t1 << std::endl;

    // Calculate time for path2
    for (size_t i = 0; i < path2.size() - 1; ++i) {
        double s1 = speed(path2[i][1]);
        double s2 = speed(path2[i + 1][1]);
        t2 += distance(path2[i][0], path2[i][1], path2[i + 1][0], path2[i + 1][1]) / average_speed(s1, s2);
    }

    std::cout << t2 << std::endl;

    int W[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {5, 3, 3, 5, 4, 1},
        {2, 5, 4, 4, 4, 2},
        {5, 5, 2, 1, 3, 1},
        {4, 2, 3, 4, 4, 1},
        {1, 5, 5, 5, 2, 3}
    };

    std::cout << "W array before updates:\n";
    for (const auto& row : W) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> fast, slow;
    if (t1 < t2) {
        fast = path1;
        slow = path2;
    } else {
        fast = path2;
        slow = path1;
    }

    // Update W based on fast path
    for (const auto& coord : fast) {
        int x = coord[0];
        int y = coord[1];
        W[Y-y][x] += 1;
    }

    // Update W based on slow path
    for (const auto& coord : slow) {
        int x = coord[0];
        int y = coord[1];
        W[Y-y][x] -= 1;
    }

    std::cout << "Updated W array:\n";
    for (const auto& row : W) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}



//ttutut