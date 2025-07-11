#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
struct point {
	int x;
	int y;

	void read()
	{
		std::cin >> x >> y;
	}

	void print()
	{
		std::cout << "(" << x << "," << y << ")";
	}

	double distance(point a)
	{
		std::cout.precision(12);
		return sqrt(abs(a.x - x) * abs(a.x - x) + abs(a.y - y) * abs(a.y - y));
	}
};
void solution(point* array, int len)
{

	double* solutions = new double[len * (len - 1) / 2];
	int count = 0;
	double temp;
	bool ind = true;
	for (int i = 0; i < len; ++i)
	{
		for (int j = i+1; j < len && j != i; ++j)
		{
			temp = array[i].distance(array[j]);
			for (int k = 0; k < count; ++k)
			{
				if (temp == solutions[k])
				{
					ind = false;
					break;
				}
			}
			if (ind == true)
			{
				solutions[count] = temp;
				count++;
			}
			ind = true;
		}
	}
	std::cout << std::fixed << std::setprecision(10);
	std::sort(solutions, solutions + count);
	std::cout << count << "\n";
	for (int i = 0; i < count; ++i)
	{
		std::cout << solutions[i] << "\n";
	}
	delete[] solutions;
}
int main(int argc, char* argv[])
{
	int n;
	std::cin >> n;
	point* points = new point[n];
	for (int i = 0; i < n; ++i)
	{
		points[i].read();
	}
	solution(points, n);
	delete[] points;
	return 0;
}
