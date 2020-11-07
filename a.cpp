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
int Exist(int x,int y){
	return (Graph[x][y]!=-1);
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
	ans.push_back('O');
	return 0;
}
int Exist_to(string to){
	if(to=="Down"){
		for(int i = my_place.first+1;i<20;i++){
			if(Exist(i,my_place.second))return 1;
		}
		return 0;
	}
	if(to=="Up"){
		for(int i = my_place.first-1;i>=0;i--){
			if(Exist(i,my_place.second))return 1;
		}
		return 0;
	}
	if(to=="Right"){
		for(int i = my_place.second+1;i<20;i++){
			if(Exist(my_place.first,i))return 1;
		}
	}
	if(to=="Left"){
		for(int i = my_place.second -1;i>=0;i--){
			if(Exist(my_place.first,i))return 1;
		}
	}
	return 0;
}
//ゼロのときは存在しない。
int Exist_to_size(string to){
	int res ;
	if(to=="Down"){
		res = my_place.first;
		for(int i = my_place.first+1;i<20;i++){
			if(Exist(i,my_place.second))res = i;
		}
		return res-my_place.first;
	}
	if(to=="Up"){
		res = my_place.first;
		for(int i = my_place.first-1;i>=0;i--){
			if(Exist(i,my_place.second))res = i;
		}
		return my_place.first - res;
	}
	if(to=="Right"){
		res = my_place.second;
		for(int i = my_place.second+1;i<20;i++){
			if(Exist(my_place.first,i))res = i;;
		}
		return res - my_place.second;
	}
	if(to=="Left"){
		res = my_place.second;
		for(int i = my_place.second -1;i>=0;i--){
			if(Exist(my_place.first,i))res = i;
		}
		return my_place.second-res;

	}
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
	for(int i = 0;i<10;i++){
		Input();
		int to[2];
		to[0] = Exist_to_size("Up");
		to[1] = Exist_to_size("Down");
		int flg = to[0]>to[1];//flg==1のとき、下から回収する
		//cout<<flg<<endl;

		for(int i = 0;i<to[0+flg];i++){if(flg==0)Up();else Down();Input();}
		for(int i = 0;i<to[0+flg];i++){if(flg==1)Up();else Down();}
		for(int i = 0;i<to[1-flg];i++){if(flg==1)Up();else Down();Input();}
		Input();
		Right();
	}
	while(my_place.first){
		Input();
		Up();
	}
	
	Input();
	for(int i=0;i<10;i++){
		for(int j = 0;j<9;j++){
			Input();
			if(i%2)Left();
			else Right();
		}
		Input();
		Down();
	}

	for(int i=0;i<10;i++){
		for(int j = 0;j<9;j++){
			Output();
			if(i%2)Left();
			else Right();
		}
		Output();
		Down();
	}

	for(int aim = 0;aim<100;aim++){
		while(place_of[aim]!=my_place){
			if(place_of[aim].first>my_place.first)Down();
			if(place_of[aim].first<my_place.first)Up();
			if(place_of[aim].second>my_place.second)Right();
			if(place_of[aim].second<my_place.second)Left();

		}
		Input();
	}
	cout<<ans<<endl;
}
