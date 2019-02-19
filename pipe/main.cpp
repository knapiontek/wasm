
#ifdef EMSCRIPTEN
// em++ -std=c++11 -O2 -o pipe.js main.cpp
#include <emscripten.h>
#else
#include <fstream>
#endif

#include <limits>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cassert>

const double pi = 4.0 * std::atan(1.0);

#include "point.hpp"
#include "paint.hpp"
#include "sparse.hpp"
#include "data.hpp"
#include "clip.hpp"
#include "convert.hpp"

#include "pipe.hpp"
#include "solve-pipe.hpp"

#ifdef EMSCRIPTEN
extern "C"
{
void EMSCRIPTEN_KEEPALIVE draw(float angle)
{
    solve_pipe::angle = angle;
    solve_pipe::run();
}
}
#else
int main()
{
    solve_pipe::run();
    return 0;
}
#endif
