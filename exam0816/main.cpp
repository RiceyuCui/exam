#include <iostream>
using namespace std;

int max(int x, int y)
{
	int a = 0;
	a = x > y ? x : y;
	return a;
}

int max(int x, int y, int z)
{
	return max(max(x, y), z);
}

double max(double x, double y)
{
	double a = 0;
	a = x > y ? x : y;
	return a;
}

double max(double x, double y, double z)
{
	return max(max(x, y), z);
}

int main()
{
	int i = 0;
	double j = 0;
	int x, y, z;
	double m, l, n;

	cout <<"input x, y, z: "<<endl;
	cin >> x >> y >> z;
	
	i = max(x, y);
	cout << i << " is bigger." << endl;
	i = max(x, y, z);
	cout << i << " is biggest." << endl;

	cout <<"input m, l, n: " <<endl;
	cin >> m >> l >> n;

	j = max(m, l);
	cout << j << " is bigger." << endl;
	j = max(m, l, n);
	cout << j << " is biggest." << endl;

	return 0;


}