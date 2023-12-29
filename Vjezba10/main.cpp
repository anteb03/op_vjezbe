#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

void rijeci(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Nemoguce otvaranje datoteke." << endl;
        return;
    }

    vector<string> words;
    copy(istream_iterator<string>(file), istream_iterator<string>(), back_inserter(words));

    string substring = "gr";
    words.erase(remove_if(words.begin(), words.end(), [&substring](const string& s) {
        return s.find(substring) != string::npos;
        }), words.end());

    string searchWord = "banana"; 
    vector<size_t> positions;
    auto it = find(words.begin(), words.end(), searchWord);
    while (it != words.end()) {
        positions.push_back(distance(words.begin(), it));
        it = find(++it, words.end(), searchWord);
    }

    transform(words.begin(), words.end(), words.begin(), [](string& s) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
        });

    copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
    cout << endl; 
    copy(positions.begin(), positions.end(), ostream_iterator<size_t>(cout, " "));
    cout << endl; 
    cout << endl;
}

struct Point {
    double x, y;

    Point(double xVal, double yVal) : x(xVal), y(yVal) {}
};

double distanca(const Point& p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

void tocke(const string& filename){
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Nemoguce otvorit datoteku." << endl; 
        return; 
    }
    vector<Point> points;
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        double x, y;
        if (iss >> x >> y) {
            points.emplace_back(x, y);
        }
    }
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return distanca(a) < distanca(b);
        });

    int radius = 5; 
    size_t countInside = count_if(points.begin(), points.end(), [radius](const Point& p) {
        return distanca(p) < radius;
        });

    double targetDistance = 5.0; 
    Point replacementPoint(10.0, 10.0); 
    replace_if(points.begin(), points.end(), [targetDistance](const Point& p) {
        return distanca(p) == targetDistance;
        }, replacementPoint);

    reverse(points.begin(), points.end());
    for (const auto& point : points) {
        cout << "(" << point.x << ", " << point.y << ")" << endl;
    }

    cout << "Unutar radijusa " << radius << ": " << countInside << endl;
}

int main() {
    rijeci("words.txt");
    tocke("points.txt");
    return 0;
}