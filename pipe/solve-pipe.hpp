
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

    void store_figure_pipe(std::vector<clip::Element>& displace_elements)
    {
        Paint paint("figure-pipe.txt");

        // draw elements
        for(auto& e : displace_elements)
        {
            if(e.pt1 != e.pt2)
            {
                double norm1 = Point2D::norm2(pipe::point_list[e.p1], pipe::point_list[e.p2]);
                double norm2 = Point2D::norm2(displace_list[e.p1], displace_list[e.p2]);
                double delta = norm2 - norm1;

                if(delta < 0)
                    paint.line(e.pt1, e.pt2);
                else if(delta > 0)
                    paint.line(e.pt1, e.pt2);
                else
                {
                    paint.dot(e.pt1);
                    paint.dot(e.pt2);
                }
            }
        }

        // draw forces
        for(auto& f : pipe::force_list)
        {
            Point3D pt1 = displace_list[f.p];
            Point3D pt2 = pt1 + 0.005 * f.val;
            Point2D pt1r = rotate(pt1);
            Point2D pt2r = rotate(pt2);
            paint.line(pt1r, pt2r);
        }
    }

    sp::Vector conjagate_gradients(const sp::SymetryMatrix& K, const sp::Vector& F)
    {
        sp::Vector dp;
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
                break;

            double b = (r1 * r1) / (r0 * r0);

            p *= b;
            p += r1; // p := r1 + b * p

            r0 = r1;
        }
        return dp;
    }

    void run()
    {
        // init
        sp::size = convert::init(pipe::fix_list, point_size);

        // populate kmx, tmx
        convert::matrix(pipe::point_list, pipe::element_list, element_size);

        auto K = sp::SymetryMatrix(convert::kmx);

        // populate F
        auto F = convert::force(pipe::force_list, force_size);

        // solve K * dp = F with conjagate_gradients
        auto dp = conjagate_gradients(K, F);
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
        auto displace_elements = clip::make(displace_list, pipe::element_list, element_size, rotate);
        store_figure_pipe(displace_elements);
    }
}
