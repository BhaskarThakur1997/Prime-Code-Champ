/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<pair<int, int>> findMaxMinPostion(vector<vector<int>>& grid){
	int n = grid.size();
	int maxMin = numeric_limits<int>::min();
	vector<pair<int, int>> positions;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int minimum = numeric_limits<int>::max();

			for(int dx=-1; dx<=1;dx++){
				for(int dy=-1; dy<=1; dy++){
					int x = i+dx;
					int y = j+dy;

					if(x>=0 && x<n && y>=0 && y<n){
						minimum = min(minimum, grid[x][y]);
					}
				}
			}

			if(minimum > maxMin){
				maxMin = minimum;
				positions.clear();
				positions.push_back({i+1, j+1});
			}else if(minimum == maxMin){
				positions.push_back({i+1, j+1});
			}
		}
	}
	
	return positions;
}
int main()
{
	int n;
	cin >> n;

	vector <vector<int>> grid(n, vector<int>(n));

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			char result;
			cin >> grid[i][j];
			if(j < n-1){
				cin >> result;
			}
		}
	}

	vector<pair<int, int>> positions = findMaxMinPostion(grid);

	for(const auto& pos : positions){
		cout <<pos.first <<"#" <<pos.second <<endl;
	}
	return 0;
	//Write code here
}
