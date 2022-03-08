#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef struct point{
    long double x;
    long double y;
}point;

long double distance(point A, point B){
    return (A.x-B.x) * (A.x-B.x) + (A.y-B.y) * (A.y-B.y);
}

int main(void){
    cout << fixed << setprecision(2);
    point points[501];
    point origin;
    int n;
    origin.x = 0;
    origin.y = 0;

    cin >> n;
    long double total = 0;
    int tmp;
    for (int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
        if (distance(points[i],origin) > total){
            total = distance(points[i],origin);
            tmp = i;
        }
    }

    point tmp2 = points[tmp];
    points[tmp] = points[--n];
    points[n] = tmp2;
    cout << (total = sqrt(total)) << endl;

    while(n){
        long double length = 0;
        for(int i = 0; i < n; i++){
            if (distance(points[i],points[n]) > length){
                length = distance(points[i],points[n]);
                tmp = i;
            }
        }
        tmp2 = points[tmp];
        points[tmp] = points[--n];
        points[n] = tmp2;
        cout << (total += sqrt(length)) << endl;
    }
    return 0;
}