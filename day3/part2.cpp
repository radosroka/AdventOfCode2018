#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Rect {
    long id;
    long off_x, off_y;
    long x, y;
    bool overlaps;

    long getRealXStart() {
        return off_x;
    }
    
    long getRealXEnd() {
        return off_x + x;
    }

    long getRealYStart() {
        return off_y;
    }
    
    long getRealYEnd() {
        return off_y + y;
    }


};

void overlaps(Rect& r1, Rect& r2) {
    if (r1.getRealXStart() <= r2.getRealXEnd() && r1.getRealXEnd() >= r2.getRealXStart() &&
        r1.getRealYStart() <= r2.getRealYEnd() && r1.getRealYEnd() >= r2.getRealYStart()) {
        r1.overlaps = true;
        r2.overlaps = true;
    }
    return;
}

void markOverlapped(vector<Rect>& rects, Rect& r){

    for(auto& s: rects) {
        overlaps(r, s);
    }

}

long getNonOverlapped(vector<Rect>& v) {
    for(auto& r: v) {
        if(!r.overlaps) {
           //cout << r.id << endl;
           return r.id;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    vector<Rect> rects;

    string line;

    
    while (getline(cin, line)){
        Rect r;

        r.overlaps = false;

        // cout << line << endl;

        size_t end = 0;
        string s = line.substr(1);
        r.id = stol(s, &end, 10);

        s = s.substr(end+3);
        r.off_x = stol(s, &end, 10);

        s = s.substr(end+1);
        r.off_y = stol(s, &end, 10);

        s = s.substr(end+2);
        r.x = stol(s, &end, 10);
        
        s = s.substr(end+1);
        r.y = stol(s, &end, 10);

        // cout << id << " " << off_x << " " << off_y << " " << x << " " << y << endl << endl;
        markOverlapped(rects,r);
        rects.push_back(r);
        //printArray(map);
    }
    cout << "ID: " << getNonOverlapped(rects) << endl;
    return 0;
}
