
class Paint
{
public:
    Paint(const std::string& filename)
    {
#ifdef EMSCRIPTEN
        draw_begin();
#else
        stream.open(filename);
#endif
    }
    ~Paint()
    {
#ifdef EMSCRIPTEN
        draw_end();
#else
        stream.close();
#endif
    }
    void line(const Point2D& p1, const Point2D& p2)
    {
#ifdef EMSCRIPTEN
        auto scale = 50.0;
        auto trans = Point2D(9.0, 2.0);
        auto _p1 = scale * (trans + p1);
        auto _p2 = scale * (trans + p2);
        draw_line(_p1.x, _p1.y, _p2.x, _p2.y);
#else
        stream << "line " << p1.x << ":" << p1.y << " " << p2.x << ":" << p2.y << std::endl;
#endif
    }
    void dot(const Point2D& p)
    {
#ifdef EMSCRIPTEN
        //draw_dot();
#else
        stream << "dot " << p.x << " " << p.y << std::endl;
#endif
    }
private:
#ifdef EMSCRIPTEN
    void draw_begin() {
        EM_ASM(draw_begin());
    }

    void draw_end() {
        EM_ASM(draw_end());
    }

    void draw_line(int x1, int y1, int x2, int y2) {
        EM_ASM(draw_line($0, $1, $2, $3), x1, y1, x2, y2);
    }
#else
    std::ofstream stream;
#endif
};
