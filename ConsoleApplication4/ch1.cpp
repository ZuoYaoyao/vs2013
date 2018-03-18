#include<array>
#include<cstdio>
#include<stack>

using namespace std;


int main()
{

	array<double, 10> data={1,2};
	
	for (double& x : data)
	{
		printf("%lf\n", x);
	}
	getchar();

	return 0;
}