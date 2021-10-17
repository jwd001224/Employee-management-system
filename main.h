//
// Created by 27252 on 2021-10-17.
//

#ifndef EMPLOYEE_MANAGEMENT_SYSTEM_MAIN_H
#define EMPLOYEE_MANAGEMENT_SYSTEM_MAIN_H

#include <iostream>
#include <string>
#include <fstream>
#define max 100
using namespace std;

class Base;
class Boss;
class Manager;
class Staff;
struct Work;

const string path_boss = "E:/CandC++/C++project/Employee management system/boss.txt";
const string path_manager = "E:/CandC++/C++project/Employee management system/manager.txt";
const string path_staff = "E:/CandC++/C++project/Employee management system/staff.txt";

class Base
{
    friend struct Work;
    friend int Ofs(_Ios_Openmode way,Base *base,string path,int num);
public:
    virtual void get() = 0;
protected:
    string name;
    string position;
    string number;
    string work;
};
class Boss:public Base
{
public:void get(){cout << "��� " << this->number << " \t���� " << this->name << " \tְλ" << this->position << " \t����" << this->work << endl;}
};
class Manager:public Base
{
public:void get(){cout << "��� " << this->number << " \t���� " << this->name << " \tְλ" << this->position << " \t����" << this->work << endl;}
};
class Staff:public Base
{
public:void get(){cout << "��� " << this->number << " \t���� " << this->name << " \tְλ" << this->position << " \t����" << this->work << endl;}
};

typedef struct{
    int boss_num = 0;
    int manager_num = 0;
    int staff_num = 0;
}Num;

