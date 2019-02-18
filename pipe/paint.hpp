
class Paint
{
public:
    Paint(const std::string& filename)
    {
        stream.open(filename);
    }
    ~Paint()
    {
        stream.close();
    }
    void line(const Point2D& p1, const Point2D& p2)
    {
        stream << "line " << p1.x << ":" << p1.y << " " << p2.x << ":" << p2.y;
    }
    void dot(const Point2D& p)
    {
        stream << "dot " << p.x << " " << p.y;
    }
private:
    std::ofstream stream;
};

