
namespace solve_pipe
{
    const int point_size = sizeof(pipe::point_list) / sizeof(Point3D);
    const int element_size = sizeof(pipe::element_list) / sizeof(data::Element);
    const int fix_size = sizeof(pipe::fix_list) / sizeof(data::Fix);
    const int force_size = sizeof(pipe::force_list) / sizeof(data::Force);

    Point3D displace_list[point_size];
    data::Force reaction_list[fix_size];

    Point3D rotate(const Point3D& p)
    {
        const double rot_x = .1; // rotation angle around axis X
        const double rot_y = pi / 4; // rotation angle around axis Z
        const double c_x = std::cos(rot_x);
        const double s_x = std::sin(rot_x);
        const double c_y = std::cos(rot_y);
        const double s_y = std::sin(rot_y);

        return Point3D
        (
            c_y * p.x - s_y * p.z,
            - s_x * s_y * p.x + c_x * p.y - s_x * c_y * p.z,
            c_x * s_y * p.x + s_x * p.y - c_x * c_y * p.z
        );
    }

    void store_figure_pipe(std::vector<clip::Element>& original_elements, std::vector<clip::Element>& displace_elements)
    {
        Paint paint("figure-pipe.txt");

        Point3D west(-4.0, 3.0, 0.0), mid(-6.0, -2.0, 0.0), east(4.0, 3.0, 0.0);

        // draw point_list
        for(auto& e : original_elements)
        {
            if(e.pt1 != e.pt2)
            {
                paint.line(west + e.pt1, west + e.pt2);
            }
        }

        // draw elements
        for(auto& e : displace_elements)
        {
            if(e.pt1 != e.pt2)
            {
                double norm1 = Point2D::norm2(pipe::point_list[e.p1], pipe::point_list[e.p2]);
                double norm2 = Point2D::norm2(displace_list[e.p1], displace_list[e.p2]);
                double delta = norm2 - norm1;

                if(delta < 0)
                {
                    paint.line(east + e.pt1, east + e.pt2);
                }
                else if(delta > 0)
                {
                    paint.line(east + e.pt1, east + e.pt2);
                }
                else
                {
                    paint.dot(east + e.pt1);
                    paint.dot(east + e.pt2);
                }
            }
        }

        // draw forces
        for(auto& f : pipe::force_list)
        {
            Point3D pt1 = displace_list[f.p];
            Point3D pt2 = pt1 + 0.005 * f.val;
            Point2D pt1r = east + rotate(pt1);
            Point2D pt2r = east + rotate(pt2);
            paint.line(pt1r, pt2r);
        }
    }

    void conjagate_gradients(sp::Vector& dp, const sp::SymetryMatrix& K, const sp::Vector& F)
    {
        auto r0 = K * dp;
        r0 -= F;
        r0 *= -1.0; // r0 := B - A * x
        auto p = r0;

        for(int i = 0; i < 1e6; i++)
        {
            double a = (r0 * r0) / (p * K * p);

            dp += a * p; // dp := dp + a * p

            auto aKp = K * p;
            aKp *= a;
            auto r1 = r0 - aKp; // r1 := r0 - a * K * p

            if(r1 * r1 < 1e-10)
            {
                break;
            }

            double b = (r1 * r1) / (r0 * r0);

            p *= b;
            p += r1; // p := r1 + b * p

            r0 = r1;
        }
    }

    void run()
    {
        // init
        sp::size = convert::init(pipe::fix_list, point_size);

        // populate kmx, tmx
        convert::matrix(pipe::point_list, pipe::element_list, element_size);

        sp::SymetryMatrix K = convert::kmx;

        // populate F
        auto F = convert::force(pipe::force_list, force_size);

        // solve K * dp = F with conjagate_gradients
        sp::Vector dp;
        conjagate_gradients(dp, K, F);
        assert(sp::Vector::norm2(K * dp, F) < 1e-10);

        // solve tensions
        std::vector<double> reaction(3 * point_size - sp::size);
        sp::mul(reaction, convert::tmx, dp);

        // convert back to 3D domain
        for(auto i = 0; i < point_size; ++i)
        {
            displace_list[i] = pipe::point_list[i];
        }
        convert::displace(displace_list, dp);
        convert::reaction(reaction_list, pipe::fix_list, fix_size, reaction);

        // store
        auto original_elements = clip::make(pipe::point_list, pipe::element_list, element_size, rotate);
        auto displace_elements = clip::make(displace_list, pipe::element_list, element_size, rotate);
        store_figure_pipe(original_elements, displace_elements);
    }
}

