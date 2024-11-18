#include "user.h"
#include <vector>

const int mapX = 5;
const int mapY = 5;

// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(vector<vector<int>> &map, int user_x, int user_y);
bool checkGoal(vector<vector<int>> &map, int user_x, int user_y);
void checkState(vector<vector<int>> &map, int user_x, int user_y, User &user);
void movePlayer(int &user_x, int &user_y, int ax, int ay, vector<vector<int>> &map, User &user);
bool CheckUser(User user);

// ����  �Լ�
int main()
{
    // 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
    vector<vector<int>> map = {{0, 1, 2, 0, 4},
                               {1, 0, 0, 2, 0},
                               {0, 0, 0, 0, 0},
                               {0, 2, 3, 0, 0},
                               {3, 0, 0, 0, 2}};

    // ������ ���� ����, ��ü
    int user_x = 0; // ������ ��ġ
    int user_y = 0; // ������ ��ġ
    User user;      // ���� ���� ��ü ����

    // ���� ����
    while (1)
    { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

        // ������� �Է��� ������ ����
        string user_input = "";

        cout << "��ɾ �Է��ϼ��� (��,��,��,��,����,����,����): ";
        cin >> user_input;

        // �÷��̾� �����¿� ������ ����ȭ
        if (user_input == "��")
        {
            movePlayer(user_x, user_y, 0, -1, map, user);
        }
        else if (user_input == "��")
        {
            movePlayer(user_x, user_y, 0, 1, map, user);
        }
        else if (user_input == "��")
        {
            movePlayer(user_x, user_y, -1, 0, map, user);
        }
        else if (user_input == "��")
        {
            movePlayer(user_x, user_y, 1, 0, map, user);
        }
        else if (user_input == "����")
        {
            displayMap(map, user_x, user_y);
        }
        else if (user_input == "����")
        {
            cout << user << endl;
            continue;
        }
        else if (user_input == "����")
        {
            cout << "�����մϴ�.";
            break;
        }
        else
        {
            cout << "�߸��� �Է��Դϴ�." << endl;
            continue;
        }
        checkState(map, user_x, user_y, user);

        // �������� �����ߴ��� üũ
        bool finish = checkGoal(map, user_x, user_y);
        if (finish == true)
        {
            cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
            cout << "������ �����մϴ�." << endl;
            break;
        }

        // HP�� 0���� Ȯ��
        if (CheckUser(user) == false)
        {
            cout << " HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
            cout << " ������ �����մϴ�." << endl;
            break;
        }
    }

    return 0;
}

// �÷��̾� ������(�����¿�) ����ȭ �Լ�
// �����͸� ����� �Լ� ���� ��ǥ���� ������ ��ġ����
void movePlayer(int &user_x, int &user_y, int ax, int ay, vector<vector<int>> &map, User &user)
{
    int new_x = user_x + ax;
    int new_y = user_y + ay;

    if (checkXY(new_x, mapX, new_y, mapY) == false)
    {
        cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
    }
    else
    {
        user_x = new_x;
        user_y = new_y;
        user.DeCreaseHP(1); // ���� �̵� �� HP 1 ����
        if (ay == -1)
            cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
        else if (ay == 1)
            cout << "�Ʒ��� �� ĭ �������ϴ�." << endl;
        else if (ax == -1)
            cout << "�������� �� ĭ �̵��մϴ�." << endl;
        else if (ax == 1)
            cout << "���������� �� ĭ �̵��մϴ�." << endl;
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

// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(vector<vector<int>> &map, int user_x, int user_y)
{
    for (int i = 0; i < mapY; i++)
    {
        for (int j = 0; j < mapX; j++)
        {
            if (i == user_y && j == user_x)
            {
                cout << " USER |"; // �� �� 1ĭ ����
            }
            else
            {
                int posState = map[i][j];
                switch (posState)
                {
                case 0:
                    cout << "      |"; // 6ĭ ����
                    break;
                case 1:
                    cout << "������|";
                    break;
                case 2:
                    cout << "  ��  |"; // �� �� 2ĭ ����
                    break;
                case 3:
                    cout << " ���� |"; // �� �� 1ĭ ����
                    break;
                case 4:
                    cout << "������|";
                    break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY)
{
    bool checkFlag = false;
    if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY)
    {
        checkFlag = true;
    }
    return checkFlag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(vector<vector<int>> &map, int user_x, int user_y)
{
    // ������ �����ϸ�
    if (map[user_y][user_x] == 4)
    {
        return true;
    }
    return false;
}

// ������ ��ġ�� Ȯ���ϴ� �Լ�
void checkState(vector<vector<int>> &map, int user_x, int user_y, User &user)
{
    if (map[user_y][user_x] == 1)
    {
        cout << "�������� �ֽ��ϴ�." << endl;
        user.InCreaseItem(1);
    }
    if (map[user_y][user_x] == 2)
    {
        cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�" << endl;
        user.DeCreaseHP(2); // ���� ���� �� HP 2����
    }
    if (map[user_y][user_x] == 3)
    {
        cout << "������ �ֽ��ϴ�. HP�� 2 �����մϴ�" << endl;
        user.InCreaseHP(2); // ���� ���� �� HP 2����
    }
}