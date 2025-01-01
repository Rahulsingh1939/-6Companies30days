class Solution
{
public:
    bool dist(int r, int cx, int cy, int x1, int y1, int x2, int y2)
    {
        int dx = x2 - x1, dy = y2 - y1;
        int dis = dx * dx + dy * dy;
        if (dis == 0)
        {
            return (cx - x1) * (cx - x1) + (cy - y1) * (cy - y1) <= r * r;
        }
        double t = ((cx - x1) * dx + (cy - y1) * dy) / (double)dis;
        t = std::max(0.0, std::min(1.0, t));
        double cX = x1 + t * dx;
        double cY = y1 + t * dy;
        return (cx - cX) * (cx - cX) + (cy - cY) * (cy - cY) <= r * r;
    }
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2)
    {
        if (x1 > x2)
            std::swap(x1, x2);
        if (y1 > y2)
            std::swap(y1, y2);
        if (dist(r, x, y, x1, y1, x1, y2) || dist(r, x, y, x2, y1, x2, y2) ||
            dist(r, x, y, x1, y1, x2, y1) || dist(r, x, y, x1, y2, x2, y2))
            return true;
        if ((x - x1) * (x - x1) + (y - y1) * (y - y1) <= r * r ||
            (x - x2) * (x - x2) + (y - y1) * (y - y1) <= r * r ||
            (x - x1) * (x - x1) + (y - y2) * (y - y2) <= r * r ||
            (x - x2) * (x - x2) + (y - y2) * (y - y2) <= r * r)
            return true;
        if (x - r >= x1 && x + r <= x2 && y - r >= y1 && y + r <= y2)
            return true;

        return false;
    }
};