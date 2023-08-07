#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <set>
#include <array>
#include <cmath>
#include <map>
using namespace std;
class Solution1 {
public:
	vector<vector<string>> res;
	vector<vector<string>> solveNQueens(int n) {
		vector<string> board(n, string(n, '.'));
		backtrack(board, 0);
		return res;
	}
	void backtrack(vector<string> &board, int row) {
		//��������
		if (row == board.size()) {
			res.push_back(board);
			return;
		}
		int n = board[row].size();
		for (int col = 0; col < n; col++) {
			//�ų����Ϸ�ѡ��
			if (!isValid(board, row, col)) {
				continue;
			}
			//��ѡ��
			board[row][col] = 'Q';
			//������һ�о���
			backtrack(board, row + 1);
			//����ѡ��
			board[row][col] = '.';
		}
	}
	//�Ƿ������board[row][col]���ûʺ�
	bool isValid(vector<string> & board, int row, int col) {

		int n = board.size();

		//������Ƿ��лʺ����ͻ
		for (int i = 0; i < row; i++) {
			if (board[i][col] == 'Q') {
				return false;
			}
		}
		//������Ϸ��Ƿ��лʺ����ͻ
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
			if (board[i][j] == 'Q') {
				return false;
			}
		}
		//������Ϸ��Ƿ��лʺ����ͻ
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
			if (board[i][j] == 'Q') {
				return false;
			}
		}
		return true;
	}
};


//��˺һ��n�ʺ�
class Solution2 {
public:

	vector<vector<string>> res;

	vector <vector<string>> solveNQueens(int n) {
		vector<string> board(n, string(n, '.'));
		backtrack(board, 0);
		return res;
	}
	void backtrack(vector<string>& board, int row) {
		//������������
		if (row == board.size()) {
			res.push_back(board);
			return;
		}

		int n = board[row].size();
		for (int col = 0; col < n; col++) {
			if (!isValid(board, row, col)) {
				continue;
			}
			//��ѡ��
			board[row][col] = 'Q';
			//������һ�о���
			backtrack(board, row + 1);
			board[row][col] = '.';
		}

	}
	bool isValid(vector<string>&board, int row, int col) {

		//
		int n = board.size();

		//����Ҫ����Ϸ�
		for (int i = 0; i < row; i++) {
			if (board[i][col] == 'Q') {
				return false;
			}
		}
		//Ȼ��������
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
			if (board[i][j] == 'Q') {
				return false;
			}
		}
		//Ȼ��������
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
			if (board[i][j] == 'Q') {
				return false;
			}
		}
		return true;
	}
};

//int main() 	{
//	Solution s;
//	vector<vector<string>> res = s.solveNQueens(4);
//	return 0;
//}
class Solution {
public:
	//�洢���
	vector<vector<string>> res;
	vector<vector<string>> solveNQueens(int n) {
		vector<string> board(n, string(n, '.'));
		backtrack(board, 0);
		return res;
	}
	void backtrack(vector<string>& board, int row) {

		if (row == board.size()) {
			res.push_back(board);
			return;
		}

		int n = board[row].size();
		for (int col = 0; col < n; col++) {
			if (!isValid(board, row, col)) {
				continue;
			}
			board[row][col] = 'Q';
			backtrack(board, row + 1);
			board[row][col] = '.';
		}
	}
	bool isValid(vector<string> &board, int row, int column) {
		int n = board.size();

		for (int i = 0; i < row; i++) {
			if (board[i][column] == 'Q') {
				return false;
			}
		}

		for (int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++) {
			if (board[i][j] == 'Q') {
				return false;
			}
		}
		for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
			if (board[i][j] == 'Q') {
				return false;
			}

		}
		return true;
	}
};