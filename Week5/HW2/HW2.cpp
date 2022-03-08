#include <iostream>

using namespace std;

struct status{
    int size;
    int count_rows[7];
    bool current_chessboard[7][7];
    int count_columns[7];
};

int calculate(status &s, int row){
    int answer = 0;
    if(row == s.size)
        return 1;

    answer += calculate(s, row+1);

    for (int i = 0; i < s.size; i++){
        if (s.current_chessboard[row][i])
            continue;
        s.current_chessboard[row][i] == true;
        s.count_rows[row]++;
        s.count_columns[i]++;
        if (s.count_rows[row] <= 2 && s.count_columns[i] <= 2)
            answer += calculate(s, row+1);
        s.current_chessboard[row][i] == false;
        s.count_rows[row]--;
        s.count_columns[i]--;
    }
    for (int i = 0; i < s.size-1; i++){
        if (s.current_chessboard[row][i])
            continue;
        for (int j = i + 1; j < s.size; j++){
            if (s.current_chessboard[row][j])
                continue;
            s.current_chessboard[row][i] == true;
            s.current_chessboard[row][j] == true;
            s.count_rows[row] += 2;
            s.count_columns[j] ++;
            s.count_columns[i] ++;
            if (s.count_rows[row] <= 2 && s.count_columns[i] <= 2 && s.count_columns[j] <= 2)
                answer += calculate(s, row+1);
            s.current_chessboard[row][i] == false;
            s.current_chessboard[row][j] == false;
            s.count_rows[row] -= 2;
            s.count_columns[j] --;
            s.count_columns[i] --;
        }
    }
    return answer;
}

int main(void){
    status chessboard;
    int k;
    cin >> chessboard.size >> k;
    int x, y;

    for (int i = 0; i < chessboard.size; i++){
        chessboard.count_rows[i] = 0;
        chessboard.count_columns[i] = 0;
        for (int j = 0; j < chessboard.size; j++)
            chessboard.current_chessboard[i][j] = false;
    }

    for (int i = 0; i < k; i++){
        cin >> x >> y;
        chessboard.count_rows[x]++;
        chessboard.count_columns[y]++;
        chessboard.current_chessboard[x][y] = true;
    }

    cout << calculate(chessboard,0) << endl;

    return 0;
}