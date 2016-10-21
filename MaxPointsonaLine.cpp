/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
    	if (points.size() < 2) return points.size();
        unordered_map<int, unordered_map<int, int>> mymap;
        int res = 1;
        for (int i = 0; i < points.size(); ++i) {
        	mymap.clear();
        	int same = 0, vertical = 0;
        	for (int j = i+1; j < points.size(); ++j) {
        		int x = points[i].x - points[j].x;
        		int y = points[i].y - points[j].y;
        		if (x == 0 && y == 0) ++same;
        		else if (x == 0) ++vertical;
        		else {
        			int r = gcd(x, y);
        			x = x / r;
        			y = y / r;
        			++mymap[x][y];
        		}
        	}
        	res = max(res, vertical+same+1);
        	for (auto dic = mymap.begin(); dic != mymap.end(); ++dic) {
        		for (auto d = (dic->second).begin(); d != (dic->second).end(); ++d) {
        			res = max(res, d->second + 1 + same);
        		}
        	}
        }
        return res;
    }

    int gcd(int a, int b) {
    	if (b == 0) return a;
    	return gcd(b, a%b);
    }
};