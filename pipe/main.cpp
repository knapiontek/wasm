
#include <limits>
#include <string>
#include <vector>
#include <map>
#include <fstream>
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

int main(int argc, char* argv[])
{
	solve_pipe::run();
	return 0;
}

