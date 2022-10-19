/*
Let's play the minesweeper game (Wikipedia, online game)!

You are given an m x n char matrix board representing the game board where:

'M' represents an unrevealed mine,
'E' represents an unrevealed empty square,
'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
'X' represents a revealed mine.
*/



class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

	int i=click[0], j=click[1];

	if(board[i][j]=='M') 
		board[i][j]='X';

	if(board[i][j]!='E')
            return board;

	reveal(board, i, j);

	return board;
}

vector<vector<int>> dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void reveal(vector<vector<char>>& board, int i, int j){
	if(i<0 || i==board.size() || j<0 || j==board[0].size() || board[i][j]!='E') return;

	int num=0;
	for(auto dir: dirs){
		int x=i+dir[0], y=j+dir[1];
		if(x>=0 && y>=0 && x<board.size() && y<board[0].size() && board[x][y]=='M') num++;
	}

	board[i][j]=(num==0?'B':'0'+num);
	if(num==0)
		for(auto dir: dirs)
			reveal(board, i+dir[0], j+dir[1]);
}
};
