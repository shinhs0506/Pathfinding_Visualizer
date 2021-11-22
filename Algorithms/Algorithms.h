#include <vector>
#include <utility>

class Algorithms {
    public :
        virtual std::vector<std::pair<int, int>> solve(
                std::vector<int, int> board, 
                std::pair<int, int> &start, 
                std::pair<int, int> &finish) = 0;
};
