#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Line {
    public:
        pair<int, int> p1;
        pair<int, int> p2;
        string orientation;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int level, width, x; cin >> level >> width >> x;
    vector<Line> lines;
    
    Line baseLine;
    baseLine.p1 = {0, 1};
    baseLine.p2 = {width, 1};
    baseLine.orientation = "top";
    lines.push_back(baseLine);

    for (int i = 0; i < level; i++) {
        vector<Line> newLines;

        for (auto line : lines) {
            Line line1, line2, line3, line4, line5;
            int third;

            if (line.orientation == "top") {
                third = (line.p2.first - line.p1.first) / 3;

                line1.p1 = line.p1;
                line1.p2 = line.p1;
                line1.p2.first += third;
                line1.orientation = "top";

                line2.p1 = line1.p2;
                line2.p2 = line1.p2;
                line2.p2.second += third;
                line2.orientation = "left";

                line3.p1 = line2.p2;
                line3.p2 = line2.p2;
                line3.p2.first += third;
                line3.orientation = "top";

                line4.p2 = line3.p2;
                line4.p1 = line3.p2;
                line4.p1.second -= third;
                line4.orientation = "right";

                line5.p1 = line4.p1;
                line5.p2 = line4.p1;
                line5.p2.first += third;
                line5.orientation = "top";
            } else if (line.orientation == "bottom") {
                third = (line.p2.first - line.p1.first) / 3; 

                line1.p1 = line.p1;
                line1.p2 = line.p1;
                line1.p2.first += third;
                line1.orientation = "bottom";

                line2.p2 = line1.p2;
                line2.p1 = line1.p2;
                line2.p1.second -= third;
                line2.orientation = "left";

                line3.p1 = line2.p1;
                line3.p2 = line2.p1;
                line3.p2.first += third;
                line3.orientation = "bottom";

                line4.p1 = line3.p2;
                line4.p2 = line3.p2;
                line4.p2.second += third;
                line4.orientation = "right";

                line5.p1 = line4.p2;
                line5.p2 = line4.p2;
                line5.p2.first += third;
                line5.orientation = "bottom";

            } else if (line.orientation == "left") {
                third = (line.p2.second - line.p1.second) / 3;

                line1.p1 = line.p1;
                line1.p2 = line.p1;
                line1.p2.second += third;
                line1.orientation = "left";

                line2.p2 = line1.p2;
                line2.p1 = line1.p2;
                line2.p1.first -= third;
                line2.orientation = "bottom";

                line3.p1 = line2.p1;
                line3.p2 = line2.p1;
                line3.p2.second += third;
                line3.orientation = "left";

                line4.p1 = line3.p2;
                line4.p2 = line3.p2;
                line4.p2.first += third;
                line4.orientation = "top";

                line5.p1 = line4.p2;
                line5.p2 = line4.p2;
                line5.p2.second += third;
                line5.orientation = "left";
            } else if (line.orientation == "right") {
                third = (line.p2.second - line.p1.second) / 3;

                line1.p1 = line.p1;
                line1.p2 = line.p1;
                line1.p2.second += third;
                line1.orientation = "right";

                line2.p1 = line1.p2;
                line2.p2 = line1.p2;
                line2.p2.first += third;
                line2.orientation = "bottom";

                line3.p1 = line2.p2;
                line3.p2 = line2.p2;
                line3.p2.second += third;
                line3.orientation = "right";

                line4.p2 = line3.p2;
                line4.p1 = line3.p2;
                line4.p1.first -= third;
                line4.orientation = "top";

                line5.p1 = line4.p1;
                line5.p2 = line4.p1;
                line5.p2.second += third;
                line5.orientation = "right";
            }

            newLines.push_back(line1);
            newLines.push_back(line2);
            newLines.push_back(line3);
            newLines.push_back(line4);
            newLines.push_back(line5);
        }

        lines = newLines;
    }

    set<int> intersections;
    for (auto line : lines) {
        if (line.orientation == "top" || line.orientation == "bottom") {
            if (x >= line.p1.first && x <= line.p2.first) {
                intersections.insert(line.p1.second);
            }
        } else if (line.orientation == "left" || line.orientation == "right") {
            if (x == line.p1.first) {
                for (int i = line.p1.second; i <= line.p2.second; i++) {
                    intersections.insert(i);
                }
            }
        }
    }
    for (auto it = intersections.begin(); it != intersections.end(); it++) {
        cout << *it << " ";
    }
}