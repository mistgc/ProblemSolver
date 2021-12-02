#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>


using namespace std;
/**
 *	规定方向优先级为逆时针
 *	
 *	0 :空地(可以通过)
 *	1 :墙(不能通过)
 *	@param direction: 方向参数
 *				0	：上
 *				1	: 左
 *				2	: 下
 *				3	: 右
 */
struct Point{
	int x, y;
};

vector<Point> path;
int s_count = 0;

bool exist(vector<Point> v, Point p){
	for(int i = 0; i < v.size(); i++){
		if(v[i].x == p.x && v[i].y == p.y){
			return true;
		}
	}
	return false;
}

bool dfs(int **map, int x, int y){

	s_count = s_count + 1;
	Point p;
	p.x = x;
	p.y = y;
	if(exist(path, p)){
		s_count--;
		return false;
	}

	path.push_back(p);
	if(x == 4 && y == 4){
		return true;
	}
	if(x < 0 || y < 0 || x >= 5 || y >= 5){
		path.pop_back();
		s_count--;
		return false;
	}

	if(map[x][y] == 1){
		path.pop_back();					//遇到墙壁
		s_count--;
		return false;
	}	

	
	dfs(map, x - 1, y);
	dfs(map, x, y - 1);
	dfs(map, x + 1, y);
	dfs(map, x, y + 1);

	return false;
}
int main(){
	int m, n;
	char c;
	cin >> n >> m ;
	//cout << '\n' << n << ' ' << m << endl;
	auto map = (int **)malloc(sizeof(int*) * n);
	for(int i = 0; i < n; i++){
		map[i] = (int *)malloc(sizeof(int) * m);
	}
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			if(s[j] == '#'){
				map[i][j] = 1;
			}else{
				map[i][j] = 0;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}

	dfs(map, 0, 0);

	cout << s_count;

	return 0;
}