class Work{
public:
    Num num;
    int Quit(){
        cout << "*****�˳�ϵͳ��*****" << endl;
        cout << "*****��ӭ�´�ʹ��*****" << endl;
        system("pause");
        exit(0);
    }
    int Add(){
        int choose;
        cout << "1.����ϰ�" << endl;
        cout << "2.��Ӿ���" << endl;
        cout << "3.���Ա��" << endl;
        cout << "������ѡ��";
        cin >> choose;
        if(choose == 1) {
            cout << "������������";
            cin >> (boss+num.boss_num)->name;
            cout << "�������ţ�";
            cin >> (boss+num.boss_num)->number;
            cout << "������ְλ��";
            cin >> (boss+num.boss_num)->position;
            cout << "�����빤����";
            cin >> (boss+num.boss_num)->work;

            num.boss_num++;
            Ofs(ios::trunc,boss,path_boss,num.boss_num);
        } else if (choose == 2) {
            cout << "������������";
            cin >> (manager+num.manager_num)->name;
            cout << "�������ţ�";
            cin >> (manager+num.manager_num)->number;
            cout << "������ְλ��";
            cin >> (manager+num.manager_num)->position;
            cout << "�����빤����";
            cin >> (manager+num.manager_num)->work;
            num.manager_num++;
            Ofs(ios::trunc,manager,path_manager,num.manager_num);
        } else {
            cout << "������������";
            cin >> (staff + num.staff_num)->name;
            cout << "�������ţ�";
            cin >> (staff + num.staff_num)->number;
            cout << "������ְλ��";
            cin >> (staff + num.staff_num)->position;
            cout << "�����빤����";
            cin >> (staff + num.staff_num)->work;
            num.staff_num++;
            Ofs(ios::trunc,staff,path_staff,num.staff_num);
        }
        return 1;
    }
    int Show(){
        int choose;
        cout << "1.��ʾ�ϰ�" << endl;
        cout << "2.��ʾ����" << endl;
        cout << "3.��ʾԱ��" << endl;
        cout << "������ѡ��";
        cin >> choose;
        if(choose == 1) {
            if(num.boss_num == 0) cout << "*****�б�Ϊ��*****" << endl;
            for(int i = 0;i < num.boss_num;i++)
                (boss+i)->get();
        } else if (choose == 2) {
            if(num.manager_num == 0) cout << "*****�б�Ϊ��*****" << endl;
            for(int i = 0;i < num.manager_num;i++)
                (manager+i)->get();
        } else
        if(num.staff_num == 0) cout << "*****�б�Ϊ��*****" << endl;
        for(int i = 0;i < num.staff_num;i++)
            (staff+i)->get();
        return 1;
    }
    int Delete(){
        int choose;
        cout << "1.ɾ���ϰ�" << endl;
        cout << "2.ɾ������" << endl;
        cout << "3.ɾ��Ա��" << endl;
        cout << "������ѡ��";
        cin >> choose;
        string n;
        cout << "������Ҫɾ����ְ����Ż�������";
        cin >> n;
        if(choose == 1) {
            if(num.boss_num == 0) cout << "*****�б�Ϊ��*****" << endl;
            for(int i = 0;i < num.boss_num;i++){
                if((boss+i)->name == n || (boss+i)->number == n){
                    for(int j = i;j < num.boss_num;j++){
                        *(boss+j) = *(boss+j+1);
                    }
                }
            }
            num.boss_num--;
            Ofs(ios::trunc,boss,path_boss,num.boss_num);
        } else if (choose == 2) {
            if(num.manager_num == 0) cout << "*****�б�Ϊ��*****" << endl;
            for(int i = 0;i < num.manager_num;i++){
                if((manager+i)->name == n || (manager+i)->number == n){
                    for(int j = i;j < num.manager_num;j++){
                        *(manager+j) = *(manager+j+1);
                    }
                }
            }
            num.manager_num--;
            Ofs(ios::trunc, manager, path_manager, num.manager_num);
        } else {
            if (num.staff_num == 0) cout << "*****�б�Ϊ��*****" << endl;
            for (int i = 0; i < num.staff_num; i++) {
                if ((staff + i)->name == n || (staff + i)->number == n) {
                    for (int j = i; j < num.staff_num; j++) {
                        *(staff + j) = *(staff + j + 1);
                    }
                }
            }
            num.staff_num--;
            Ofs(ios::trunc, staff, path_staff, num.staff_num);
        }
        return 1;
    }
    int Modify() {
        int choose;
        cout << "1.�޸��ϰ�" << endl;
        cout << "2.�޸ľ���" << endl;
        cout << "3.�޸�Ա��" << endl;
        cout << "������ѡ��";
        cin >> choose;

        string name;
        cout << "������Ҫ�޸ĵ�ְ����Ż�������";
        cin >> name;

        int n;
        cout << "1.�޸ı��" << endl;
        cout << "2.�޸�ְλ" << endl;
        cout << "3.�޸Ĺ���" << endl;
        cout << "������ѡ��";
        cin >> n;

        if(choose == 1) {
            if(num.boss_num == 0) cout << "*****�б�Ϊ��*****" << endl;
            for(int i = 0;i < num.boss_num;i++) {
                if ((boss + i)->name == name) {
                    switch(n){
                        case 1: {
                            string number;
                            cout << "�������±��";
                            cin >> number;
                            (boss + i)->number = number;
                            break;
                        }
                        case 2: {
                            string position;
                            cout << "��������ְλ";
                            cin >> position;
                            (boss + i)->position = position;
                            break;
                        }
                        case 3: {
                            string work;
                            cout << "�������¹���";
                            cin >> work;
                            (boss + i)->work = work;
                            break;
                        }
                    }
                }
            }
            Ofs(ios::trunc,boss,path_boss,num.boss_num);
        } else if (choose == 2) {
            if(num.manager_num == 0) cout << "*****�б�Ϊ��*****" << endl;
            for(int i = 0;i < num.manager_num;i++) {
                if ((manager + i)->name == name) {
                    switch(n){
                        case 1: {
                            string number;
                            cout << "�������±��";
                            cin >> number;
                            (manager + i)->number = number;
                            break;
                        }
                        case 2: {
                            string position;
                            cout << "��������ְλ";
                            cin >> position;
                            (manager + i)->position = position;
                            break;
                        }
                        case 3: {
                            string work;
                            cout << "�������¹���";
                            cin >> work;
                            (manager + i)->work = work;
                            break;
                        }
                    }
                }
            }
            Ofs(ios::trunc,manager,path_manager,num.manager_num);
        } else {
            if (num.staff_num == 0) cout << "*****�б�Ϊ��*****" << endl;
            for(int i = 0;i < num.staff_num;i++) {
                if ((staff + i)->name == name) {
                    switch(n){
                        case 1: {
                            string number;
                            cout << "�������±��";
                            cin >> number;
                            (staff + i)->number = number;
                            break;
                        }
                        case 2: {
                            string position;
                            cout << "��������ְλ";
                            cin >> position;
                            (staff + i)->position = position;
                            break;
                        }
                        case 3: {
                            string work;
                            cout << "�������¹���";
                            cin >> work;
                            (staff + i)->work = work;
                            break;
                        }
                    }
                }
            }
            Ofs(ios::trunc,staff,path_staff,num.staff_num);
        }
        return 1;
    }
    int Seach(){
        int choose;
        cout << "1.�����ϰ�" << endl;
        cout << "2.��������" << endl;
        cout << "3.����Ա��" << endl;
        cout << "������ѡ��";
        cin >> choose;

        string name_or_number;
        cout << "������Ҫ������ְ����Ż�������";
        cin >> name_or_number;

        if(choose == 1) {
            if(num.boss_num == 0) cout << "*****�б�Ϊ��*****" << endl;
            for(int i = 0;i < num.boss_num;i++) {
                if ((boss + i)->name == name_or_number || (boss + i)->number == name_or_number) {
                    (boss + i)->get();
                }
            }
        } else if (choose == 2) {
            if(num.manager_num == 0) cout << "*****�б�Ϊ��*****" << endl;
            for(int i = 0;i < num.manager_num;i++) {
                if ((manager + i)->name == name_or_number || (manager + i)->number == name_or_number) {
                    (manager + i)->get();
                }
            }
        } else {
            if (num.staff_num == 0) cout << "*****�б�Ϊ��*****" << endl;
            for(int i = 0;i < num.staff_num;i++) {
                if ((staff + i)->name == name_or_number || (staff + i)->number == name_or_number) {
                    (staff + i)->get();
                }
            }
        }
        return 1;
    }
    int Empty() {
        cout << "*****ȷ�����ְ�����ݣ�*****" << endl;
        cout << "1.ȷ��" << endl;
        cout << "2.ȡ��" << endl;
        int choose;
        cout << "������ѡ��";
        cin >> choose;
        if(choose == 1)
        {
            Ofs(ios::trunc,boss,path_boss,0);
            Ofs(ios::trunc,manager,path_manager,0);
            Ofs(ios::trunc,staff,path_staff,0);

            delete[] boss;
            boss = NULL;
            delete[] manager;
            manager = NULL;
            delete[] staff;
            staff = NULL;

            num.boss_num = 0;
            num.manager_num = 0;
            num.staff_num = 0;
        } else
            cout << "*****ȡ������*****" << endl;
        return 1;
    }
protected:
    Base *boss = new Boss[max];
    Base *manager = new Manager[max];
    Base *staff = new Staff[max];
};

int Ofs(_Ios_Openmode way,Base *base,string path,int num){
    ofstream ofs;
    ofs.open(path,way);
    for(int i = 0;i < num;i++)
    {
        ofs << "��� " << (base+i)->number << " \t���� " << (base+i)->name << " \tְλ" << (base+i)->position << " \t����" << (base+i)->work << endl;
    }
    ofs.close();
    return 1;
}


#endif //EMPLOYEE_MANAGEMENT_SYSTEM_MAIN_H
