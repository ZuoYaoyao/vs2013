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

//�������������������鼯�ķ�ʽһ��
//�ǵÿ���ɭ�ֵ����

void DP(int root)
{
	int dp0 = 0, dp1 = 0, i;
	//Ҷ��
	if(childCnt[root] == 0)
	{
		dp[root][1] = 1;
		dp[root][0] = 0;
		return;
	}
	//��Ҷ�ڵ�
	//N�Σ����нڵ�����ô���
	for (i = 0; i < n; i++)
	{
		//�������е�node�������root��Ҷ�ӣ��͵ݹ�
		if (pre[i] == root)
		{
			DP(i);
			//dp1 root�����
			//dp0 root��û��
			//root�൱��i��i�൱��Ҷ��j
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
		for (i = 0; i < n; i++)//����
		{
			scanf("%d:(%d)", &father, &m);
			childCnt[father] = m;//ÿ����Ҷ�Ӹ���
			if (root == -1)root = father;
			while (m--)
			{
				scanf("%d", &child);
				pre[child] = father;//���Ϊchild�ĺ��ӵ�ǰ��
				if (child == root)root = father;
			}
		}
		DP(root);
		printf("%d\n", min(dp[root][0], dp[root][1]));
	}

	return 0;
}