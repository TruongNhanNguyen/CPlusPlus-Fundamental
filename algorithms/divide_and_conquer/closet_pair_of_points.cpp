#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

const double INF = 1e9;

struct Point
{
    double x, y;
    bool operator<(const Point &p) const
    {
        return x < p.x;
    }
};

double dist(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double closest_pair(Point *p, int n)
{
    if (n <= 1)
        return INF;
    int m = n / 2;
    double x = p[m].x;
    double d = min(closest_pair(p, m), closest_pair(p + m, n - m));
    inplace_merge(p, p + m, p + n, [](Point a, Point b)
                  { return a.y < b.y; });
    vector<Point> b;
    for (int i = 0; i < n; i++)
        if (abs(p[i].x - x) < d)
            b.push_back(p[i]);
    for (int i = 0; i < b.size(); i++)
        for (int j = i + 1; j < b.size() && b[j].y - b[i].y < d; j++)
            d = min(d, dist(b[i], b[j]));
    return d;
}

void test_closet_pair()
{
    Point p1[] = {{1, 1}, {3, 3}, {4, 5}, {6, 7}, {8, 9}};
    int n = sizeof(p1) / sizeof(p1[0]);
    cout << "The closest pair has distance: " << closest_pair(p1, n) << endl;
    Point p2[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    n = sizeof(p2) / sizeof(p2[0]);
    cout << "The closest pair has distance: " << closest_pair(p2, n) << endl;
}

int main()
{
    test_closet_pair();
    return 0;
}
