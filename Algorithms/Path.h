#ifndef PATH_H
#define PATH_H

#include <vector>
#include <utility>

struct Path {
    std::vector<std::pair<int, int>> visited;
    std::vector<std::pair<int, int>> shortest;
};

#endif
