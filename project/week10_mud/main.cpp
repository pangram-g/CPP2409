#include "user.h"

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, User &user);
void movePlayer(int &user_x, int &user_y, int ax, int ay, int map[][mapX], User &user);
bool CheckUser(User user);

// 메인  함수
int main()
{
    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    int map[mapY][mapX] = {{0, 1, 2, 0, 4},
                           {1, 0, 0, 2, 0},
                           {0, 0, 0, 0, 0},
                           {0, 2, 3, 0, 0},
                           {3, 0, 0, 0, 2}};

    // 유저에 관한 변수, 객체
    int user_x = 0; // 가로축 위치
    int user_y = 0; // 세로축 위치
    User user;      // 단일 유저 객체 생성

    // 게임 시작
    while (1)
    { // 사용자에게 계속 입력받기 위해 무한 루프

        // 사용자의 입력을 저장할 변수
        string user_input = "";

        cout << "현재 HP: " << user.GetHP() << "   ";
        cout << "명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
        cin >> user_input;

        // 플레이어 상하좌우 움직임 간결화
        if (user_input == "상")
        {
            movePlayer(user_x, user_y, 0, -1, map, user);
        }
        else if (user_input == "하")
        {
            movePlayer(user_x, user_y, 0, 1, map, user);
        }
        else if (user_input == "좌")
        {
            movePlayer(user_x, user_y, -1, 0, map, user);
        }
        else if (user_input == "우")
        {
            movePlayer(user_x, user_y, 1, 0, map, user);
        }
        else if (user_input == "지도")
        {
            displayMap(map, user_x, user_y);
        }
        else if (user_input == "종료")
        {
            cout << "종료합니다.";
            break;
        }
        else
        {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }
        checkState(map, user_x, user_y, user);

        // 목적지에 도달했는지 체크
        bool finish = checkGoal(map, user_x, user_y);
        if (finish == true)
        {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        // HP가 0인지 확인
        if (CheckUser(user) == false)
        {
            cout << " HP가 0 이하가 되었습니다. 실패했습니다." << endl;
            cout << " 게임을 종료합니다." << endl;
            break;
        }
    }

    return 0;
}

// 플레이어 움직임(상하좌우) 간결화 함수
// 포인터를 사용해 함수 밖의 좌표까지 영향이 미치게함
void movePlayer(int &user_x, int &user_y, int ax, int ay, int map[][mapX], User &user)
{
    int new_x = user_x + ax;
    int new_y = user_y + ay;

    if (checkXY(new_x, mapX, new_y, mapY) == false)
    {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
    }
    else
    {
        user_x = new_x;
        user_y = new_y;
        user.DeCreaseHP(1); // 정상 이동 시 HP 1 감소
        if (ay == -1)
            cout << "위로 한 칸 올라갑니다." << endl;
        else if (ay == 1)
            cout << "아래로 한 칸 내려갑니다." << endl;
        else if (ax == -1)
            cout << "왼쪽으로 한 칸 이동합니다." << endl;
        else if (ax == 1)
            cout << "오른쪽으로 한 칸 이동합니다." << endl;
        displayMap(map, user_x, user_y);
    }
}

bool CheckUser(User user)
{
    if (user.GetHP() > 0)
        return true;
    else
        return false;
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y)
{
    for (int i = 0; i < mapY; i++)
    {
        for (int j = 0; j < mapX; j++)
        {
            if (i == user_y && j == user_x)
            {
                cout << " USER |"; // 양 옆 1칸 공백
            }
            else
            {
                int posState = map[i][j];
                switch (posState)
                {
                case 0:
                    cout << "      |"; // 6칸 공백
                    break;
                case 1:
                    cout << "아이템|";
                    break;
                case 2:
                    cout << "  적  |"; // 양 옆 2칸 공백
                    break;
                case 3:
                    cout << " 포션 |"; // 양 옆 1칸 공백
                    break;
                case 4:
                    cout << "목적지|";
                    break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY)
{
    bool checkFlag = false;
    if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY)
    {
        checkFlag = true;
    }
    return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y)
{
    // 목적지 도착하면
    if (map[user_y][user_x] == 4)
    {
        return true;
    }
    return false;
}

// 유저의 위치를 확인하는 함수
void checkState(int map[][mapX], int user_x, int user_y, User &user)
{
    if (map[user_y][user_x] == 1)
    {
        cout << "아이템이 있습니다." << endl;
    }
    if (map[user_y][user_x] == 2)
    {
        cout << "적이 있습니다. HP가 2 줄어듭니다" << endl;
        user.DeCreaseHP(2); // 적과 조우 후 HP 2감소
    }
    if (map[user_y][user_x] == 3)
    {
        cout << "포션이 있습니다. HP가 2 증가합니다" << endl;
        user.InCreaseHP(2); // 포션 얻은 후 HP 2증가
    }
}