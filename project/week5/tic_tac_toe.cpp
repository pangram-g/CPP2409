#include <iostream>
using namespace std;

int main()
{
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y; // 사용자에게 입력받는 x,y좌표를 저장하는 변수

    // 보드판 초기화
    for (x = 0; x < numCell; x++)
    {
        for (y = 0; y < numCell; y++)
        {
            board[x][y] = ' ';
        }
    }

    // 게임 코드
    int k = 0;              // 누구 차례인지 확인 변수
    char currentUser = 'X'; // 현재유저의 돌을 저장하는 문자 변수
    while (1)
    { // 1.누구 차례인지 출력
        switch (k % 2)
        {
        case 0:
            cout << "첫번째 유저(X)의 차례입니다 -> ";
            currentUser = 'X';
            break;
        case 1:
            cout << "두번째 유저(O)의 차례입니다 -> ";
            currentUser = 'O';
            break;
        }

        // 2.좌표 입력받기
        cout << "(x, y) 좌표를 입력하세요 : ";
        cin >> x >> y;

        // 3. 입력받은 좌표 유효성 체크
        if (x - 1 >= numCell || y - 1 >= numCell)
        {
            cout << x << ", " << y << ": ";
            cout << "x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        if (board[x - 1][y - 1] != ' ')
        {
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }
        // 4.입력받은 좌표에 돌 놓기
        board[x - 1][y - 1] = currentUser;

        // 5.현재 보드판 출력
        for (int i = 0; i < numCell; i++)
        {
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++)
            {
                cout << board[i][j];
                if (j == numCell - 1)
                {
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;
        k++;

        // 6.보드판이 찼는지 확인
        int A = 0; // 보드판 찼는지 확인 변수
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != ' ')
                {
                    A++;
                }
            }
        }
        if (A == 9)
        {
            cout << "보드판이 전부 찼습니다. 무승부 입니다.";
            return 0;
        }
        // 7.빙고시 승자 출력후 종료
        int end = 0; // 게임 끝내는 변수
        for (int i = 0; i < 3; i++)//가로, 세로줄 확인 for문
        {
            if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser)
            {
                end = 1;
                cout << "가로에 돌이 한줄 입니다!" << "\n";
            }

            if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser)
            {
                end = 2;
                cout << "세로에 돌이 한줄 입니다!" << "\n";
            }
        }

        if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser)
        {
            end = 3;
            cout << "왼쪽 위 오른쪽 아래 대각선에 돌이 한줄 입니다!" << "\n";
        }

        if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser)
        {
            end = 4;
            cout << "왼쪽 아래 오른쪽 위 대각선에 돌이 한줄 입니다!" << "\n";
        }
        if (end != 0)
        {
            cout << "축하합니다! " << currentUser << "말이 이겼습니다!";
            return 0;
        }
    }
    return 0;
}
