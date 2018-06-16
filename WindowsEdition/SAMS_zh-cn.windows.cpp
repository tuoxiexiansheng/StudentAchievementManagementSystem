//Copyright (C) 2017-2018 XiyuWang All rights reserved.
//Version: 17.2.6 

//Author: XiyuWang
//Author E-mail Address: XiyuWang_Code@hotmail.com 
//GitHub Address: https://xiyuwang2006.github.io/StudentAchievementManagementSystem 

//THIS APPLICATION CAN ONLY RUN ON WINDOWS (BEST ON X64, X32 MAY HAVE SOME RUNTIME ERROR)

/* ѧ���ɼ�����ϵͳ ���ܣ�
1.¼��+����+ɾ�� ѧ����Ϣ 
2.�ļ� ����+���
3.���� ��ѯ��ʽ
4.�ɸ��� �û���Ϣ
5.������ϵͳ  
6.�༶ģʽ 
�����Ƴ�������ɾ����Ϣ 
���๦�ܣ������ڴ��� 
*/

#include "include.h"
using namespace std;

BOOL CtrlHandler(DWORD fdwCtrlType);
bool ROSid=1,ROSname=1,ROSnum=1;
long long i,j,n,ti;
int menl,midl,mnl;//menl:max exam_name length	midl:max id length	mnl:max name length
string o;//o:order
long long ScoreControl,ScoreControlFI;//FI:FileInput 

time_t tt = time(NULL);
tm* t=localtime(&tt);

struct student{
	double S;//S:Score
	string name,id,exam_name;
};
student z;
struct cmp_ss/*ss:student score*/{
	bool operator()(const student&x,const student&y)const{
		if(x.exam_name<y.exam_name) return 1;
		if(x.exam_name>y.exam_name) return 0;
		if(x.S>y.S) return 1;
		if(x.S<y.S) return 0;
		if(x.id<y.id) return 1;
		if(x.id>y.id) return 0;
		return 0;
	}
};
set<student,cmp_ss> stu;
set<student,cmp_ss>::iterator it;

struct student_info{
	string name,id;
};
student_info zz;
struct cmp_si/*si:student info*/{
	bool operator()(const student_info&x,const student_info&y)const{
		if(x.id>y.id) return 0;
		if(x.id<y.id) return 1;
		return 0;
	}
};
set<student_info,cmp_si> stuinfo;
set<student_info,cmp_si>::iterator siit;//student info iterator

int max(int a,int b){
	if(a>b) return a;
	return b;
}

bool adminCheck(){
	ofstream fout;
	fout.open("AdminAccess.txt");
	if(!fout) return 0;
	fout<<"SAMS has alreay gotten the admin access!"<<endl;
	fout<<"This file will be deleted by SAMS program in 1 minute!"<<endl;
	fout.close();
	system("del AdminAccess.txt /f/q");
	return 1;
}

bool DriverCheck(){
	ofstream fout;
	fout.open("D:\\DriverExist.txt");
	if(!fout) return 0;
	fout<<"SAMS is checking if Drive 'D:' exists!"<<endl;
	fout<<"Result: Exist!"<<endl;
	fout<<"This file will be deleted by SAMS program in 1 minute!"<<endl;
	fout.close();
	system("del D:\\DriverExist.txt /f/q");
	return 1;
}

