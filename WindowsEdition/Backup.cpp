//Copyright (C) 2018 XiyuWang All rights reserved.
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
ifstream fin;
ofstream fout;
int main(){
	system("cls");
	system("color f0");
	system("title 学生成绩管理系统-导入程序");
	cout<<"正在检查数据……"<<endl;
	fin.open("~Control.usr");
	if(!fin){
		system("cls");
		cout<<"缺失文件！"<<endl;
		getch();
		return 0;
	}
	fin.close();
	fin.open("~Control.passwd");
	if(!fin){
		system("cls");
		cout<<"缺失文件！"<<endl;
		getch();
		return 0;
	}
	cout<<"正在导入数据……"<<endl;
	system("copy ~Control.usr C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.usr");
	system("copy ~Control.passwd C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.passwd");
	cout<<"请自行将StudentScore.dat和ClassEdition.dat复制到主程序运行文件夹！ "<<endl;
	getch();
	cout<<"正在删除备份文件夹中的文件……"<<endl;
	system("del *.* /f/s/q");
	fout.open("del.bat");
	fout<<"taskkill /f /im Backup.exe"<<endl; 
	fout<<"del Backup.exe /f/s/q"<<endl;
	fout<<"del del.bat /f/s/q"<<endl;
	fout.close();
	system("cls");
	cout<<"完成！"<<endl;
	getch();
	system("del.bat");	
	return 0;
}
