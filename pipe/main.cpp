
// em++ -std=c++11 -O2 -o pipe.js main.cpp

#include <limits>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <cmath>
#include <cassert>
#include <iostream>

const double pi = 4.0 * std::atan(1.0);

#include "point.hpp"
#include "paint.hpp"
#include "sparse.hpp"
#include "data.hpp"
#include "clip.hpp"
#include "convert.hpp"

#include "pipe.hpp"
#include "solve-pipe.hpp"

int main()
{
    std::multimap<int, int> points = {{1,2}, {1,3}, {1,4}, {2,3}, {2,4}, {2,5}};
    for(auto& it : points) {
        std::cout << it.first << ":" << it.second << std::endl;
    }
    std::cout << "equal_range" << std::endl;
    auto range1 = points.equal_range(1);
    auto range2 = points.equal_range(2);
    for(auto it1 = range1.first; it1 != range1.second; it1++) {
        for(auto it2 = range2.first; it2 != range2.second; it2++) {
            std::cout << "(" << it1->first << ":" << it1->second << ") - (" << it2->first << ":" << it2->second << ")" << std::endl;
            if(it1->second == it2->second)
                std::cout << "[" << it1->second << ":" << it2->second << "]" << std::endl;
        }
    }
    solve_pipe::run();
    return 0;
}
