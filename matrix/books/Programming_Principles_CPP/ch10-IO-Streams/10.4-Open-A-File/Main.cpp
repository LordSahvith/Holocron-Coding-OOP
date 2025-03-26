#include "../../00_std_lib_facilities.h"

int main()
{
    cout << "Please enter input file: ";
    string inName;
    cin >> inName;
    ifstream inStream{inName};
    if (!inStream)
    {
        error("can't open input file ", inName);
    }

    vector<Point> points;
    for (int i = 0; i < 10; i++)
    {
        points.push_back(Point{i, i + 1});
    }

    cout << "Please enter output file: ";
    string outName;
    cin >> outName;
    ofstream outStream{outName};
    if (!outStream)
    {
        error("can't open output file ", outName);
    }

    for (Point point : points)
    {
        outStream << '(' << point.x << ',' << point.y << ')' << endl;
    }
}