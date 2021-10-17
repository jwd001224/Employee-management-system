#include "main.h"


class Workstation
{
public:
    Work oper;
    void show(){
        cout << "0. 退出管理程序" << endl;
        cout << "1. 增加职工信息" << endl;
        cout << "2. 显示职工信息" << endl;
        cout << "3. 删除离职职工" << endl;
        cout << "4. 修改职工信息" << endl;
        cout << "5. 查找职工信息" << endl;
        cout << "6. 清空所有文档" << endl;
    }
    void work(){
        int choose;
        while (true){
            show();
            cout << "请输入选择：";
            cin >> choose;
            if (choose > 7) {
                cout << "*****输入错误！*****" << endl;
                cout << "请重新输入：";
                cin >> choose;
            }
            switch(choose){
                case 0:
                    oper.Quit();
                    break;
                case 1:
                    if(oper.Add() == 1)
                        cout << "*****添加成功*****" << endl;
                    break;
                case 2:
                    oper.Show();
                    break;
                case 3:
                    if(oper.Delete() == 1)
                        cout << "*****删除成功*****" << endl;
                    break;
                case 4:
                    if(oper.Modify() == 1)
                        cout << "*****修改成功*****" << endl;
                    break;
                case 5:
                    if(oper.Seach() == 1)
                        cout << "*****搜索成功*****" << endl;
                    break;
                case 6:
                    if(oper.Empty() == 1)
                        cout << "*****清空成功*****" << endl;
                    break;
            }
        }
    }
};

int main()
{
    Workstation station;
    cout << "*****职工信息管理系统*****" << endl;
    station.work();

    return 0;
}