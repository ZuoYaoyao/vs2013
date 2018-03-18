//poj 1463 strategic game

#include<cmath>
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int N = 1501;
int pre[N], childCnt[N], root, n;
int dp[N][2];

//用数组来建树，跟并查集的方式一样
//记得考虑森林的情况

void DP(int root)
{
	int dp0 = 0, dp1 = 0, i;
	//叶子
	if(childCnt[root] == 0)
	{
		dp[root][1] = 1;
		dp[root][0] = 0;
		return;
	}
	//非叶节点
	//N次，所有节点数那么多次
	for (i = 0; i < n; i++)
	{
		//遍历所有的node，如果是root的叶子，就递归
		if (pre[i] == root)
		{
			DP(i);
			//dp1 root点放了
			//dp0 root点没放
			//root相当于i，i相当于叶子j
			dp1 += min(dp[i][1], dp[i][0]);
			dp0 += dp[i][1];
		}
	}
	dp[root][1] = dp1 + 1;
	dp[root][0] = dp0;
}

int main()
{
	int i, father, m, child;
	while (!scanf("%d", &n))
	{
		memset(dp, 0, sizeof(dp));
		memset(pre, -1, sizeof(dp));
		root = -1;
		memset(childCnt, -1, sizeof(childCnt));
		for (i = 0; i < n; i++)//建树
		{
			scanf("%d:(%d)", &father, &m);
			childCnt[father] = m;//每个根叶子个数
			if (root == -1)root = father;
			while (m--)
			{
				scanf("%d", &child);
				pre[child] = father;//编号为child的孩子的前驱
				if (child == root)root = father;
			}
		}
		DP(root);
		printf("%d\n", min(dp[root][0], dp[root][1]));
	}

	return 0;
}