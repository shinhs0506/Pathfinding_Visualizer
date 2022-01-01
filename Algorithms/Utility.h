#include <utility>
#include <vector>
#include <cmath>

class Utility {
    public:
        static const std::vector<std::pair<int, int>> dirs;
        static bool isInbound(std::vector<std::vector<int>> grid, std::pair<int, int> cell);
        static double euclideanDistance(int x1, int y1, int x2, int y2);
};
