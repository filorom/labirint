#include <iostream>
#include <fstream>
#include <stack>
#include <set>

using namespace std;

struct pozitie {
	int i;
	int j;

	pozitie(int _i, int _j) {
		i = _i;
		j = _j;
	}
};

int V[1001][1001];
stack<pozitie> da,ds;
int n, m, L[1001][1001],fi,fj;
ifstream fin("labirint.in");
ofstream fout("labirint.out");

bool inLabirint(int i, int j) {
	pozitie p(i, j);
	return (i>0 && i<=n && j>0 && j<=m && V[i][j]==0);
}
void pasesteLa(int i, int j);

void duteVino(int i, int j) {
	if (inLabirint(i, j) && L[i][j] == 0) {
		pasesteLa(i, j);
		V[i][j] = 0;
		da.pop();
	}
}

void pasesteLa(int i,int j) {
	cout << i << ' ' << j<<endl;
	pozitie p(i, j); 
	V[i][j] = -1;
	da.push(p);

	if (i == fi && j == fj) {
		if (da.size() < ds.size() || ds.empty()) {
			ds = da;
		}
		return;
	}
	duteVino(i, j + 1);
	duteVino(i, j - 1);
	duteVino(i + 1, j);
	duteVino(i - 1, j);
}

void print() {
	if (ds.empty()) {
		fout << 0;
		return;
	}
	fout << ds.size()<<endl;
	stack<pozitie> aux;
	while (!ds.empty()) {
		aux.push(ds.top());
		ds.pop();
	}
	while (!aux.empty()) {
		fout << aux.top().i<<" "<< aux.top().j <<endl;
		aux.pop();
	}	
}

int main()
{
	int si, sj;
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			fin >> L[i][j];
	fin >> si >> sj >> fi >> fj;
	pasesteLa(si, sj);
	print();
}
