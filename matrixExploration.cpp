#include <iostream>
#include <sstream>
#include <iomanip>
#include <queue>
using namespace std; 
#define N 1000
#define M 1000
int n, m, k;
int kinput[500][2];
int input[N][M];
int cellNo=0;
queue<pair<int, int>> q;


/*Reading one character of the input. Allowed cells are noted with '.' and are saved with -1. Forbidden cells are noted with '#' and are saved with -2.*/
void read(int i, int j){
	char in;
	cin >> in; 
	if(in=='.'){
		input[i][j]=-1;
		++cellNo;
	}
	else if(in=='#'){
		input[i][j]=-2;
	}
}

/*No true usage for the solution. Implemented for the understanding of the problem*/
void deBugPrint(){
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			/*setw is a formating function. It does the same as %.4d in printf*/
			cout << setw(4) <<  input[i][j];
		}
		cout << endl;
	}
}

/*The main logic of the solution.*/
void entersTheQueue(int i, int j){
	/*This is the array the program traverses. It is the 4 directions allowed by the definition of the problem.*/
	int direction[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
	/*Debugging line that makes sure we see every cell*/
	// cout << "i=" << i << ", j=" << j << endl;
	/*The program traverses the 4 directions, in order ot avoid to implemented the same logic 4 time.*/
	for (int count = 0; count < 4; ++count) {
		/*Values only here to help*/
		int neighbori = i+direction[count][0];
		int neighborj = j+direction[count][1];
		/*The following "if-statement" is here to make sure there is a neighboring cell*/
		if(neighbori < n && neighborj < m && neighbori > -1 && neighborj > -1){
			/*This "if-statement" is here for the cells that have never been visited before.*/
			if(input[neighbori][neighborj]==-1){
				input[neighbori][neighborj]=input[i][j]+1;
				q.push(make_pair(neighbori,neighborj));
			}
			/*The "else-if-statement" is for cells already visited. If the value of the cell is bigger than the new potential value, we change the value and we put the cell back at the queue.

			The cells don't enter the queue more than K-times. 
			*/
			else if(input[neighbori][neighborj]>0){
				if(input[neighbori][neighborj] > input[i][j]+1){
					input[neighbori][neighborj] = input[i][j]+1;
					q.push(make_pair(neighbori,neighborj));
				}
			}
			continue;
		}
	}
}

int solve(){
	/*While the queue is not empty the algorithm checks the neighborhood of the top and then pops it*/
	while(!q.empty()){
		pair<int,int> curr=q.front();
		entersTheQueue(curr.first, curr.second);
		q.pop();
	}
	/*the program traverses the array and finds the sum of non-negative values*/
	int res=0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if(input[i][j]>-1)
				res += input[i][j];
		}
	}
	return res;
}

int main(){
	int ki, kj; 
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			read(i,j);
		}
	}
	for (int i = 0; i < k; ++i) {
		cin >> ki >> kj;
		--ki; --kj;
		input[ki][kj] = -0;
		kinput[i][0] = ki;
		kinput[i][1] = kj;
		q.push(make_pair(ki,kj));
	}
	// pair<int,int> test = q.front();	
	// cout << q.front().first;	
	// deBugPrint();
	// cout << endl;
	cout << solve();
	// deBugPrint();
	// cout << 	cellNo;
}