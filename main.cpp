#include "main.h"


class Workstation
{
public:
    Work oper;
    void show(){
        cout << "0. �˳��������" << endl;
        cout << "1. ����ְ����Ϣ" << endl;
        cout << "2. ��ʾְ����Ϣ" << endl;
        cout << "3. ɾ����ְְ��" << endl;
        cout << "4. �޸�ְ����Ϣ" << endl;
        cout << "5. ����ְ����Ϣ" << endl;
        cout << "6. ��������ĵ�" << endl;
    }
    void work(){
        int choose;
        while (true){
            show();
            cout << "������ѡ��";
            cin >> choose;
            if (choose > 7) {
                cout << "*****�������*****" << endl;
                cout << "���������룺";
                cin >> choose;
            }
            switch(choose){
                case 0:
                    oper.Quit();
                    break;
                case 1:
                    if(oper.Add() == 1)
                        cout << "*****��ӳɹ�*****" << endl;
                    break;
                case 2:
                    oper.Show();
                    break;
                case 3:
                    if(oper.Delete() == 1)
                        cout << "*****ɾ���ɹ�*****" << endl;
                    break;
                case 4:
                    if(oper.Modify() == 1)
                        cout << "*****�޸ĳɹ�*****" << endl;
                    break;
                case 5:
                    if(oper.Seach() == 1)
                        cout << "*****�����ɹ�*****" << endl;
                    break;
                case 6:
                    if(oper.Empty() == 1)
                        cout << "*****��ճɹ�*****" << endl;
                    break;
            }
        }
    }
};

int main()
{
    Workstation station;
    cout << "*****ְ����Ϣ����ϵͳ*****" << endl;
    station.work();

    return 0;
}