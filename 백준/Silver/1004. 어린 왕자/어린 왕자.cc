#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int n;
        cin >> n;
        
        int count = 0;
        
        while (n--) 
        {
            int cx, cy, r;
            cin >> cx >> cy >> r;
            
            int dist1 = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy);
            int dist2 = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy);
            int rr = r * r;
            
            bool si = (dist1 < rr);
            bool ei = (dist2 < rr);
            
            if (si != ei)
                count++;
        }
        cout << count << '\n';
    }
    
    return 0;
}