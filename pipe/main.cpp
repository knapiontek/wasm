
#include <math.h>

const double pi = 4.0 * std::atan(1.0);

#include "point.hpp"
#include "paint.hpp"
#include "sparse.hpp"
#include "data.hpp"
#include "clip.hpp"
#include "convert.hpp"

#include "tetrahedron.hpp"
#include "solve-tetrahedron.hpp"
#include "pipe.hpp"
#include "solve-pipe.hpp"
#include "test.hpp"
#include "doc.hpp"
#include "gen-pipe.hpp"

int main(int argc, char* argv[])
{
	test::steepest_descent();
	test::conjagate_gradients();
	test::clip_triangles();
	test::intersection();

	solve_tetrahedron::run();
	solve_pipe::run();

	doc::store_figure_quadratic_form();
	doc::store_figure_levels();

	gen_pipe::run();

	return 0;
}