bool ACTIVATION(){
	string code;
	ifstream fin;
	fin.open("Activation.dat");
	getline(fin,code);
	if(!fin||code!="SYSTEM ACTIVATED! ALLOWED TO RUN ON THIS COMPUTER! CODE:ck~.jj=T5Nif%h![utA#P[xvbQWH#-=c"){
		MessageBox(NULL,"ϵͳ��δ����밴ȷ����ǰ�����","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
		system("Activation.dll");
		exit(0);
	}
}

void start(int len){
	srand(time(0));
	string key,ans;
	system("cls");
	system("title ѧ���ɼ�����ϵͳ");
	cout<<"��֤�룺"; 
	for(i=0;i<len;i++){
		key[i]=char(65+rand()%(65-122+1));
		cout<<key[i];
	}	
	cout<<endl<<"��������֤�룺";
	cin>>ans;
	for(i=0;i<len;i++)
		if(ans[i]!=key[i]) start(len+1);
	cout<<"��֤����ȷ��"<<endl; 
}

void load(){
	system("cls");
	system("title ѧ���ɼ�����ϵͳ-������......");
	cout<<"Copyright (C) 2017-2018 XiyuWang All rights reserved."<<endl;
	cout<<"Version:17.2.6"<<endl; 
	cout<<"ע�⣺������������ʱ������ӿո񣬷���ϵͳ�����"<<endl; 
	cout<<"С��ʾ�������԰� Ctrl+Z ֹͣ�������ݣ�"<<endl; 
	cout<<"������......"<<endl; 
	for(i=1;i<=10;i++){
		cout<<"��";
		Sleep(188);
	}
	system("title ѧ���ɼ�����ϵͳ"); 
}

void hit(){
	system("cls");
	system("title ѧ���ɼ�����ϵͳ"); 
	cout<<"�ף�Windows10ϵͳ���԰� F11 ȫ�����������Ч��Ŷ��"<<endl;
	Sleep(2000);
}

namespace ClassEdition{
	//Class Edition
	int reg(){
		string classname,passwd,name,id;
		int n;
		ifstream fin;
		fin.open("ClassEdition.dat");
		fin>>classname>>passwd>>n;
		ofstream fout;
		fout.open("ClassEdition.dat");
		if(!fout){
			cout<<"ϵͳ�����볢������ϵͳ��"<<endl;
			system("pause");
			return 1;
		}
		system("cls");
		cout<<"�������°༶���ƣ�";
		cin>>classname;
		//�����㷨 
		for(i=0;i<classname.length();i++)
			classname[i]+=18;
		cout<<"�������°༶����Ա���룺";
		cin>>passwd;
		//�����㷨 
		for(i=0;i<passwd.length();i++)
			passwd[i]+=18;
		fout<<classname<<" "<<passwd<<" "<<n<<endl;
		for(i=1;i<=n;i++){
			fin>>name>>id;
			fout<<name<<" "<<id<<endl;
		}
		system("cls");
	} 
	int make(){
		ofstream fout;
		fout.open("ClassEdition.dat");
		if(!fout){
			cout<<"ϵͳ�����볢������ϵͳ��"<<endl;
			system("pause");
			return 1;
		}
		string classname,passwd;
		int n;
		system("cls");
		cout<<"������༶���ƣ�";
		cin>>classname;
		//�����㷨 
		for(i=0;i<classname.length();i++)
			classname[i]+=18;
		cout<<"������༶����Ա���룺";
		cin>>passwd;
		//�����㷨 
		for(i=0;i<passwd.length();i++)
			passwd[i]+=18;
		system("cls");
		cout<<"������༶������";
		cin>>n;
		if(n+stu.size()>=10000){
			cout<<"�༶�������࣡"<<endl;
			system("pause");
			return 1;
		}
		fout<<classname<<" "<<passwd<<" "<<n<<endl; 
		for(i=1;i<=n;i++){
			system("cls");
			cout<<"���������"<<i<<"��ѧ������Ϣ����"<<n<<"��......"<<endl;
			cout<<"������ѧ��ѧ�ţ�"; 
			cin>>zz.id;
			cout<<"������ѧ��������";
			cin>>zz.name;
			stuinfo.insert(zz);
			for(j=0;j<zz.id.length();j++)
				zz.id[j]+=10;
			for(j=0;j<zz.name.length();j++)
				zz.name[j]+=10;
			fout<<zz.name<<" "<<zz.id<<endl;
		}
		fout.close();
		system("cls");
		cout<<"�༶������ɣ�"<<endl;
		system("pause");
	}
	int main(){
		system("cls");
		string clssnm,pwd,classname,passwd;
		int n=0;
		ifstream fin;
		fin.open("ClassEdition.dat");
		fin>>clssnm>>passwd>>n;
		for(i=0;i<clssnm.length();i++)
			clssnm[i]-=18;
		for(i=0;i<passwd.length();i++)
			passwd[i]-=18;
		cout<<"�༶ģʽ-��½"<<endl; 
		cout<<"�༶���ƣ�"<<clssnm<<endl;
		cout<<"���룺";
		int ii;
		srand(time(0));
		for(ii=0;char tmp=getch();ii++){
			if(tmp==13) break;
			o[ii]=tmp;
			for(int iii=0;iii<rand()%5;iii++,cout<<"*");
		}
		for(i=0;i<ii;i++){
			if(o[i]!=passwd[i]||ii!=passwd.length()){
				MessageBox(NULL,"�������","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
				return 1;
			}
		}
		system("cls");
		cout<<"�����뿼�����ƣ�";
		cin>>z.exam_name; 
		for(i=1;i<=n;i++){
			fin>>zz.name>>zz.id;
			for(j=0;j<zz.id.length();j++)
				zz.id[j]-=10;
			for(j=0;j<zz.name.length();j++)
				zz.name[j]-=10;
			stuinfo.insert(zz);
		}
		for(siit=stuinfo.begin(),i=1;siit!=stuinfo.end();siit++,i++){
			system("cls");
			cout<<"�������� "<<clssnm<<" �е�"<<i<<"��ѧ���ĳɼ�����"<<n<<"��......"<<endl; 
			z.id=siit->id;
			z.name=siit->name;
			cout<<"ѧ�ţ�"<<z.id<<endl;
			cout<<"������"<<z.name<<endl;
			cout<<"�������ƣ�"<<z.exam_name<<endl;
			string tmp; 
			inputScore:
			cout<<"������ɼ���";
			cin>>tmp;
			for(int iii=0;iii<tmp.size();iii++)
				if((tmp[iii]<'0'||tmp[iii]>'9')&&tmp[iii]!='.'){
					system("cls");
					cout<<endl<<"�ɼ����Ϸ������������룡"<<endl; 
					system("pause");
					system("cls");
					goto inputScore;
				}
			z.S=atof(tmp.c_str());
			for(it=stu.begin();it!=stu.end();it++)
				if(it->id==z.id&&it->name==z.name&&it->exam_name==z.exam_name){
					ef:
					system("cls");
					cout<<"ѧ�ţ�"<<it->id<<endl;
					cout<<"������"<<it->name<<endl;
					cout<<"�������ƣ�"<<it->exam_name<<endl; 
					cout<<"���سɼ���"<<fixed<<setprecision(0)<<it->S<<endl; 
					cout<<"����ɼ���"<<tmp<<endl; 
					cout<<"���󣺸�ѧ����Ϣ�Ѵ��ڣ�"<<endl;
					cout<<"================================="<<endl;
					cout<<"1.���汾����Ϣ     2.����������Ϣ"<<endl; 
					cin>>o;
					if(o[0]=='1') z.S=it->S;
					if(o[0]!='1'&&o[0]!='2') goto ef;
					break;  
				}
			if(z.S>ScoreControl+0.999999){
				system("cls");
				cout<<"�ɼ�����������ƣ�"<<endl;
				getch();
				goto inputScore; 
			}
			else stu.insert(z);
		}
		system("cls");
		cout<<"�༶ģʽ����¼�������"<<endl;
		system("pause"); 
	}
	//Class Edition
}

namespace file{
	//file operation
	int output(bool save){
		double Average,All;
		ofstream fout;
		system("cls");
		z.exam_name=' ';
		fout.open("StudentScore.dat"); 
		if(!fout)
			MessageBox(NULL,"����\r\n�޷�������������ļ������鱾ϵͳ�Ƿ��Ѿ���ù���ԱȨ�ޣ�","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		else{	
			fout<<"17.2.6"<<endl;
			fout<<stu.size()<<endl;
			for(it=stu.begin(),i=1;it!=stu.end();it++,i++){
				z.exam_name=it->exam_name;
				for(int i=0;i<=z.exam_name.size();i++)
					z.exam_name[i]=z.exam_name[i]+1;
				z.name=it->name;
				for(int i=0;i<=z.name.size();i++)
					z.name[i]=z.name[i]+2;
				z.id=it->id;
				for(int i=0;i<=z.id.size();i++)
					z.id[i]=z.id[i]+3;
				z.S=it->S;
				fout<<z.exam_name<<" "<<z.name<<" "<<z.id<<" "<<char(((int) z.S)+5)<<" ";
			}
			fout.close();
		}
		fout.open("D:\\ѧ���ɼ���Ϣ.csv",ios::out|ios::trunc); 
		if(!fout)
			MessageBox(NULL,"����\r\n�޷�����Excel����ļ�������������D��D�̣��Ƿ���ڣ�","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		else{ 
			if(stu.size()==0) fout<<"���޼�¼��"<<endl;
			else{
				fout<<"����"<<","<<"ѧ��"<<","<<"�ɼ�"<<","<<"����"<<","<<"��������"<<endl;
				for(it=stu.begin(),i=1;it!=stu.end();it++,i++){
					if(z.exam_name!=it->exam_name&&i!=1){
						Average=All/(i-1);
						All=0;
						i=1;
						fout<<"ƽ���֣�"<<Average<<endl;
						fout<<endl;
					}
					if(i<10) fout<<i<<"   "<<","<<"";
					if(i>=10&&i<100) fout<<i<<"  "<<","<<"";
					if(i>=100&&i<1000) fout<<i<<" "<<","<<"";
					if(i>=1000&&i<10000) fout<<i<<""<<","<<"";
			 		if(i>=10000&&i<100000) fout<<i<<"|";
					if((it->id).length()==1) fout<<it->id<<"   "<<","<<" ";
					if((it->id).length()==2) fout<<it->id<<"  "<<","<<" ";
					if((it->id).length()==3) fout<<it->id<<" "<<","<<" ";
					if((it->id).length()==4) fout<<it->id<<""<<","<<" ";
					fout<<" "<<","<<" "<<it->name<<" "<<","<<" "<<it->exam_name<<endl;
					fout<<setprecision(0)<<fixed<<it->S;
					z.exam_name=it->exam_name;
					All+=it->S; 
				}
			Average=All/(i-1);
			fout<<"ƽ���֣�"<<Average<<endl;
			}
			fout.close();
		}
		if(!save&&fout){
			cout<<"��ɣ���ر�Ԥ�����ڣ�Excel��񴰿ڣ��������"<<endl;
			system("D:\\ѧ���ɼ���Ϣ.csv");
			system("pause");
		}
	}
	int input(bool w){
		bool found;
		system("cls");
		unsigned long long int num;
		string version;
		ifstream fin;
		fin.open("StudentScore.dat"); 
		if(!fin&&!w){
			MessageBox(NULL,"�ļ�\"StudentScore.dat\"�����ڣ�","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND);
			return 1;
		}
		if(!fin&&w) return 1; 
		fin>>version>>num;
		if(version!="17.2.6"&&!w){
			cout<<"�ļ��汾��ϵͳ�������޷�¼����Ϣ��"<<endl;
			cout<<"�ļ��汾��"<<version<<endl; 
			cout<<"ϵͳ�汾��17.2.6"<<endl;
			cout<<"���ְ汾���ļ�֧��ʹ���޸�����ת�룡"<<endl; 
			system("pause");
			return 1;
		}
		if(version!="17.2.6"&&w) return 1;
		if((num+stu.size())>=10000&&!w){
			cout<<"�ļ������������޷�¼��ϵͳ��"<<endl;
			cout<<"�ļ��������� "<<num<<endl;
			cout<<"ϵͳ��ǰ��������"<<stu.size()<<endl;
			cout<<"¼�����������"<<num+stu.size()<<endl;
			cout<<"������׼��"<<num+stu.size()-10000<<endl;
			system("pause");
			return 1;
		}
		if((num+stu.size())>=10000&&w) return 1;
		for(int iiii=1;iiii<=num;iiii++){
			char Stmp;
			fin>>z.exam_name>>z.name>>z.id>>Stmp; 
			for(i=0;i<=z.exam_name.size();i++)
				z.exam_name[i]=z.exam_name[i]-1;
			menl=max(menl,z.exam_name.length());
			for(i=0;i<=z.name.size();i++)
				z.name[i]=z.name[i]-2;
			mnl=max(mnl,z.name.length());
			for(i=0;i<=z.id.size();i++)
				z.id[i]=z.id[i]-3;
			midl=max(midl,z.id.length());
			z.S=((int) Stmp)-5;
			for(it=stu.begin();it!=stu.end();it++){
				if(it->exam_name==z.exam_name&&it->name==z.name&&it->id==z.id){
					fileInputError:
					system("cls");
					cout<<"�ļ�";
					if(w) cout<<"�Զ�";
					cout<<"����ʱ������⵽��ͬѧ����Ϣ��"<<endl;
					cout<<"ѧ�ţ�"<<it->id<<endl; 
					cout<<"������"<<it->name<<endl;
					cout<<"�������ƣ�"<<it->exam_name<<endl;
					cout<<"���سɼ���"<<fixed<<setprecision(0)<<it->S<<endl;
					cout<<"�ļ��ɼ���"<<fixed<<setprecision(0)<<z.S<<endl; 
					cout<<"===================================="<<endl;
					cout<<"1.����                        2.�ļ�"<<endl; 
					cout<<"��ѡ��Ҫ��������Ϣ����ţ���"; 
					cin>>o;
					o[0]=='1'?found=true:found=false;
					if(o[0]!='1'&&o[0]!='2') goto fileInputError;
				}
			}
			if(found){
				continue;
				found=false;
			}
			if(!found) stu.insert(z);
		}
		if(!w) MessageBox(NULL,"��ɣ�","ѧ���ɼ�����ϵͳ",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND);
	}
	int backup(){
		system("mkdir D:\\StudentAchievementManagementSystem_BACKUP\\");
		system("copy C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.usr D:\\StudentAchievementManagementSystem_BACKUP\\~Control.usr");
		system("copy C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.passwd D:\\StudentAchievementManagementSystem_BACKUP\\~Control.passwd");
		system("copy StudentScore.dat D:\\StudentAchievementManagementSystem_BACKUP\\StudentScore.dat");
		system("copy ClassEdition.dat D:\\StudentAchievementManagementSystem_BACKUP\\ClassEdition.dat");
		system("copy Backup.dll D:\\StudentAchievementManagementSystem_BACKUP\\Backup.exe");
		system("cls");
		cout<<"���ݳɹ��������ļ����������ļ��С�D:\\StudentAchievementManagementSystem_BACKUP���У�"<<endl;
		cout<<"���赼����������������뽫�����ļ����ļ��У�ע�⣺ֱ�Ӹ����ļ��У����Ƶ�����һ̨�������Ȼ�� �Թ���Ա��� �����ļ����е�Backup.exe�������Զ����룬������ɺ󽫻�ɾ�������ļ���"<<endl;
		cout<<"                                                                                            ~~~~~~~~~~~~~~"<<endl;
		getch(); 
	}
	//file operation end
}

namespace record_input{ 
	//record operation (input,change,delete)
	int rinput(){
		ris: 
		o[0]=0; 
		bool found=false;
		ri:
		system("cls");
		cout<<"������ѧ�ţ�";
		cin>>z.id;
		midl=max(midl,z.id.length());
		cout<<"������������";
		cin>>z.name;
		mnl=max(mnl,z.name.length());
		cout<<"�����뿼�����ƣ�";
		cin>>z.exam_name; 
		menl=max(menl,z.exam_name.length());
		string tmp; 
		inputScore:
		cout<<"������ɼ���";
		cin>>tmp;
		for(int iii=0;iii<tmp.size();iii++)
			if((tmp[iii]<'0'||tmp[iii]>'9')&&tmp[iii]!='.'){
				system("cls");
				cout<<endl<<"�ɼ����Ϸ������������룡"<<endl; 
				system("pause");
				system("cls");
				goto inputScore;
			}
		z.S=atof(tmp.c_str());
		for(it=stu.begin();it!=stu.end();it++)
			if(it->id==z.id&&it->name==z.name&&it->exam_name==z.exam_name){
				system("cls");
				cout<<"���󣺸ü�¼�Ѵ��ڣ�"<<endl;
				cout<<"ѧ�ţ�"<<it->id<<endl;
				cout<<"������"<<it->name<<endl;
				cout<<"�������ƣ�"<<it->exam_name<<endl;
				cout<<"���سɼ���"<<fixed<<setprecision(0)<<it->S<<endl;
				cout<<"����ɼ���"<<fixed<<setprecision(0)<<z.S<<endl;
				cout<<"===================="<<endl;
				cout<<"�Ƿ��滻��(Y/N)"; 
				cin>>o;
				o[0]=='Y'||o[0]=='y'?found=false:found=true;
				break;
			}
		if(z.S>ScoreControl){
			system("cls");
			cout<<"�ɼ�����������ƣ�"<<endl;
			getch();
			return 0;
		}
		else{
			stu.insert(z);
			system("cls");
			cout<<"������ɣ��Ƿ�������룿(Y/N)"<<endl;
			cin>>o;
			if(o[0]=='y'||o[0]=='Y') goto ris;
			else return 0;
		}
	}
	int rchange(){
		rcs:
		o[0]=0;
		system("cls");
		string tmp;
		j=1;
		cout<<"������ѧ��ѧ�Ż�������";
		cin>>tmp;
		cout<<"�����뿼�����ƣ�";
		cin>>z.exam_name; 
		for(it=stu.begin();it!=stu.end();it++,j++){
			if((it->id==tmp||it->name==tmp)&&it->exam_name==z.exam_name){
				system("cls"); 
				cout<<"��ѧ��ԭ��Ϣ"<<endl;
				cout<<"ѧ�ţ�"<<it->id<<endl;
				cout<<"������"<<it->name<<endl;
				cout<<"�������ƣ�"<<it->exam_name<<endl; 
				cout<<"�ɼ���"<<it->S<<endl;
				if(MessageBox(NULL,"��ȷ��Ҫ���ĸ�ѧ������Ϣ��","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES){
					z.id=it->id;
					z.name=it->name;
					stu.erase(it);
					break;
				}
				else return 1;
			}
			if(j==stu.size()){
				system("cls");
				MessageBox(NULL,"δ�ҵ���ѧ������Ϣ��������Ϣ�Ƿ��Ѿ�¼��ϵͳ��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
				return 1;
			}
		}
		rc:
		cout<<"�������¿������ƣ�";
		cin>>z.exam_name; 
		menl=max(menl,z.exam_name.length());
		string ttmp;
		inputScore:
		cout<<"������ɼ���";
		cin>>ttmp;
		for(int iii=0;iii<ttmp.size();iii++)
			if((ttmp[iii]<'0'||ttmp[iii]>'9')&&ttmp[iii]!='.'){
				system("cls");
				cout<<endl<<"�ɼ����Ϸ������������룡"<<endl; 
				system("pause");
				system("cls");
				goto inputScore;
			}
		z.S=atof(ttmp.c_str());
		stu.insert(z);
		system("cls");
		cout<<"������ɣ��Ƿ�������ģ�(Y/N)"<<endl;
		cin>>o;
		if(o[0]=='Y'||o[0]=='y') goto rcs;
		else return 0; 
	}
	int rdelete(){
		rds:
		system("cls");
		string tmp;
		j=1;
		cout<<"������ѧ��ѧ�Ż�������";
		cin>>tmp;
		cout<<"�����뿼�����ƣ�";
		cin>>z.exam_name; 
		for(it=stu.begin();it!=stu.end();it++,j++){
			if((it->id==tmp||it->name==tmp)&&z.exam_name==it->exam_name){
				system("cls"); 
				cout<<"��ѧ��ԭ��Ϣ"<<endl;
				cout<<"ѧ�ţ�"<<it->id<<endl;
				cout<<"������"<<it->name<<endl;
				cout<<"�������ƣ�"<<it->exam_name<<endl; 
				cout<<"�ɼ���"<<fixed<<setprecision(0)<<it->S<<endl;
				if(MessageBox(NULL,"��ȷ��Ҫɾ����ѧ������Ϣ��","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES){
					z.id=it->id;
					stu.erase(it);
					break;
				}
				else return 1;
			}
			if(j==stu.size()){
				system("cls");
				MessageBox(NULL,"δ�ҵ���ѧ������Ϣ��������Ϣ�Ƿ��Ѿ�¼��ϵͳ��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
				return 1;
			}
		}
		system("cls");
		cout<<"ɾ����ɣ��Ƿ����ɾ����(Y/N)"<<endl;
		cin>>o;
		if(o[0]=='Y'||o[0]=='y') goto rds;
		else return 0; 
	}
	int rexam_nameDelete(){
		 system("cls");
		 cout<<"�����뿼�����ƣ�";
		 cin>>z.exam_name;
		 system("cls");	
		 cout<<"��־��"<<endl;
		 cout<<"����ɾ����������Ϊ "<<z.exam_name<<" ��������Ϣ"<<endl;
		 bool found=false;
		 for(it=stu.begin(),i=1;it!=stu.end();it++,i++){
			if(it->exam_name==z.exam_name){
				cout<<"��ɾ��"<<i<<"����Ϣ��ѧ�ţ�"<<it->id<<" ������"<<it->name<<" ������"<<fixed<<setprecision(0)<<it->S<<"��"<<endl;
				stu.erase(it);
				it=stu.begin();
				found=true;
			}
		}
		if(!found){
			system("cls");
			MessageBox(NULL,"δ�ҵ����ϵĿ��ԣ�������Ϣ�Ƿ��Ѿ�¼��ϵͳ��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
			return 1;
		}
		getch();
		return 0;
	}
	//record operation end
}

namespace record_output{
	//record output settings
	void Settings(){
		while(1){
			system("cls");
			while(1){
				ifstream fin;
				fin.open("ROS.dat");
				fin>>ROSnum>>ROSid>>ROSname;
				fin.close();
				break;
			}
			cout<<"ѧ���ɼ�����ϵͳ-��ѯ����"<<endl;
			if(ROSnum) cout<<"(��) ";
			else cout<<"(��) "; 
			cout<<"1.��ʾ����"<<endl; 
			if(ROSid) cout<<"(��) ";
			else cout<<"(��) "; 
			cout<<"2.��ʾѧ��"<<endl; 
			if(ROSname) cout<<"(��) ";
			else cout<<"(��) "; 
			cout<<"3.��ʾ����"<<endl;
			cout<<"(��) 4.�˳�����"<<endl; 
			o[0]=getch();
			if(o[0]=='1'){
				if(ROSnum) ROSnum=0;
				else ROSnum=1;
			}
			if(o[0]=='2'){
				ROSid?ROSid=0:ROSid=1;
				if(!ROSid&&!ROSname){
					MessageBox(NULL,"ѧ�ź������б�����һ��ѡ�У�","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
					ROSid=1;
				}
			}
			if(o[0]=='3'){
				ROSname?ROSname=0:ROSname=1;
				if(!ROSid&&!ROSname){
					MessageBox(NULL,"ѧ�ź������б�����һ��ѡ�У�","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
					ROSname=1;
				}
			}
			while(1){
				ofstream fout;
				fout.open("ROS.dat");
				fout<<ROSnum<<" "<<ROSid<<" "<<ROSname;
				fout.close();
				break;
			}
			if(o[0]=='4'){
				system("cls");
				cout<<"ѧ���ɼ�����ϵͳ-��ѯ����"<<endl;
				if(ROSnum) cout<<"(��) ";
				else cout<<"(��) "; 
				cout<<"1.��ʾ����"<<endl; 
				if(ROSid) cout<<"(��) ";
				else cout<<"(��) "; 
				cout<<"2.��ʾѧ��"<<endl; 
				if(ROSname) cout<<"(��) ";
				else cout<<"(��) "; 
				cout<<"3.��ʾ����"<<endl;
				cout<<"(��) 4.�˳�����"<<endl; 
				Sleep(500);
				break;
			}
			o[0]=0;
		}
	}
	//record output (five ways)
	//output all information
	int output(){
		double All,Average;
		system("cls");
		if(stu.size()<1){
			MessageBox(NULL,"���޼�¼��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
			return 1;
		}
		clock_t start = clock();
		z.exam_name=' ';
		if(ROSnum) cout<<"���� |";
		if(ROSid){
			cout<<"ѧ�� ";
			for(i=midl;i>4;i--) cout<<" ";
			cout<<"|";
		}
		if(ROSname){
			cout<<"���� ";
			for(i=mnl;i>4;i--) cout<<" ";
			cout<<"|";
		}
		cout<<"�������� ";
		for(i=menl;i>8;i--) cout<<" ";
		cout<<"|�ɼ�"<<endl;
		double STmp=-1;
		int sum;
		for(it=stu.begin(),i=0,sum=1;it!=stu.end();it++,sum++){
			if(STmp!=it->S) i++;
			if(z.exam_name!=it->exam_name&&i!=1){
				Average=All/(sum-1);
				All=0;
				i=1;
				sum=1;
				cout<<"ƽ���֣�"<<setprecision(2)<<fixed<<Average<<endl;
				cout<<endl;
			}
			if(ROSnum){
				if(i<10) cout<<i<<"    |";
				if(i>=10&&i<100) cout<<i<<"   |";
				if(i>=100&&i<1000) cout<<i<<"  |";
				if(i>=1000&&i<10000) cout<<i<<" |";
				if(i>=10000&&i<100000) cout<<i<<"|";
			}
			if(ROSid){
				cout<<it->id;
				for(j=midl;j>=it->id.length();j--) cout<<" ";
				cout<<"|";
			}
			if(ROSname){
				cout<<it->name;
				for(j=mnl;j>=it->name.length();j--) cout<<" ";
				cout<<"|";
			}
			cout<<it->exam_name;
			for(j=menl;j>=it->exam_name.length();j--) cout<<" ";
			cout<<"|"<<setprecision(0)<<fixed<<it->S;
			cout<<endl;
			STmp=it->S; 
			All+=it->S;
			z.exam_name=it->exam_name;
		}
		Average=All/(sum-1);
		cout<<"ƽ���֣�"<<setprecision(2)<<fixed<<Average<<endl<<endl;
		clock_t end   = clock();
		cout << "ʹ��ʱ�䣺" <<setprecision(2)<<fixed<<(double)(end - start) / CLOCKS_PER_SEC << " ��" << endl;
		system("pause");
	}
	//output only one student's information
	int find(){
		system("cls");
		if(stu.size()<1){
			MessageBox(NULL,"���޼�¼��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
			return 1;
		}
		double Average,All;
		z.exam_name=' ';
		string tmp;
		bool f=false; 
		cout<<"������ѧ��ѧ�Ż�������";
		cin>>tmp;
		clock_t start = clock();
		if(ROSnum) cout<<"���� |";
		if(ROSid){
			cout<<"ѧ�� ";
			for(i=midl;i>4;i--) cout<<" ";
			cout<<"|";
		}
		if(ROSname){
			cout<<"���� ";
			for(i=mnl;i>4;i--) cout<<" ";
			cout<<"|";
		}
		cout<<"�������� ";
		for(i=menl;i>8;i--) cout<<" ";
		cout<<"|�ɼ�"<<endl;
		double STmp;
		int sum;
		for(it=stu.begin(),i=0,sum=1;it!=stu.end();it++,sum++){
			if(STmp!=it->S) i++;
			if(z.exam_name!=it->exam_name&&i!=1){
				Average=All/(sum-1);
				All=0;
				i=1;
				sum=1;
				cout<<"ƽ���֣�"<<setprecision(2)<<fixed<<Average<<endl;
				cout<<endl;
			}
			if(it->id==tmp||it->name==tmp){
				if(ROSnum){
					if(i<10) cout<<i<<"    |";
					if(i>=10&&i<100) cout<<i<<"   |";
					if(i>=100&&i<1000) cout<<i<<"  |";
					if(i>=1000&&i<10000) cout<<i<<" |";
					if(i>=10000&&i<100000) cout<<i<<"|";
				}
				if(ROSid){
					cout<<it->id;
					for(j=midl;j>=it->id.length();j--) cout<<" ";
					cout<<"|";
				}
				if(ROSname){
					cout<<it->name;
					for(j=mnl;j>=it->name.length();j--) cout<<" ";
					cout<<"|";
				}
				cout<<it->exam_name;
				for(j=menl;j>=it->exam_name.length();j--) cout<<" ";
				cout<<"|"<<setprecision(0)<<fixed<<it->S;
				STmp=it->S; 
				cout<<endl;
				f=true;
			}
			All+=it->S; 
			z.exam_name=it->exam_name;
		}
		Average=All/(sum-1);
		cout<<"ƽ���֣�"<<setprecision(2)<<fixed<<Average<<endl<<endl;
		if(f==true){
			clock_t end   = clock();
			cout << "ʹ��ʱ�䣺" <<setprecision(2)<<fixed<< (double)(end - start) / CLOCKS_PER_SEC << " ��" << endl;
			system("pause");
			return 1;
		}
		system("cls");
		MessageBox(NULL,"δ�ҵ���ѧ������Ϣ��������Ϣ�Ƿ��Ѿ�¼��ϵͳ��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		return 1;
	}
	//output information in given examname
	int find_examname(){
		system("cls");
		if(stu.size()<1){
			MessageBox(NULL,"���޼�¼��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
			return 1;
		}
		double Average,All;
		bool f=false; 
		z.exam_name=' ';
		string tmp;
		cout<<"�����뿼�����ƣ�";
		cin>>tmp;
		clock_t start = clock();
		if(ROSnum) cout<<"���� |";
		if(ROSid){
			cout<<"ѧ�� ";
			for(i=midl;i>4;i--) cout<<" ";
			cout<<"|";
		}
		if(ROSname){
			cout<<"���� ";
			for(i=mnl;i>4;i--) cout<<" ";
			cout<<"|";
		}
		cout<<"�������� ";
		for(i=menl;i>8;i--) cout<<" ";
		cout<<"|�ɼ�"<<endl;
		double STmp;
		int sum=1;
		for(it=stu.begin(),i=0;it!=stu.end();it++,sum++){
			if(STmp!=it->S) i++;
			if(z.exam_name!=it->exam_name&&i!=1){
				Average=All/(sum-1);
				All=0;
				i=1;
				sum=1;
				if(z.exam_name==tmp) cout<<setprecision(2)<<fixed<<"ƽ���֣�"<<Average<<endl;
				cout<<endl;
			}
			if(it->exam_name==tmp){	if(ROSnum){
					if(i<10) cout<<i<<"    |";
					if(i>=10&&i<100) cout<<i<<"   |";
					if(i>=100&&i<1000) cout<<i<<"  |";
					if(i>=1000&&i<10000) cout<<i<<" |";
					if(i>=10000&&i<100000) cout<<i<<"|";
				}
				if(ROSid){
					cout<<it->id;
					for(j=midl;j>=it->id.length();j--) cout<<" ";
					cout<<"|";
				}
				if(ROSname){
					cout<<it->name;
					for(j=mnl;j>=it->name.length();j--) cout<<" ";
					cout<<"|";
				}
				cout<<it->exam_name;
				for(j=menl;j>=it->exam_name.length();j--) cout<<" ";
				cout<<"|"<<setprecision(0)<<fixed<<it->S;
				STmp=it->S; 
				cout<<endl;
				f=true;
			}
			All+=it->S; 
			z.exam_name=it->exam_name;
		}
		Average=All/(sum-1);
		cout<<"ƽ���֣�"<<setprecision(2)<<fixed<<Average<<endl<<endl;
		if(f==true){
			clock_t end   = clock();
			cout << "ʹ��ʱ�䣺" << setprecision(2)<<fixed<<(double)(end - start) / CLOCKS_PER_SEC << " ��" << endl;
			system("pause");
			return 1;
		}
		system("cls");
		MessageBox(NULL,"δ�ҵ��ÿ������κ�ѧ������Ϣ��������Ϣ�Ƿ��Ѿ�¼��ϵͳ��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		return 1;
	}
	//output information between given lowest score and given highest score
	int find_score(){
		system("cls");
		if(stu.size()<1){
			MessageBox(NULL,"���޼�¼��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
			return 1;
		}
		double Average,All;
		bool f=false; 
		z.exam_name=' ';
		int l,h;//l:lowest,h:highest
		cout<<"��������ͷ�����";
		cin>>l;
		cout<<"��������߷�����";
		cin>>h; 
		clock_t start = clock();
		if(ROSnum) cout<<"���� |";
		if(ROSid){
			cout<<"ѧ�� ";
			for(i=midl;i>4;i--) cout<<" ";
			cout<<"|";
		}
		if(ROSname){
			cout<<"���� ";
			for(i=mnl;i>4;i--) cout<<" ";
			cout<<"|";
		}
		cout<<"�������� ";
		for(i=menl;i>8;i--) cout<<" ";
		cout<<"|�ɼ�"<<endl;
		double STmp;
		int sum=1;
		for(it=stu.begin(),i=0;it!=stu.end();it++,sum++){
			if(STmp!=it->S) i++;
			if(z.exam_name!=it->exam_name&&i!=1){
				Average=All/(sum-1);
				All=0;
				i=1;
				sum=1;
				cout<<"ƽ���֣�"<<setprecision(2)<<fixed<<Average<<endl;
				cout<<endl;
			}
			if(it->S>=l&&it->S<=h){	if(ROSnum){
					if(i<10) cout<<i<<"    |";
					if(i>=10&&i<100) cout<<i<<"   |";
					if(i>=100&&i<1000) cout<<i<<"  |";
					if(i>=1000&&i<10000) cout<<i<<" |";
					if(i>=10000&&i<100000) cout<<i<<"|";
				}
				if(ROSid){
					cout<<it->id;
					for(j=midl;j>=it->id.length();j--) cout<<" ";
					cout<<"|";
				}
				if(ROSname){
					cout<<it->name;
					for(j=mnl;j>=it->name.length();j--) cout<<" ";
					cout<<"|";
				}
				cout<<it->exam_name;
				for(j=menl;j>=it->exam_name.length();j--) cout<<" ";
				cout<<"|"<<setprecision(0)<<fixed<<it->S;
				STmp=it->S; 
				cout<<endl;
				f=true;
			}
			All+=it->S; 
			z.exam_name=it->exam_name;
		}
		Average=All/(sum-1);
		cout<<"ƽ���֣�"<<setprecision(2)<<fixed<<Average<<endl<<endl;
		if(f==true){
			clock_t end   = clock();
			cout << "ʹ��ʱ�䣺" << setprecision(2)<<fixed<<(double)(end - start) / CLOCKS_PER_SEC << " ��" << endl;
			system("pause");
			return 1;
		}
		system("cls");
		MessageBox(NULL,"δ�ҵ��÷��������κ�ѧ������Ϣ��������Ϣ�Ƿ��Ѿ�¼��ϵͳ��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		return 1;
	}
	//output information in given classname 
	int find_clssnm(){
		string clssnm,pwd;
		int n;
		system("cls");
		if(stu.size()<1){
			MessageBox(NULL,"���޼�¼��","ѧ���ɼ�����ϵͳ",MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
			return 1;
		}
		ifstream fin;	
		fin.open("ClassEdition.dat");
		fin>>clssnm>>pwd>>n;
		for(i=1;i<=n;i++){
			fin>>zz.name>>zz.id;
			for(j=0;j<zz.id.length();j++)
				zz.id[j]-=10;
			z.id=zz.id;
			for(j=0;j<zz.name.length();j++)
				zz.name[j]-=10;
			stuinfo.insert(zz);
		}
		double Average,All;
		bool f=false; 
		z.exam_name=' ';
		clock_t start = clock();
		if(ROSnum) cout<<"���� |";
		if(ROSid){
			cout<<"ѧ�� ";
			for(i=midl;i>4;i--) cout<<" ";
			cout<<"|";
		}
		if(ROSname){
			cout<<"���� ";
			for(i=mnl;i>4;i--) cout<<" ";
			cout<<"|";
		}
		cout<<"�������� ";
		for(i=menl;i>8;i--) cout<<" ";
		cout<<"|�ɼ�"<<endl;
		double STmp;
		int sum=1;
		for(it=stu.begin(),i=0;it!=stu.end();it++,sum++){
			if(STmp!=it->S) i++;
			if(z.exam_name!=it->exam_name&&i!=1){
				Average=All/(sum-1);
				All=0;
				i=1;
				sum=1;
				cout<<"ƽ���֣�"<<setprecision(2)<<fixed<<Average<<endl;
				cout<<endl;
			}
			for(siit=stuinfo.begin();siit!=stuinfo.end();siit++){
				if(siit->name==it->name&&siit->id==it->id){	
					if(ROSnum){
						if(i<10) cout<<i<<"    |";
						if(i>=10&&i<100) cout<<i<<"   |";
						if(i>=100&&i<1000) cout<<i<<"  |";
						if(i>=1000&&i<10000) cout<<i<<" |";
						if(i>=10000&&i<100000) cout<<i<<"|";
					}
					if(ROSid){
						cout<<it->id;
						for(j=midl;j>=it->id.length();j--) cout<<" ";
						cout<<"|";
					}
					if(ROSname){
						cout<<it->name;
						for(j=mnl;j>=it->name.length();j--) cout<<" ";
						cout<<"|";
					}
					cout<<it->exam_name;
					for(j=menl;j>=it->exam_name.length();j--) cout<<" ";
					cout<<"|"<<setprecision(0)<<fixed<<it->S;
					STmp=it->S; 
					cout<<endl;
					break;
				}
			}
			All+=it->S; 
			z.exam_name=it->exam_name;
		}
		Average=All/(sum-1);
		cout<<"ƽ���֣�"<<setprecision(2)<<fixed<<Average<<endl<<endl;
		clock_t end   = clock();
		cout << "ʹ��ʱ�䣺" << setprecision(2)<<fixed<<(double)(end - start) / CLOCKS_PER_SEC << " ��" << endl;
		system("pause");
		return 1;
	}
	//record output end
}

int main(){	
	//===============init===============
	system("cls");
	system("color f0");
	ti=t->tm_min; 
	bool usr,adminAccess,DriverExist;
	bool SetFocus=0;
	adminAccess=adminCheck(); 
	if(!adminAccess){
		MessageBox(NULL,"ϵͳδ��ù���ԱȨ�ޣ�Ϊ����ѧ����Ϣ���ᶪʧ����ʹ�ù���ԱȨ������ϵͳ��\r\nע�⣺��ȷ������ϵͳ��رգ�","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		exit(0);
	}
	DriverExist=DriverCheck();
	if(!DriverExist){
		MessageBox(NULL,"ϵͳδδ�ҵ�D�̣�����ϵͳ���� ����ļ����� �� ������Ϣ ��  ���ذ�װ�� ʱ���õ�D�̣��봴��D�̣����������в��ң���\r\nע�⣺��ȷ������ϵͳ��رգ�","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		exit(0);
	}
	cin.clear();
	cin.sync(); 
	ACTIVATION();
	load(); hit(); start(4); usr=user::login(1); load(); file::input(1);
	ifstream fin;
	fin.open("ROS.dat");
	fin>>ROSnum>>ROSid>>ROSname;
	fin.close();
	if(!ROSid&&!ROSname) ROSid=ROSname=1;
	SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE);
	string clssnm,pwd;
	int n;
	int size,sizetmp;
	if(usr){
		ifstream fin;
		fin.open("ScoreControl.dat");
		if(!fin){
			cout<<"��������߷������ƣ�Ĭ��Ϊ100�֣����1000000�֣���"<<endl;
			cin>>ScoreControl;
			if(ScoreControl<1||ScoreControl>1000000)
				MessageBox(NULL,"��Ч������","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
			else{
				ofstream fout;
				fout.open("ScoreControl.dat");
				if(!fout)
					MessageBox(NULL,"�޷��������ã�����ϵͳ�Ƿ��Ѿ���ù���ԱȨ�ޣ�","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
				else{
					fout<<ScoreControl*80123750<<endl;
					fout.close();
					system("cls");
					cout<<"�������� ��߷������ƣ�"<<ScoreControl<<"�֣�����������ݳ��������ƣ����ᱨ��"<<endl;
					getch();
				}
			}
		}
		else{ 
			fin>>ScoreControlFI; 
			ScoreControl=ScoreControlFI/80123750;
		}
	}
	//===============init===============
	while(o[0]!='E'){
		cin.clear();
		cin.sync(); 
		time_t tt = time(NULL);	
		tm* t=localtime(&tt);
		if(t->tm_min!=ti&&stu.size()>0){
			file::output(1);
			ti=t->tm_min;
		}
		mnl=menl=midl=0;
		for(it=stu.begin();it!=stu.end();it++){
			mnl=max(mnl,it->name.length());
			if(mnl<5) mnl=5;
			menl=max(menl,it->exam_name.length());
			if(menl<5) menl=9;
			midl=max(midl,it->id.length());
			if(midl<5) midl=5;
		}
		system("cls");
		if(usr) system("title ѧ���ɼ�����ϵͳ");
		if(!usr) system("title ѧ���ɼ���ѯϵͳ"); 
		if(usr) cout<<"ѧ���ɼ�����ϵͳ ";
		if(!usr) cout<<"ѧ���ɼ���ѯϵͳ"; 
		cout<<" ���ڣ�"<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
		cout<<" ʱ�䣺"<<t->tm_hour<<":";
		if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
		else cout<<t->tm_min<<endl;
		if(usr) cout<<"1.ѧ����Ϣ����"<<endl;
		if(usr) cout<<"2.�ļ�����"<<endl; 
		if(usr) cout<<"3.��ѯ"<<endl;
		if(!usr) cout<<"1.��ѯ"<<endl; 
		if(usr) cout<<"4.����"<<endl; 
		if(usr) cout<<"H.����"<<endl; 
		cout<<"E.�˳�ϵͳ"<<endl; 
		cout<<"L.����ϵͳ"<<endl; 
		if(!SetFocus) cout<<"S.�ö�����"<<endl; 
		if(usr) cout<<"R.��������"<<endl;
		cout<<"@.����"<<endl; 
		cout<<"������������룺"; 
		o[0]=getch();
		if(o[0]=='S'){SetWindowPos(GetConsoleWindow(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE); SetFocus=1;}
		if(o[0]=='E') if(MessageBox(NULL,"��ȷ��Ҫ�˳���","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) break;
		if(o[0]=='H') system("HELP_zh-cn.chm");
		if(o[0]=='L'){load();start(4);usr=user::login(1);}
		if(o[0]=='R'&&usr){
			o[0]=0; 
			system("cls");
			if(MessageBox(NULL,"��ȷ��Ҫ����������\r\n�˲��������棡","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES){
				while(1){
					bool admin;
					system("cls");
					start(4);
					if(MessageBox(NULL,"����Ҫ��֤����Ա��ݣ�\r\n���Ǽ���������ֹͣ���ģ�","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) admin=user::login(1);
					else break;
					if(!admin){
						MessageBox(NULL,"����ʹ��ѧ��ģʽ��½��","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
						break;
					}
					if(MessageBox(NULL,"��֤ͨ����\r\n���Ǽ���������ֹͣ���ģ�","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) stu.clear();
					else break;
					MessageBox(NULL,"��ɣ�","ѧ���ɼ�����ϵͳ",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
					break;
				}
			}
			o[0]=0; 
		}
		if(o[0]=='@'){
			o[0]=0; 
			system("cls");	
			cout<<"Copyright (C) 2017-2018 XiyuWang All rights reserved."<<endl;
			cout<<"Version:17.2.6"<<endl; 
			system("pause");
			o[0]=0; 
		}
		if(o[0]=='1'&&usr){
			o[0]=0; 
			string clssnm="���봴���༶��",tmp; 
			ifstream fin;
			fin.open("ClassEdition.dat");
			fin>>tmp;
			if(fin&&tmp[0]!=0){
				clssnm=tmp;
				for(i=0;i<clssnm.length();i++)
					clssnm[i]-=18;
			}
			system("cls");
			cout<<"ѧ���ɼ�����ϵͳ-ѧ����Ϣ����";
			cout<<" ���ڣ�"<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" ʱ�䣺"<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.¼��ѧ����Ϣ"<<endl;
			cout<<"2.����ѧ����Ϣ"<<endl; 
			cout<<"3.ɾ��ѧ����Ϣ"<<endl; 
			cout<<"4.ɾ���ض�����������ѧ������Ϣ"<<endl; 
			cout<<"5.�༶ģʽ¼����Ϣ����ǰ�༶��"<<clssnm<<"��"<<endl; 
			cout<<"�������� ����"<<endl;
			cout<<"������������룺";
			o[0]=getch(); 
			if(o[0]=='1'&&stu.size()<100000) record_input::rinput();
			if(o[0]=='1'&&stu.size()>=100000){
				system("cls");
				cout<<"���������󣬲��ɼ���¼����Ϣ��"<<endl;
				system("pause");
			}
			if(o[0]=='2'){
				if(stu.size()<=0) MessageBox(NULL,"�������ݣ��޷����и��Ĳ�����","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
				else record_input::rchange();
			} 
			if(o[0]=='3'){
				if(stu.size()<=0) MessageBox(NULL,"�������ݣ��޷�����ɾ��������","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
				else record_input::rdelete();
			}
			if(o[0]=='4'){
				if(stu.size()<=0) MessageBox(NULL,"�������ݣ��޷�����ɾ��������","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
				while(stu.size()>0){
					bool admin;
					system("cls");
					start(4);
					if(MessageBox(NULL,"����Ҫ��֤����Ա��ݣ�\r\n���Ǽ���������ֹͣ���ģ�","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) admin=user::login(1);
					else break;
					if(!admin){
						MessageBox(NULL,"����ʹ��ѧ��ģʽ��½��","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
						break;
					}
					if(MessageBox(NULL,"��֤ͨ����\r\n���Ǽ���������ֹͣ���ģ�","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) record_input::rexam_nameDelete(); 
					else break;
					MessageBox(NULL,"��ɣ�","ѧ���ɼ�����ϵͳ",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
					break;
				}
			}
			if(o[0]=='5'){
				system("cls");
				ifstream fin;
				fin.open("ClassEdition.dat");
				if(!fin){
					cout<<"����δ�����༶���밴���������......"<<endl;
					cout<<"���Ҫȡ�������༶���밴�رհ�ť��ѡ�������ϵͳ��"<<endl; 
					getch();
					ClassEdition::make();
				}
				else ClassEdition::main();
			}
			o[0]=0; 
		} 
		if(o[0]=='2'&&usr){
			o[0]=0; 
			system("cls");
			cout<<"ѧ���ɼ�����ϵͳ-�ļ�����";
			cout<<" ���ڣ�"<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" ʱ�䣺"<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.������Ϣ���ļ����Զ���"<<endl;
			cout<<"2.���ļ���ȡ��Ϣ "<<endl;
			cout<<"3.�������������ļ�"<<endl;
			cout<<"4.����ת�����"<<endl; 
			cout<<"�������� ����"<<endl;
			cout<<"������������룺";
			o[0]=getch(); 
			if(o[0]=='1') file::output(0);
			if(o[0]=='2') file::input(0);
			if(o[0]=='3') file::backup(); 
			if(o[0]=='4'){
				o[0]=0;
				system("cls");
				cout<<"ѧ���ɼ�����ϵͳ-�ļ�����-����ת�����";
				cout<<" ���ڣ�"<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
				cout<<" ʱ�䣺"<<t->tm_hour<<":";
				if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
				else cout<<t->tm_min<<endl;
				cout<<"1.V16.9.18ת��V17.2.6"<<endl;
				cout<<"�������� ����"<<endl;
				cout<<"������������룺";
				o[0]=getch();
				if(o[0]=='1') system("FileCodeConvert\\FileCodeConvert-16.9.18_To_17.2.6.dll");
			}
			o[0]=0;
		}
		if(o[0]=='3'&&usr||o[0]=='1'&&!usr){
			o[0]=0; 
			string clssnm="���봴���༶��",tmp; 
			ifstream fin;
			fin.open("ClassEdition.dat");
			fin>>tmp;
			if(fin&&tmp[0]!=0){
				clssnm=tmp;
				for(i=0;i<clssnm.length();i++)
					clssnm[i]-=18;
			}
			system("cls");
			if(usr) cout<<"ѧ���ɼ�����ϵͳ-��ѯ";
			if(!usr) cout<<"ѧ���ɼ���ѯϵͳ-��ѯ"; 
			cout<<" ���ڣ�"<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" ʱ�䣺"<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.�鿴����ѧ��������"<<endl;
			cout<<"2.�鿴����ѧ����ϸ��Ϣ"<<endl; 
			cout<<"3.�鿴�ض�����ѧ��������"<<endl; 
			cout<<"4.�鿴�ض���������ѧ��������"<<endl; 
			cout<<"5.�鿴�༶ "<<clssnm<<" ��ѧ��������"<<endl; 
			cout<<"6.��ѯ����"<<endl; 
			cout<<"�������� ����"<<endl; 
			cout<<"������������룺";
			o[0]=getch(); 
			if(o[0]=='1') record_output::output(); 
			if(o[0]=='2') record_output::find();
			if(o[0]=='3') record_output::find_examname(); 
			if(o[0]=='4') record_output::find_score();
			if(o[0]=='5'&&fin) record_output::find_clssnm();
			if(o[0]=='5'&&!fin) MessageBox(NULL,"����δ�����༶��\r\n��ǰ�� ��ҳ=>ѧ����Ϣ����=>4.�༶ģʽ¼����Ϣ �����༶��","ѧ���ɼ�����ϵͳ",MB_OK|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
			if(o[0]=='6') record_output::Settings();
			o[0]=0;
		}
		if(o[0]=='4'&&usr){
			o[0]=0;
			system("cls");
			cout<<"ѧ���ɼ�����ϵͳ-����";
			cout<<" ���ڣ�"<<t->tm_year+1900<<"/"<<t->tm_mon+1<<"/"<<t->tm_mday;
			cout<<" ʱ�䣺"<<t->tm_hour<<":";
			if(t->tm_min<10) cout<<"0"<<t->tm_min<<endl;
			else cout<<t->tm_min<<endl;
			cout<<"1.�����û���Ϣ"<<endl;
			cout<<"2.���İ༶��Ϣ"<<endl; 
			cout<<"3.�ؽ��༶"<<endl; 
			cout<<"4.���÷�������"<<endl; 
			cout<<"5.��ϵ����"<<endl; 
			cout<<"6.�鿴������"<<endl; 
			cout<<"7.����"<<endl; 
			cout<<"�������� ����"<<endl; 
			cout<<"������������룺";
			o[0]=getch();
			if(o[0]=='1'){
				while(1){
					bool admin;
					system("cls");
					start(4);
					if(MessageBox(NULL,"����Ҫ��֤����Ա��ݣ�\r\n���Ǽ���������ֹͣ���ģ�","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) admin=user::login(1);
					else break;
					if(!admin){
						MessageBox(NULL,"����ʹ��ѧ��ģʽ��½��","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
						break;
					}
					if(MessageBox(NULL,"��֤ͨ����\r\n���Ǽ���������ֹͣ���ģ�","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) user::ReReg();
					else break;
					MessageBox(NULL,"��ɣ�","ѧ���ɼ�����ϵͳ",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
					break;
				}
			}
			if(o[0]=='2'){
				while(1){ 
					string tmp;
					ifstream fin;
					fin.open("ClassEdition.dat");
					fin>>tmp;
					if(!fin||tmp[0]==0){
						system("cls");
						MessageBox(NULL,"����δ�����༶��\r\n��ǰ�� ��ҳ=>ѧ����Ϣ����=>4.�༶ģʽ¼����Ϣ �����༶��","ѧ���ɼ�����ϵͳ",MB_OK|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND);
						break;
					}	
					bool admin;
					system("cls");
					start(4);
					if(MessageBox(NULL,"����Ҫ��֤����Ա��ݣ�\r\n���Ǽ���������ֹͣ���ģ�","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) admin=user::login(1);
					else break;
					if(!admin){
						MessageBox(NULL,"����ʹ��ѧ��ģʽ��½��","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
						break;
					}
					if(MessageBox(NULL,"��֤ͨ����\r\n���Ǽ���������ֹͣ���ģ�","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) ClassEdition::reg();
					break; 
				}
			}
			if(o[0]=='3'){
				while(1){ 
					bool admin;
					system("cls");
					start(4);
					if(MessageBox(NULL,"����Ҫ��֤����Ա��ݣ�\r\n���Ǽ���������ֹͣ���ģ�","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) admin=user::login(1);
					else break;
					if(!admin){
						MessageBox(NULL,"����ʹ��ѧ��ģʽ��½��","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
						break;
					}
					if(MessageBox(NULL,"��֤ͨ����\r\n���Ǽ���������ֹͣ���ģ�","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) ClassEdition::make();
					break;
				}
			}
			if(o[0]=='4'){
				system("cls");
				while(1){ 
					bool admin;
					system("cls");
					start(4);
					if(MessageBox(NULL,"����Ҫ��֤����Ա��ݣ�\r\n���Ǽ���������ֹͣ���ģ�","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES) admin=user::login(1);
					else break;
					if(!admin){
						MessageBox(NULL,"����ʹ��ѧ��ģʽ��½��","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
						break;
					}
					if(MessageBox(NULL,"��֤ͨ����\r\n���Ǽ���������ֹͣ���ģ�","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONWARNING|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDNO) break;
					system("cls");
					cout<<"��������߷������ƣ�Ĭ��Ϊ100�֣����1000000�֣���"<<endl;
					cin>>ScoreControl;
					if(ScoreControl<1||ScoreControl>1000000)
						MessageBox(NULL,"��Ч������","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
					else{
						ofstream fout;
						fout.open("ScoreControl.dat");
						if(!fout)
							MessageBox(NULL,"�޷��������ã�����ϵͳ�Ƿ��Ѿ���ù���ԱȨ�ޣ�","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
						else{
							fout<<ScoreControl*80123750<<endl;
							fout.close();
							system("cls");
							cout<<"�������� ��߷������ƣ�"<<ScoreControl<<"�֣�����������ݳ��������ƣ����ᱨ��"<<endl;
							getch();
							break;
						}
					}
					break;
				}
			}
			if(o[0]=='5'){
				system("cls");
				MessageBox(NULL,"�뷢���ʼ�����\r\nXiyuWang_Code@hotmail.com","ѧ���ɼ�����ϵͳ",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
			}
			if(o[0]=='6'){
				ifstream fin;
				fin.open("ClassEdition.dat");
				if(fin){
					fin>>clssnm;
					for(i=0;i<clssnm.length();i++)
						clssnm[i]-=18;
				}
				system("cls");
				cout<<"��ǰ��������"<<stu.size()<<endl; 
				if(fin&&stuinfo.size()!=0) cout<<"�༶ "<<clssnm<<" �е�ѧ������"<<stuinfo.size()<<endl; 
				system("pause");
			}
			if(o[0]=='7'){
				system("cls");
				system("del D:\\SAMS_zh-cn_installer.rar");
				system("cls");
				cout<<"�����������µ� ��װ��������رճ���......"<<endl;
				system("wget https://xiyuwang2006.github.io/MyWork/StudentAchievementManagementSystem/SAMS_zh-cn_installer.rar -q");
				system("copy SAMS_zh-cn_installer.rar D:\\SAMS_zh-cn_installer.rar");
				system("del SAMS_zh-cn_installer.rar /s/f/q"); 
				system("cls"); 
				ifstream fin;
				fin.open("D:\\SAMS_zh-cn_installer.rar") ;
				if(!fin){
					cout<<"�޷����� 64λϵͳ �����°�װ�������������D���Ƿ���ڣ��������������������Ƿ�����ά����10~30�����ڽ��޸���"<<endl;
					getch(); 
				}
				else{
					cout<<"������Դ���Ѿ������D�̣��ļ�����SAMS_zh-cn_installer.rar����"<<endl;
					cout<<"����ж�ؾ������Ȼ���ѹѹ���������а�װ������װ��ϵͳ��"<<endl;
					cout<<"ע�⣺������װϵͳ���ᵼ��ѧ����Ϣ�Ķ�ʧ����Ȼ������������ģ�Ҳ�����ȱ�����Ϣ����"<<endl; 
					getch();
				}
			}
		}
		o[0]=0; 
	}
	if(stu.size()>0) file::output(1);
	system("cls");
	system("title ѧ���ɼ�����ϵͳ-�����˳�"); 
	load();
	system("title ѧ���ɼ�����ϵͳ-�����˳�"); 
	Sleep(1000);
	return 0; 
}

BOOL CtrlHandler(DWORD fdwCtrlType)
{
    switch (fdwCtrlType)
    {
        /* handle the CTRL-C signal */
    case CTRL_C_EVENT:
        Beep(750, 300);
		return TRUE; 
 
        /* handle the CTRL-BREAK signal */
    case CTRL_BREAK_EVENT:
        Beep(750, 300);
		return TRUE; 
 
        /* handle the CTRL-CLOSE signal */
    case CTRL_CLOSE_EVENT:
		//����˹رմ��ڼ�
        Beep(750, 300);
		if(stu.size()>0) file::output(1);
		if(MessageBox(NULL,"��ȷ��Ҫ����ϵͳ���˳�ϵͳ�𣿣������˳�������������","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES){
			system("cls");
			system("title ѧ���ɼ�����ϵͳ-�����˳�"); 
			load();
	    	cout<<endl<<"�����˳�......"<<endl; 
			system("title ѧ���ɼ�����ϵͳ-�����˳�"); 
			Sleep(1000);
			exit(0); 
		}
		else system("SAMS_zh-cn.exe");
 
        /* handle the CTRL-LOGOFF signal */
    case CTRL_LOGOFF_EVENT:
        Beep(750, 300);
		if(stu.size()>0) file::output(1);
		if(MessageBox(NULL,"��ȷ��Ҫ����ϵͳ���˳�ϵͳ�𣿣������˳�������������","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES){
			system("cls");
			system("title ѧ���ɼ�����ϵͳ-�����˳�"); 
			load();
	    	cout<<endl<<"�����˳�......"<<endl; 
			system("title ѧ���ɼ�����ϵͳ-�����˳�"); 
			Sleep(1000);
			exit(0); 
		}
		else system("SAMS_zh-cn.exe");
 
        /* handle the CTRL-SHUTDOWN signal */
    case CTRL_SHUTDOWN_EVENT:
        Beep(750, 300);
		if(stu.size()>0) file::output(1);
		if(MessageBox(NULL,"��ȷ��Ҫ����ϵͳ���˳�ϵͳ�𣿣������˳�������������","ѧ���ɼ�����ϵͳ",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL|MB_SETFOREGROUND)==IDYES){
			system("cls");
			system("title ѧ���ɼ�����ϵͳ-�����˳�"); 
			load();
	    	cout<<endl<<"�����˳�......"<<endl; 
			system("title ѧ���ɼ�����ϵͳ-�����˳�"); 
			Sleep(1000);
			exit(0); 
		}
		else system("SAMS_zh-cn.exe");
 
    default:
        return FALSE;
    }
}
