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
public:void get(){cout << "编号 " << this->number << " \t姓名 " << this->name << " \t职位" << this->position << " \t工作" << this->work << endl;}
};
class Manager:public Base
{
public:void get(){cout << "编号 " << this->number << " \t姓名 " << this->name << " \t职位" << this->position << " \t工作" << this->work << endl;}
};
class Staff:public Base
{
public:void get(){cout << "编号 " << this->number << " \t姓名 " << this->name << " \t职位" << this->position << " \t工作" << this->work << endl;}
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
        cout << "*****退出系统！*****" << endl;
        cout << "*****欢迎下次使用*****" << endl;
        system("pause");
        exit(0);
    }
    int Add(){
        int choose;
        cout << "1.添加老板" << endl;
        cout << "2.添加经理" << endl;
        cout << "3.添加员工" << endl;
        cout << "请输入选择：";
        cin >> choose;
        if(choose == 1) {
            cout << "请输入姓名：";
            cin >> (boss+num.boss_num)->name;
            cout << "请输入编号：";
            cin >> (boss+num.boss_num)->number;
            cout << "请输入职位：";
            cin >> (boss+num.boss_num)->position;
            cout << "请输入工作：";
            cin >> (boss+num.boss_num)->work;

            num.boss_num++;
            Ofs(ios::trunc,boss,path_boss,num.boss_num);
        } else if (choose == 2) {
            cout << "请输入姓名：";
            cin >> (manager+num.manager_num)->name;
            cout << "请输入编号：";
            cin >> (manager+num.manager_num)->number;
            cout << "请输入职位：";
            cin >> (manager+num.manager_num)->position;
            cout << "请输入工作：";
            cin >> (manager+num.manager_num)->work;
            num.manager_num++;
            Ofs(ios::trunc,manager,path_manager,num.manager_num);
        } else {
            cout << "请输入姓名：";
            cin >> (staff + num.staff_num)->name;
            cout << "请输入编号：";
            cin >> (staff + num.staff_num)->number;
            cout << "请输入职位：";
            cin >> (staff + num.staff_num)->position;
            cout << "请输入工作：";
            cin >> (staff + num.staff_num)->work;
            num.staff_num++;
            Ofs(ios::trunc,staff,path_staff,num.staff_num);
        }
        return 1;
    }
    int Show(){
        int choose;
        cout << "1.显示老板" << endl;
        cout << "2.显示经理" << endl;
        cout << "3.显示员工" << endl;
        cout << "请输入选择：";
        cin >> choose;
        if(choose == 1) {
            if(num.boss_num == 0) cout << "*****列表为空*****" << endl;
            for(int i = 0;i < num.boss_num;i++)
                (boss+i)->get();
        } else if (choose == 2) {
            if(num.manager_num == 0) cout << "*****列表为空*****" << endl;
            for(int i = 0;i < num.manager_num;i++)
                (manager+i)->get();
        } else
        if(num.staff_num == 0) cout << "*****列表为空*****" << endl;
        for(int i = 0;i < num.staff_num;i++)
            (staff+i)->get();
        return 1;
    }
    int Delete(){
        int choose;
        cout << "1.删除老板" << endl;
        cout << "2.删除经理" << endl;
        cout << "3.删除员工" << endl;
        cout << "请输入选择：";
        cin >> choose;
        string n;
        cout << "请输入要删除的职工编号或姓名：";
        cin >> n;
        if(choose == 1) {
            if(num.boss_num == 0) cout << "*****列表为空*****" << endl;
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
            if(num.manager_num == 0) cout << "*****列表为空*****" << endl;
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
            if (num.staff_num == 0) cout << "*****列表为空*****" << endl;
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
        cout << "1.修改老板" << endl;
        cout << "2.修改经理" << endl;
        cout << "3.修改员工" << endl;
        cout << "请输入选择：";
        cin >> choose;

        string name;
        cout << "请输入要修改的职工编号或姓名：";
        cin >> name;

        int n;
        cout << "1.修改编号" << endl;
        cout << "2.修改职位" << endl;
        cout << "3.修改工作" << endl;
        cout << "请输入选择：";
        cin >> n;

        if(choose == 1) {
            if(num.boss_num == 0) cout << "*****列表为空*****" << endl;
            for(int i = 0;i < num.boss_num;i++) {
                if ((boss + i)->name == name) {
                    switch(n){
                        case 1: {
                            string number;
                            cout << "请输入新编号";
                            cin >> number;
                            (boss + i)->number = number;
                            break;
                        }
                        case 2: {
                            string position;
                            cout << "请输入新职位";
                            cin >> position;
                            (boss + i)->position = position;
                            break;
                        }
                        case 3: {
                            string work;
                            cout << "请输入新工作";
                            cin >> work;
                            (boss + i)->work = work;
                            break;
                        }
                    }
                }
            }
            Ofs(ios::trunc,boss,path_boss,num.boss_num);
        } else if (choose == 2) {
            if(num.manager_num == 0) cout << "*****列表为空*****" << endl;
            for(int i = 0;i < num.manager_num;i++) {
                if ((manager + i)->name == name) {
                    switch(n){
                        case 1: {
                            string number;
                            cout << "请输入新编号";
                            cin >> number;
                            (manager + i)->number = number;
                            break;
                        }
                        case 2: {
                            string position;
                            cout << "请输入新职位";
                            cin >> position;
                            (manager + i)->position = position;
                            break;
                        }
                        case 3: {
                            string work;
                            cout << "请输入新工作";
                            cin >> work;
                            (manager + i)->work = work;
                            break;
                        }
                    }
                }
            }
            Ofs(ios::trunc,manager,path_manager,num.manager_num);
        } else {
            if (num.staff_num == 0) cout << "*****列表为空*****" << endl;
            for(int i = 0;i < num.staff_num;i++) {
                if ((staff + i)->name == name) {
                    switch(n){
                        case 1: {
                            string number;
                            cout << "请输入新编号";
                            cin >> number;
                            (staff + i)->number = number;
                            break;
                        }
                        case 2: {
                            string position;
                            cout << "请输入新职位";
                            cin >> position;
                            (staff + i)->position = position;
                            break;
                        }
                        case 3: {
                            string work;
                            cout << "请输入新工作";
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
        cout << "1.搜索老板" << endl;
        cout << "2.搜索经理" << endl;
        cout << "3.搜索员工" << endl;
        cout << "请输入选择：";
        cin >> choose;

        string name_or_number;
        cout << "请输入要搜索的职工编号或姓名：";
        cin >> name_or_number;

        if(choose == 1) {
            if(num.boss_num == 0) cout << "*****列表为空*****" << endl;
            for(int i = 0;i < num.boss_num;i++) {
                if ((boss + i)->name == name_or_number || (boss + i)->number == name_or_number) {
                    (boss + i)->get();
                }
            }
        } else if (choose == 2) {
            if(num.manager_num == 0) cout << "*****列表为空*****" << endl;
            for(int i = 0;i < num.manager_num;i++) {
                if ((manager + i)->name == name_or_number || (manager + i)->number == name_or_number) {
                    (manager + i)->get();
                }
            }
        } else {
            if (num.staff_num == 0) cout << "*****列表为空*****" << endl;
            for(int i = 0;i < num.staff_num;i++) {
                if ((staff + i)->name == name_or_number || (staff + i)->number == name_or_number) {
                    (staff + i)->get();
                }
            }
        }
        return 1;
    }
    int Empty() {
        cout << "*****确认清空职工数据？*****" << endl;
        cout << "1.确认" << endl;
        cout << "2.取消" << endl;
        int choose;
        cout << "请输入选择：";
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
            cout << "*****取消操作*****" << endl;
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
        ofs << "编号 " << (base+i)->number << " \t姓名 " << (base+i)->name << " \t职位" << (base+i)->position << " \t工作" << (base+i)->work << endl;
    }
    ofs.close();
    return 1;
}


#endif //EMPLOYEE_MANAGEMENT_SYSTEM_MAIN_H
