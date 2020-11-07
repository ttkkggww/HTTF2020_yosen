#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int Graph[20][20];
pair<int,int> place_of[100];
string ans;
pair<int,int> my_place;
stack<int> Box;

int Down(){
	if(my_place.first==19)return 1;
	my_place.first++;
	ans.push_back('D');
	return 0;
}
int Up(){
	if(my_place.first==0)return 1;
	my_place.first--;
	ans.push_back('U');
	return 0;
}
int Right(){
	if(my_place.second==19)return 1;
	my_place.second++;
	ans.push_back('R');
	return 0;
}
int Left(){
	if(my_place.second==0)return 0;
	my_place.second--;
	ans.push_back('L');
	return 0;
}
int Exist(pair<int,int> p){
	return (Graph[p.first][p.second]!=-1);
}
int Input(){
	if(Graph[my_place.first][my_place.second]==-1)return 1;
	Box.push(Graph[my_place.first][my_place.second]);
	Graph[my_place.first][my_place.second]=-1;
	place_of[Box.top()] = make_pair(-1,-1);
	ans.push_back('I');
	return 0;
}
int Output(){
	if(Graph[my_place.first][my_place.second]!=-1)return 1;
	int out = Box.top();Box.pop();
	int x = my_place.first;int y = my_place.second;
	Graph[x][y] = out;
	place_of[out] = make_pair(x,y);
	ans.push_back('I');
	return 0;
}

int main()
{
	for(int i = 0;i<20;i++)for(int j = 0;j<20;j++)Graph[i][j] = -1;
	for(int i = 0;i <100;i++){
		int x,y;
		cin >> x >> y;
		Graph[x][y]=i;
		place_of[i] = make_pair(x,y);
	}
	
}
