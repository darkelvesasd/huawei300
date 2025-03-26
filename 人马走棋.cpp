
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int>PII;
int flag = 0;
int m, n;
int hx[8] = { -2,-2,-1,-1,1,1,2,2 };
int hy[8] = { -1,1,-2,2,2,-2,1,-1 };
int sx[4] = { 0,0,-1,1 };
int sy[4] = { -1,1,0,0 };
void bfs(vector<vector<char>>& v, vector<vector<bool>>& vb, int x, int y, queue<PII>q)
{
	q.emplace(PII(x, y));
	int cnt = 0;
	queue<PII>q1;
	queue<bool>qb;
	queue<bool>qb1;
	qb.emplace(false);
	while (!q.empty() || !q1.empty())
	{
		int sz = q.size();
		while (!q1.empty())
		{
			PII t1 = q1.front();
			q.emplace(t1);
			q1.pop();
			bool qbt1 = qb1.front();
			qb.emplace(qbt1);
			qb1.pop();
		}
		for (int i = 0;i < sz;i++)
		{
			PII pt = q.front();
			vb[pt.first][pt.second] = true;
			bool qbt = qb.front();
			qb.pop();
			q.pop();
			if (pt.first == m - 1 && pt.second == n - 1)
			{
				cout << cnt;
				flag = 1;
				return;
			}
			if (v[pt.first][pt.second] == '.')
			{
				if (qbt == false)
				{
					for (int i = 0; i < 4; i++)
					{
						int xt = sx[i] + pt.first;
						int yt = sy[i] + pt.second;
						if (xt >= 0 && xt < m && yt >= 0 && yt < n && vb[xt][yt] == false && (v[xt][yt] != 'X'))
						{
							q.emplace(PII(xt, yt));
							qb.emplace(false);
						}
					}
				}
				else
				{
						for (int i = 0; i < 8; i++)
						{
							int xt = hx[i] + pt.first;
							int yt = hy[i] + pt.second;
							if (xt >= 0 && xt < m && yt >= 0 && yt < n && vb[xt][yt] == false && (v[xt][yt] != 'X'))
							{
								q.emplace(PII(xt, yt));
								qb.emplace(true);
							}
						}
				}
			}
			else if (v[pt.first][pt.second] == 'S')
			{
				if (qbt == false)
				{
					for (int i = 0; i < 4; i++)
					{
						int xt = sx[i] + pt.first;
						int yt = sy[i] + pt.second;
						if (xt >= 0 && xt < m && yt >= 0 && yt < n && vb[xt][yt] == false && (v[xt][yt] != 'X'))
						{
							q.emplace(PII(xt, yt));
							qb.emplace(false);
						}
					}
					for (int i = 0; i < 8; i++)
					{
						int xt = hx[i] + pt.first;
						int yt = hy[i] + pt.second;
						if (xt >= 0 && xt < m && yt >= 0 && yt < n && vb[xt][yt] == false && (v[xt][yt] != 'X'))
						{
							q1.emplace(PII(xt, yt));
							qb1.emplace(true);
						}
					}
				}
				else
				{
					for (int i = 0; i < 4; i++)
					{
						int xt = sx[i] + pt.first;
						int yt = sy[i] + pt.second;
						if (xt >= 0 && xt < m && yt >= 0 && yt < n && vb[xt][yt] == false && (v[xt][yt] != 'X'))
						{
							q1.emplace(PII(xt, yt));
							qb1.emplace(true);
						}
					}
					for (int i = 0; i < 8; i++)
					{
						int xt = hx[i] + pt.first;
						int yt = hy[i] + pt.second;
						if (xt >= 0 && xt < m && yt >= 0 && yt < n && vb[xt][yt] == false && (v[xt][yt] != 'X'))
						{
							q.emplace(PII(xt, yt));
							qb.emplace(false);
						}
					}
				}
			}
		}
		cnt++;
	}
}
int main()
{
	cin >> m >> n;
	vector<vector<char>>v(m, vector<char>(n));
	queue<PII>q;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			v[i][j] = c;
		}
	}
	vector<vector<bool>>vb(m, vector<bool>(n));
	bfs(v, vb, 0, 0, q);
	if (!flag)
	{
		cout << 0;
	}
	return 0;
}/*9 9
.........
.....XXX.
.....X.X.
.....X.X.
.....X.XS
XXXXXXX.X
.........
.........
.........
 */
/*5 3
.....
.....
.....
SSSSS
SSSSS
SSSSS
*/
