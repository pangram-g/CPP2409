#include <iostream>
using namespace std;

int main()
{
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y; // ����ڿ��� �Է¹޴� x,y��ǥ�� �����ϴ� ����

    // ������ �ʱ�ȭ
    for (x = 0; x < numCell; x++)
    {
        for (y = 0; y < numCell; y++)
        {
            board[x][y] = ' ';
        }
    }

    // ���� �ڵ�
    int k = 0;              // ���� �������� Ȯ�� ����
    char currentUser = 'X'; // ���������� ���� �����ϴ� ���� ����
    while (1)
    { // 1.���� �������� ���
        switch (k % 2)
        {
        case 0:
            cout << "ù��° ����(X)�� �����Դϴ� -> ";
            currentUser = 'X';
            break;
        case 1:
            cout << "�ι�° ����(O)�� �����Դϴ� -> ";
            currentUser = 'O';
            break;
        }

        // 2.��ǥ �Է¹ޱ�
        cout << "(x, y) ��ǥ�� �Է��ϼ��� : ";
        cin >> x >> y;

        // 3. �Է¹��� ��ǥ ��ȿ�� üũ
        // �Ϲ������� ���ڸ� ���� 1���� �����ϹǷ� -1�� ����
        if (x - 1 >= numCell || y - 1 >= numCell)
        {
            cout << x << ", " << y << ": ";
            cout << "x�� y �� �� �ϳ��� ĭ�� ����ϴ�." << endl;
            continue;
        }
        if (board[x - 1][y - 1] != ' ')
        {
            cout << x << ", " << y << ": �̹� ���� ���ֽ��ϴ�." << endl;
            continue;
        }
        // 4.�Է¹��� ��ǥ�� �� ����
        board[x - 1][y - 1] = currentUser;

        // 5.���� ������ ���
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

        // 6.�������� á���� Ȯ��
        int A = 0; // ������ á���� Ȯ�� ����
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
            cout << "�������� ���� á���ϴ�. ���º� �Դϴ�.";
            return 0;
        }
        // 7.����� ���� ����� ����
        int end = 0; // ���� ������ ����
        for (int i = 0; i < 3; i++)//����, ������ Ȯ�� for��
        {
            if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser)
            {
                end = 1;
                cout << "���ο� ���� ���� �Դϴ�!" << "\n";
            }

            if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser)
            {
                end = 2;
                cout << "���ο� ���� ���� �Դϴ�!" << "\n";
            }
        }

        if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser)
        {
            end = 3;
            cout << "���� �� ������ �Ʒ� �밢���� ���� ���� �Դϴ�!" << "\n";
        }

        if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser)
        {
            end = 4;
            cout << "���� �Ʒ� ������ �� �밢���� ���� ���� �Դϴ�!" << "\n";
        }
        if (end != 0)
        {
            cout << "�����մϴ�! " << currentUser << "���� �̰���ϴ�!";
            return 0;
        }
    }
    return 0;
}
