#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <algorithm>

struct Waypoint {
    std::string id;
    std::string name;
    float lat;
    float lon;
};

struct Route {
    std::string id;
    std::string name;
    std::string specs;
    std::string behaviorFormula;
    std::vector<Waypoint*> points;
};

struct Train {
    std::string id;
    std::string name;
    float speed;
    Route* assignedRoute;
    float segmentProgress;
    int currentSegment;
    float routeProgress;
};
/*
class FormulaParser {
private:
    std::string src;
    size_t idx;
    float p_val;

    char peek() {
        return idx < src.size() ? src[idx] : 0;
    }

    char get() {
        return idx < src.size() ? src[idx++] : 0;
    }

    void skipSpace() {
        while (peek() == ' ') get();
    }

    float parseAtom() {
        skipSpace();
        if (peek() == 'p') {
            get();
            return p_val;
        }
        if (peek() == 's' || peek() == 'c') {
            std::string op = "";
            while (std::isalpha(peek())) {
                op += get();
            }
            skipSpace();
            if (peek() == '(') {
                get();
                float val = parseExpr();
                if (peek() == ')') get();
                if (op == "sin") return std::sin(val);
                if (op == "cos") return std::cos(val);
            }
        }
        if (peek() == '(') {
            get();
            float val = parseExpr();
            if (peek() == ')') get();
            return val;
        }
        std::string num = "";
        while (std::isdigit(peek()) || peek() == '.') {
            num += get();
        }
        return num.empty() ? 0.0f : std::stof(num);
    }

    float parseTerm() {
        float val = parseAtom();
        while (true) {
            skipSpace();
            char c = peek();
            if (c == '*') {
                get();
                val *= parseAtom();
            } else if (c == '/') {
                get();
                float denom = parseAtom();
                val /= (denom != 0.0f ? denom : 1.0f);
            } else {
                break;
            }
        }
        return val;
    }

public:
    FormulaParser(std::string s, float p) : src(s), idx(0), p_val(p) {}

    float parseExpr() {
        float val = parseTerm();
        while (true) {
            skipSpace();
            char c = peek();
            if (c == '+') {
                get();
                val += parseTerm();
            } else if (c == '-') {
                get();
                val -= parseTerm();
            } else {
                break;
            }
        }
        return val;
    }
};

std::vector<Waypoint*> waypointsList;
std::vector<Route*> routesList;
std::vector<Train*> trainsList;

void updateTrainsState() {
    for (auto* t : trainsList) {
        if (t->assignedRoute == nullptr || t->assignedRoute->points.empty()) continue;

        t->segmentProgress += 5.0f;
        if (t->segmentProgress > 100.0f) {
            t->segmentProgress = 0.0f;
            t->currentSegment++;
            if (t->currentSegment >= t->assignedRoute->points.size() - 1) {
                t->currentSegment = 0;
            }
        }

        FormulaParser parser(t->assignedRoute->behaviorFormula, t->segmentProgress);
        t->speed = parser.parseExpr();

        int totalSegments = t->assignedRoute->points.size() - 1;
        if (totalSegments > 0) {
            t->routeProgress = ((float)t->currentSegment / totalSegments * 100.0f) + (t->segmentProgress / totalSegments);
        } else {
            t->routeProgress = 100.0f;
        }
    }
}

int main() {
    Waypoint* wp1 = new Waypoint{"WP1", "Station A", 55.75f, 37.61f};
    Waypoint* wp2 = new Waypoint{"WP2", "Station B", 59.93f, 30.36f};
    Waypoint* wp3 = new Waypoint{"WP3", "Station C", 56.83f, 60.60f};
    waypointsList.push_back(wp1);
    waypointsList.push_back(wp2);
    waypointsList.push_back(wp3);

    Route* r1 = new Route();
    r1->id = "R1";
    r1->name = "Express Route";
    r1->specs = "HighSpeed";
    r1->behaviorFormula = "160.0 * sin(p * 0.0314159)";
    r1->points.push_back(wp1);
    r1->points.push_back(wp2);
    r1->points.push_back(wp3);
    routesList.push_back(r1);

    Train* t1 = new Train{"T1", "Sapsan", "EVS2", 0.0f, r1, 0.0f, 0, 0.0f};
    trainsList.push_back(t1);

    std::cout << "Simulation start" << std::endl;
    std::cout << "Formula used: " << r1->behaviorFormula << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    for (int step = 0; step < 25; ++step) {
        updateTrainsState();
        std::cout << "Step: " << step 
                  << " | Seg: " << t1->currentSegment 
                  << " | SegProgress: " << t1->segmentProgress << "%"
                  << " | CalcSpeed: " << t1->speed << " km/h"
                  << " | TotalProgress: " << t1->routeProgress << "%" 
                  << std::endl;
    }

    delete t1;
    delete r1;
    delete wp1;
    delete wp2;
    delete wp3;

    return 0;
}*/


int main(){return 0;}