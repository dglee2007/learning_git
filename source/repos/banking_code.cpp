#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;  // �� �̸� ���� (�ѱ� �� ���ڴ� 2 ����Ʈ)
const int MAX_CUS_NUM = 100; // �ִ� �� ��

void ShowMenu(void);            // �޴� ����� ���� �Լ�
void MakeAccount(void);         // ���� ������ ���� �Լ� 
void DepositMoney(void);        // �Ա��� ���� �Լ�
void WithdrawMoney(void);       // ����� ���� �Լ�
void ShowAllAccInfo(void);      // ��� ���� ���� ����� ���� �Լ�

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };  // ������ �̸� ���� ����

typedef struct   // ����ü �̸� ���� ����
{
    int accID;    // ���� ��ȣ
    int balance;  // �ܾ�
    char cusName[NAME_LEN];  // �� �̸�
} ACCOUNT;


ACCOUNT account[MAX_CUS_NUM];  // ���� ó���� ���� �迭
int accNum = 0;  // ���� �ε���


int main(void)
{
    int choice;

    while (1)
    {
        ShowMenu();

        cout << "����: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithdrawMoney();
            break;
        case INQUIRE:
            ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "�߸��� �Է� �Դϴ�." << endl;

        }
    }

    system("pause");  // VC++ ������ �ʿ�

    return 0;
}


void ShowMenu(void)
{
    cout << endl;
    cout << "------------------Menu------------------" << endl;
    cout << "1. ���� ����" << endl;
    cout << "2. �Ա�" << endl;
    cout << "3. ����" << endl;
    cout << "4. ���� ���� ��ü ���" << endl;
    cout << "5. ���α׷� ����" << endl << endl;
}

void MakeAccount(void)
{
    cout << endl;
    cout << "[���� ����]" << endl;
    cout << "���� ID: ";
    cin >> account[accNum].accID;
    cout << "�̸�: ";
    cin >> account[accNum].cusName;
    cout << "�Աݾ�: ";
    cin >> account[accNum].balance;

    accNum++;
}

void DepositMoney(void)
{
    int id;
    int money;

    cout << endl;
    cout << "[�Ա�]" << endl;
    cout << "���� ID: ";
    cin >> id;

    for (int i = 0; i < accNum; i++)
    {
        if (account[i].accID == id)
        {
            cout << "�Աݾ�: ";
            cin >> money;
            account[i].balance += money;
            cout << "�Ա� �Ϸ�: " << endl;
            return;
        }
    }
    cout << "�߸��� ���� ��ȣ �Է�. " << endl;
}

void WithdrawMoney(void)
{
    int id;
    int money;

    cout << endl;
    cout << "[���]" << endl;
    cout << "���� ID: ";
    cin >> id;

    for (int i = 0; i < accNum; i++)
    {
        if (account[i].accID == id)
        {
            cout << "��ݾ�: ";
            cin >> money;
            if (account[i].balance < money)
            {
                cout << "�ܾ� ����." << endl;
                return;
            }
            else
            {
                account[i].balance -= money;
                cout << "��� �Ϸ�: " << endl;
                return;
            }
        }
    }
    cout << "�߸��� ���� ��ȣ �Է�. " << endl;
}

void ShowAllAccInfo(void)
{
    cout << endl;
    cout << "[���� ����]" << endl;

    for (int i = 0; i < accNum; i++)
    {
        cout << "���� ID: " << account[i].accID << endl;
        cout << "�̸� : " << account[i].cusName << endl;
        cout << "�ܾ�: " << account[i].balance << endl;
        cout << endl;
    }
}
