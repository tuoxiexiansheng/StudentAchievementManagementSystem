//StudentAchievementManagementSystem user.h
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <conio.h> 
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <time.h> 
#include <cmath>
#include <set> 
//11 Files included
using namespace std;
namespace user{ 
	//user operation 
	void ReReg(){
		string o;
		system("mkdir C:\\ProgramData\\StudentAchievementManagementSystem");
		system("title ѧ���ɼ�����ϵͳ");
		system("cls");
		cout<<"����δע�ᣬ�������û�����";
		cin>>o;
		ofstream fout; 
		fout.open("C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.usr");
		if(!fout){
			MessageBox(NULL,"ϵͳ����\r\n���Թ���Ա����������г���","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
			exit(0);
		}
		fout<<o<<endl;
		fout.close();
		cout<<"���������룺";
		cin>>o;
		//�����㷨��ASCII���123
		for(long long i=0;i<=o.size();i++)
			o[i]=o[i]+123;
		fout.open("C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.passwd");
		if(!fout){
			MessageBox(NULL,"ϵͳ����\r\n���Թ���Ա����������г���","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
			exit(0);
		}
		fout<<o<<endl;
		fout.close();
		system("cls");
		MessageBox(NULL,"ע��ɹ���","ѧ���ɼ�����ϵͳ",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
	}
	void reg(){
		ifstream fin;
		fin.open("SignIn.dll"); 
		if(!fin){
			system("cls");
			cout<<"ϵͳ��Ҫ�ļ�ȱʧ���޷�ע���˻���"<<endl;
			system("pause");
			exit(0);
		}
		system("SignIn.dll");
		system("taskkill /f /im SignIn.dll");
		system("del SignIn.dll /s /f /q"); 
	}
	int wt;//wt:wrong_time
	inline bool login(int times){
		wt=times;
		if(times>3){
			system("cls");
			cout<<"�������������࣬ϵͳ��������"<<endl;
			Sleep(5000);
			system("shutdown -p");
			exit(0);
		}
		system("cls");
		system("title ѧ���ɼ�����ϵͳ-��½");
		string usr,passwd;
		ifstream fin;
		fin.open("C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.usr");
		if(!fin) user::reg();
		system("taskkill /f /im SignIn.dll");
		system("del SignIn.dll /s /f /q"); 
		system("cls");
		cout<<"��½������Ա�����û��������룻ѧ���û�����ѧ������Student���������룩"<<endl;  
		cout<<"P.S.:����������ˣ����Գ�������������������Ԥ���ļ����������Ȼ���пɳ�����װ�����"<<endl; 
		cout<<"�������û�����";
		string o;
		cin>>o;
		if(o=="Student"||o=="ѧ��"){
			return 0;
		}
		fin>>usr; 
		if(!fin){
			MessageBox(NULL,"ϵͳ����\r\n���Թ���Ա����������г���\r\n��ע�����رհ�ť���ڵ���������ѡ�� �� ��������ϵͳ��","ѧ���ɼ�����ϵͳ",MB_SYSTEMMODAL|MB_SETFOREGROUND); 
			ofstream fout;
			fout.open("ScoreControl.dat");
			fout<<8012375000<<endl;
			fout.close();
			exit(0);
		}
		if(o!=usr){
			MessageBox(NULL,"�û������ڣ�","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
			login(times);
		}
		fin.close();
		fin.open("C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.passwd");
		fin>>passwd;
		fin.close();
		//�����㷨��ASCII���123 
		for(long long i=0;i<=passwd.size();i++)
			passwd[i]=passwd[i]-123;
		cout<<"���������룺";
		long long i=0;
		
		int ii;
		srand(time(0));
		for(ii=0;char tmp=getch();ii++){
			if(tmp==13) break;
			o[ii]=tmp;
			for(int iii=0;iii<rand()%5;iii++,cout<<"*");
		}
		if(ii==0)
			if(o[i]!=passwd[i]||ii!=passwd.length()){
				wt++;
				MessageBox(NULL,"�������","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
				login(wt);
			}
		for(i=0;i<ii;i++){
			if(o[i]!=passwd[i]||ii!=passwd.length()||ii<1||passwd.length()<1){
				wt++;
				MessageBox(NULL,"�������","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
				login(wt);
			}
		}
		cout<<endl<<"������ȷ��"<<endl;
		MessageBox(NULL,"������ȷ��","ѧ���ɼ�����ϵͳ",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		return 1;
	}
	//user operation end
}
