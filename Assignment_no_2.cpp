#include <bits/stdc++.h>
using namespace std;
#define N 3

class Node
{
public:
	Node* parent;
	int mat[N][N];
	int x, y;
	int cost = 0;
	int level = 0;
};

void printMatrix(int mat[N][N])
{
	cout<<endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
}

Node* newNode(int mat[N][N], int x, int y, int newX, int newY, int level, Node* parent)
{
	Node* node = new Node;
	node->parent = parent;
	memcpy(node->mat, mat, sizeof node->mat);
	swap(node->mat[x][y], node->mat[newX][newY]);
	node->cost = INT_MAX;
	node->level = level;
	node->x = newX;
	node->y = newY;

	return node;
}

int calculateCost(int initial[N][N], int final[N][N])
{
	int count = 0;
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		if (initial[i][j] && initial[i][j] != final[i][j])
		count++;
	return count;
}

int isSafe(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N);
}

// Comparison object to be used to order the heap
struct comp
{
	bool operator()(const Node* lhs, const Node* rhs) const
	{
		return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
	}
};

// bottom, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

void solve(int initial[N][N], int x, int y, int final[N][N])
{
	priority_queue<Node*, vector<Node*>, comp> pq;

	Node* root = newNode(initial, x, y, x, y, 0, NULL);
	root->cost = calculateCost(initial, final);

	pq.push(root);

	while (!pq.empty())
	{
		Node* min = pq.top();
		pq.pop();

		printMatrix(min->mat);

		if (min->cost == 0)
		{
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			if (isSafe(min->x + row[i], min->y + col[i]))
			{
				Node* child = newNode(min->mat, min->x,min->y, min->x + row[i], min->y + col[i], min->level + 1, min);
				child->cost = calculateCost(child->mat, final);
				pq.push(child);
			}
		}
	}
}

int main()
{
	cout<<"\nEnter Initial Matrix"<<endl;

	int initial[N][N];
	int x=0, y=0;

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin>>initial[i][j];
			if(initial[i][j] == 0)
			{
				x = i;
				y = j;
			}
		}
	}

	cout<<"\nEnter Final Matrix"<<endl;
	int final[N][N];
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin>>final[i][j];
		}
	}

	solve(initial, x, y, final);

	return 0;
}
