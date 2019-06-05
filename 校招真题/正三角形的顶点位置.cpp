#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main_zhengsanjiaoxing()
{
	int n;
	cin >> n;
	double g3 = sqrt(3);
	for (int i = 0; i<n; i++)
	{
		double x1, y1, x2, y2, x0, y0, d, x, y, xx, yy, k, hx, hy;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x2 == x1)
		{
			d = abs(y2 - y1);
			y = min(y1, y2) + d / 2;
			yy = y;
			x = x1 + d*g3 / 2;
			xx = x1 - d*g3 / 2;
		}
		else if (y2 == y1)
		{
			d = abs(x2 - x1);
			x = min(x1, x2) + d / 2;
			xx = x;
			y = y1 + d*g3 / 2;
			yy = y1 - d*g3 / 2;
		}
		else
		{
			d = sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
			k = (x1 - x2) / (y2 - y1);
			x0 = (x1 + x2) / 2; y0 = (y1 + y2) / 2;
			hx = g3*d / 2 / sqrt(1 + pow(k, 2));
			hy = abs(k*hx);
			if (k<0)
			{
				xx = x0 - hx;
				yy = y0 + hy;
				x = x0 + hx;
				y = y0 - hy;
			}
			else
			{
				xx = x0 - hx;
				yy = y0 - hy;
				x = x0 + hx;
				y = y0 + hy;
			}
		}
		//cout << setiosflags(ios::fixed) << setprecision(2);
		//cout << xx << " " << yy << " " << x << " " << y << endl;
		printf("%.2f %.2f %.2f %.2f\n", xx, yy, x, y);
	}
	return 0;
}