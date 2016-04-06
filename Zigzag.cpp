#include <iostream>
#include <typeinfo>
#include <string>
#include <memory.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
    	int length = s.size(), count = numRows*2-2;
        int column = length / count;
        int tmp = length % count;
        column = column * 2 + (tmp == 0 ? 0 : (tmp <= numRows ? 1 : 2));
        char **matrix = new char*[numRows];
        for (int i = 0; i < numRows; ++i) {
        	matrix[i] = new char[column];
        	memset(*(matrix+i), '\0', column*sizeof(char));
        }
        int row = 0, col = 0;
        for (int i = 0; i < length; ++i) {
        	col = (i+1) / count;
        	tmp = (i+1) % count;
        	col = col * 2 + (tmp == 0 ? 0 : (tmp <= numRows ? 1 : 2)) - 1; 
        	row = tmp == 0 ? 1 : (tmp <= numRows ? (tmp-1) : (2*numRows-tmp-1));
        	matrix[row][col] = s[i];
        }
        char *tmpResult = new char[length+1];
        int index = 0; 
        for (int i = 0; i < numRows; ++i) {
        	for (int j = 0; j < column; ++j) {
        		if (matrix[i][j] != '\0') {
        			tmpResult[index++] = matrix[i][j];
        		}
        		if (i == 0 || i == numRows-1) ++j;
        	}
        }
        tmpResult[index] = '\0';
        string result(tmpResult);
        return result;
    }
};

int main() {
	Solution a;
	cout<<a.convert("PAYPALISHIRING", 3)<<endl;
	return 0;
}