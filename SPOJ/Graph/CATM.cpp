#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

float dist(int x1, int y1, int x2, int y2){
	//return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
	return abs(x1-x2) + abs(y2-y1);
}

bool live(int n, int m, int mx, int my, int c1x, int c1y, int c2x, int c2y){

	queue<pair<int,int> > rat;
	queue<pair<int,int> > cat1;
	queue<pair<int,int> > cat2;

	vector<vector<int> > vrat(n+1,vector<int> (m+1,false));
	vector<vector<int> > vc1(n+1,vector<int> (m+1,false));
	vector<vector<int> > vc2(n+1,vector<int> (m+1,false));

	rat.push(make_pair(mx,my));
	cat1.push(make_pair(c1x,c1y));
	cat2.push(make_pair(c2x,c2y));

	vrat[mx][my] = true;
	vc1[c1x][c1y] = true;
	vc2[c2x][c2y] = true;

	while(!rat.empty() && !cat1.empty() && !cat2.empty()){
		pair<int,int> rat_pos = rat.front();
		rat.pop();
		
		pair<int,int> cat_pos1 = cat1.front();
		cat1.pop();
		
		pair<int,int> cat_pos2 = cat2.front();
		cat2.pop();

		if(rat_pos==cat_pos1 || rat_pos == cat_pos2)
			return false;
		
		if(rat_pos.first == 1 ||  rat_pos.first == n || rat_pos.second == 1 || rat_pos.second == m)
			return true;

		if(!vrat[rat_pos.first-1][rat_pos.second]){
			rat.push(make_pair(rat_pos.first-1,rat_pos.second));
			vrat[rat_pos.first-1][rat_pos.second] = true;
		}
		if(!vrat[rat_pos.first+1][rat_pos.second]){
			rat.push(make_pair(rat_pos.first+1,rat_pos.second));
			vrat[rat_pos.first+1][rat_pos.second] = true;
		}
		if(!vrat[rat_pos.first][rat_pos.second-1]){
			rat.push(make_pair(rat_pos.first,rat_pos.second-1));
			vrat[rat_pos.first][rat_pos.second-1] = true;
		}
		if(!vrat[rat_pos.first][rat_pos.second+1]){
			rat.push(make_pair(rat_pos.first,rat_pos.second+1));
			vrat[rat_pos.first][rat_pos.second+1] = true;
		}

		if(!vc1[cat_pos1.first-1][cat_pos1.second]){
			rat.push(make_pair(cat_pos1.first-1,cat_pos1.second));
			vc1[cat_pos1.first-1][cat_pos1.second] = true;
		}
		if(!vc1[cat_pos1.first+1][cat_pos1.second]){
			rat.push(make_pair(cat_pos1.first+1,cat_pos1.second));
			vc1[cat_pos1.first+1][cat_pos1.second] = true;
		}
		if(!vc1[cat_pos1.first][cat_pos1.second-1]){
			rat.push(make_pair(cat_pos1.first,cat_pos1.second-1));
			vc1[cat_pos1.first][cat_pos1.second-1] = true;
		}
		if(!vc1[cat_pos1.first][cat_pos1.second+1]){
			rat.push(make_pair(cat_pos1.first,cat_pos1.second+1));
			vc1[cat_pos1.first][cat_pos1.second+1] = true;
		}

		if(!vc2[cat_pos2.first-1][cat_pos2.second]){
			rat.push(make_pair(cat_pos2.first-1,cat_pos2.second));
			vc2[cat_pos2.first-1][cat_pos2.second] = true;
		}
		if(!vc2[cat_pos2.first+1][cat_pos2.second]){
			rat.push(make_pair(cat_pos2.first+1,cat_pos2.second));
			vc2[cat_pos2.first+1][cat_pos2.second] = true;
		}
		if(!vc2[cat_pos2.first][cat_pos2.second-1]){
			rat.push(make_pair(cat_pos2.first,cat_pos2.second-1));
			vc2[cat_pos2.first][cat_pos2.second-1] = true;
		}
		if(!vc2[cat_pos2.first][cat_pos2.second+1]){
			rat.push(make_pair(cat_pos2.first,cat_pos2.second+1));
			vc2[cat_pos2.first][cat_pos2.second+1] = true;
		}

	} 

	return false;
}

int main(int argc, char const *argv[]) {
	int n,m;
	cin>>n>>m;
	int mx, my, c1x, c1y, c2x, c2y,t;
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>mx>>my>>c1x>>c1y>>c2x>>c2y;
		
		vector<int> top(m);
		vector<int> bottom(m);

		vector<int> right(n);
		vector<int> left(n);

		for(int i=1; i<=m; ++i){
			top[i-1] = dist(mx, my, 1, i);
			bottom[i-1] = dist(mx, my, n, i);
		}
		
		for(int i=1; i<=n; ++i){
			left[i-1] = dist(mx, my, i, 1);
			right[i-1] = dist(mx, my, i, m);
		}

		int found = 0;
		for(int i=1; i<=m; ++i){
			if(top[i-1] < dist(c1x, c1y, 1, i) &&  top[i-1] < dist(c2x, c2y, 1, i)){
				found = 1;
				break;
			}
			if(bottom[i-1] < dist(c1x, c1y, n, i) &&  bottom[i-1] < dist(c2x, c2y, n, i)){
				found = 1;
				break;
			}
		}
		
		for(int i=1; i<=n; ++i){
			if(left[i-1] < dist(c1x, c1y, i, 1) &&  left[i-1] < dist(c2x, c2y, i, 1)){
				found = 1;
				break;
			}
			if(right[i-1] < dist(c1x, c1y, i, m) &&  right[i-1] < dist(c2x, c2y, i, m)){
				found = 1;
				break;
			}
		}

		if(found) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}	
	return 0;
}