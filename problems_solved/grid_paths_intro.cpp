#include<bits/stdc++.h>
using namespace std;
 
char inp[48];
bool already_traversed[7][7];
 
int graph_traversal(int row, int column, int current_char_position) {
    // cout<<"HELLO" << row << column << current_char_position<<endl;
    if (row < 0 || row >= 7 || column < 0 || column >= 7) return 0;
    if (already_traversed[row][column]) return 0;
    // cout<<"HELLO" << row << column << current_char_position<<endl;
    if (current_char_position == 48 && row == 6 && column == 0) return 1; 
    if (current_char_position >= 48) return 0;
    if (row == 6 && column == 0) return 0;
 
    if (row == 0 && column < 6 && column > 0 &&!already_traversed[row][column + 1] && !already_traversed[row][column - 1]) return 0;
    if (column == 0 && row > 0 && row < 6 && !already_traversed[row + 1][column] && !already_traversed[row - 1][column]) return 0;
    if (row == 6 && column < 6 && column > 0 && !already_traversed[row][column + 1] && !already_traversed[row][column - 1]) return 0;
    if (column == 6 && row > 0 && row < 6 && !already_traversed[row + 1][column] && !already_traversed[row - 1][column]) return 0;
    if (0 < row && row < 6 && 0 < column && column < 6) {
        if (!already_traversed[row][column-1] && !already_traversed[row][column + 1] && already_traversed[row-1][column] && already_traversed[row+1][column]) {return 0;}
        // if (!already_traversed[row][column-1] && already_traversed[row][column + 1] && !already_traversed[row-1][column] && already_traversed[row+1][column]) return 0;
        // if (!already_traversed[row][column-1] && already_traversed[row][column + 1] && already_traversed[row-1][column] && !already_traversed[row+1][column]) return 0;
        // if (already_traversed[row][column-1] && !already_traversed[row][column + 1] && !already_traversed[row-1][column] && already_traversed[row+1][column]) return 0;
        // if (already_traversed[row][column-1] && !already_traversed[row][column + 1] && already_traversed[row-1][column] && !already_traversed[row+1][column]) return 0;
        if (already_traversed[row][column-1] && already_traversed[row][column + 1] && !already_traversed[row-1][column] && !already_traversed[row+1][column]) {return 0;}
    }
    int count = 0 ;
    already_traversed[row][column] = true;
    if (inp[current_char_position] == '?') {
            count += graph_traversal(row + 1, column, current_char_position + 1);
            count += graph_traversal(row - 1, column, current_char_position + 1);
            count += graph_traversal(row, column - 1, current_char_position + 1);
            count += graph_traversal(row, column + 1, current_char_position + 1);
        
    }
    else if (inp[current_char_position] == 'D') {
        // cout<<row<<" d "<<column<<endl;
        if (row == 5 && column == 6) {
            if (inp[current_char_position + 1] != 'L' && inp[current_char_position + 1] != '?') return 0;
            already_traversed[6][6] = true;
            count += graph_traversal(6, 5, current_char_position + 2);
            already_traversed[6][6] = false;
        }
        
        else {
            count += graph_traversal(row + 1, column, current_char_position + 1);
            
        }
    }
    else if (inp[current_char_position] == 'U') {
        if (row == 1 && column == 6) {
            if (inp[current_char_position + 1] != 'L' && inp[current_char_position + 1] != '?') return 0;
            already_traversed[0][6] = true;
            count += graph_traversal(0, 5, current_char_position + 2);
            already_traversed[0][6] = false;
        }
        else {
            count += graph_traversal(row - 1, column, current_char_position + 1);
        }
    }
    else if (inp[current_char_position] == 'L') {
            count += graph_traversal(row, column - 1, current_char_position + 1);
    }
    else if (inp[current_char_position] == 'R') {
        if (row == 0 && column == 5) {
            if (inp[current_char_position + 1] != 'D' && inp[current_char_position + 1] != '?') return 0;
            already_traversed[0][6] = true;
            count += graph_traversal(1, 6, current_char_position + 2);
            already_traversed[0][6] = false;
        }
        else if (row == 6 && column == 5) {
            if (inp[current_char_position + 1] != 'U' && inp[current_char_position + 1] != '?') return 0;
            already_traversed[6][6] = true;
            count += graph_traversal(5, 6, current_char_position + 2);
            already_traversed[6][6] = false;
        }
        else {
            count += graph_traversal(row, column + 1, current_char_position + 1);
        }
    }
    already_traversed[row][column] = false;
    return count;
}
 
int main () {
    
    for (int i = 0 ; i < 48 ; i ++ ) {
        cin >> inp[i];
    }
 
    for (int i = 0 ; i < 7 ; i ++ ) { 
        for (int j = 0 ; j < 7 ; j ++ ) {
            already_traversed[i][j] = false;
        }
    }
 
    cout << graph_traversal(0 , 0 , 0);
 
 
}