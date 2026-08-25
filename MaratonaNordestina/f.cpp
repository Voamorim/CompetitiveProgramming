#include <bits/stdc++.h>
using namespace std;

#define MAXN 1012

int n, h;
vector<vector<double>> graph (MAXN, vector<double> (MAXN, 10000000));
vector<tuple<int, int, int>> guarda_sois;

double dijkstra(int src = 0){
	vector<double> dist (MAXN, INT_MAX);
	vector<bool> vis (MAXN, false);

	priority_queue<tuple<double, int>> pq;

	pq.push(make_tuple(0, src));

	while(!pq.empty()){
		auto [d, v] = pq.top();
		d = -d;
		pq.pop();

		if(vis[v]) continue;

		vis[v] = true;

		//cout << "visita o guarda sol " << v << endl;

		for(int i = 1; i <= n + 1; ++i){
			if(d + graph[v][i] < dist[i]){
				//cout << "a distancia de " << v << " ate " << i << " e mais curta que a atual" << endl;

				dist[i] = d + graph[v][i];
				pq.push(make_tuple(-dist[i], i));
			}
		}
	}

	return dist[n+1];
}

int main(){
	cin >> n >> h;

	for(int i = 0; i < n; ++i){
		int x, y, r; cin >> x >> y >> r;
		guarda_sois.push_back(make_tuple(x, y, r));
	}	

	graph[0][n+1] = h;

	for(int i = 0; i < n; ++i){	
		auto [x, y, r] = guarda_sois[i];

		graph[0][i + 1] = y - r >= 0 ? y - r : 0;
		graph[i+1][n+1] = h - (y + r) >= 0 ? h - (y+r) : 0;

		for(int j = 0; j < n; ++j){
			if(i == j) continue;

			auto [xj, yj, rj] = guarda_sois[j];

			double dist = sqrt((double)pow((double) x - xj, 2) + pow((double) y - yj, 2));

			dist -= rj;
			dist -= r;

			if(dist < 0) dist = 0;


			graph[i+1][j+1] = dist;
		}
	}

	cout << fixed << setprecision(10) << dijkstra() << endl;
	return 0;
}
