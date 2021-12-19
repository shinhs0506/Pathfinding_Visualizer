#include <utility>
#include <vector>

class Utility {
    public:
        static const std::vector<std::pair<int, int>> dirs;
        static bool isInbound(std::vector<std::vector<int>> grid, std::pair<int, int> cell);
};
