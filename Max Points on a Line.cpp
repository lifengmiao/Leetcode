/*
对于每一个点计算它和它之后每一点的斜率，如果斜率相同，证明在一条线上
以斜率为 key 建立map，存储斜率相同的点的数量，也即在一条线上点的数量
用overlap存 和i点（起点）重合的点数
用localMax存以 i 为起点的在一条线上的最大点数
*/

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
        if(points.size()<2) return points.size();
        int rst=0;
        for(int i=0; i<points.size(); i++) {
            map<pair<int,int>, int> mMap;
            int localMax = 0;
            int overlap = 0;
            for(int j=i+1; j<points.size(); j++) {
                if(points[j].x==points[i].x && points[j].y==points[i].y)
                    overlap++;
                else {
                    int a= points[j].x-points[i].x;
                    int b=points[j].y-points[i].y;
                    int gcd = GCD(a,b);
                    if (gcd!=0) {
                        a /= gcd;
                        b /= gcd;
                    }
                    mMap[make_pair(a,b)]++;
                    localMax = max(localMax, mMap[make_pair(a,b)]);
                }
            }
            rst = max(rst, localMax+overlap+1);
        }
        return rst;
    }
    
    int GCD(int a, int b) {
        if (b==0) return a;
        return GCD(b, a%b);
    }
};
