#include <bits/stdc++.h>
using namespace std;
int n, m;
int temp_x=0, temp_y=0;
int x, y;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        temp_x += x;
        temp_y += y;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x += temp_x;
    	y += temp_y;
    	cout << x <<" "<< y << "\n"; 
    }
    cout << endl;
    return 0;
}
