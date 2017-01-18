/*������� ���������� "���������� �����". ����������
������� ������ �� �������� (���, �������� �������,
������� �������, ��������� �������, ��������������
���������� � ��������) ������ ���������������� ����-
��. ��������� ����� �����������-�������, �������-
��-�������, ��������������, inline-���������-�������,
����������� ��������������, ���������� ����������.
����������� ���������� �������� ����������� ������
��� ���. ������������ ������������ ����������� ��-
������� ����� ���������, ������� ���������, ������ ���-
������ �� ���, ���������� ���� ���������, ���������
���������� � ���� � ��������� �� �����.*/

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;
void SetColor(WORD wAttributes){// ������� ��� ����� �����
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOUTPUT,wAttributes);
}


int g_nID = 0;

class CAbonent
{
private:
	int	   m_nID;
	char   m_pszName[65];
	char   m_szHomePhone[10];
	char   m_szOfficePhone[10];
	char   m_szMobilePhone[17];
	char   m_pszInfo[65];

public:
	CAbonent(){};
	~CAbonent()
	{
		//if(m_pszName) {delete [] m_pszName;}
		//if(m_pszInfo) {delete [] m_pszInfo;}
	}

	CAbonent(char *name, char hphone[10], char ofphone[10], char mphone[17], char *info = "-")
	{
		m_nID = g_nID + 1;
		g_nID++;
		if(name){
//			int len = strlen(name);
//			m_pszName = new char[len+1];
			strcpy(m_pszName, name);
		}
		
		strcpy(m_szHomePhone, hphone);
		strcpy(m_szOfficePhone, ofphone);
		strcpy(m_szMobilePhone, mphone);
		if(info){
			int len = strlen(info);
			
//			m_pszInfo = new char[len+1];
			strcpy(m_pszInfo, info);
		}
	}
	//����� ��� �������� �������:
	void Edit()
	{
		/*
		m_nID = 0;
		int len = strlen("�������");
		m_pszName = new char[len+1];
		strcpy(m_pszName, "�������");
		strcpy(m_szHomePhone, "xxx-xx-xx");
		strcpy(m_szOfficePhone, "xxx-xx-xx");
		strcpy(m_szMobilePhone, "+7-xxx-xxx-xx-xx");
		len = strlen("info");
		m_pszInfo = new char[len+1];
		strcpy(m_pszInfo, "info");
		*/
		m_nID = g_nID + 1;				//����������� ���������� ����� ��������
		g_nID++;
		cin.get();
		cout << "������� ��� ��������: ";
//		cin.getline(m_pszName, 65);
		char *tmp = new char[65];		//��������� ��������� ������
		cin.getline(tmp, 65);			//��������� ��������� ������
//		int len = strlen(tmp);			//���������� ����� ����. ������
//		m_pszName = new char[len+1];	//�������� ������ ��� ����� ��������
		strcpy(m_pszName, tmp);			//�������� �� ��������� ������ � ���
		tmp = nullptr;					//�������� ����. ������

		cout << "������� �������� ������� ��������: ";
		tmp = new char[65];
		cin.getline(tmp, 65);
		int len = strlen(tmp);
		while(len > 9){
			cout << "������! ������� �� 9 ��������: ";
			tmp = nullptr;
			tmp = new char[65];
			cin.getline(tmp, 65);
			len = strlen(tmp);
		}
		strcpy(m_szHomePhone, tmp);
		tmp = nullptr;

		cout << "������� ������� ������� ��������: ";
		tmp = new char[65];
		cin.getline(tmp, 65);
		len = strlen(tmp);
		while(len > 9){
			cout << "������! ������� �� 9 ��������: ";
			tmp = nullptr;
			tmp = new char[65];
			cin.getline(tmp, 65);
			len = strlen(tmp);
		}
		strcpy(m_szOfficePhone, tmp);
		tmp = nullptr;

		cout << "������� ��������� ������� ��������: ";
		tmp = new char[65];
		cin.getline(tmp, 65);
		len = strlen(tmp);
		while(len > 16){
			cout << "������! ������� �� 16 ��������: ";
			tmp = nullptr;
			tmp = new char[65];
			cin.getline(tmp, 65);
			len = strlen(tmp);
		}		
		strcpy(m_szMobilePhone, tmp);
		tmp = nullptr;

		cout << "������� �������������� ���������� : ";
		tmp = new char[65];
		cin.getline(tmp, 500);			//��������� ��������� ������
		len = strlen(tmp);				//���������� ����� ����. ������
//		m_pszInfo = new char[len+1];	//�������� ������ ��� ����� ��������
		strcpy(m_pszInfo, tmp);			//�������� �� ��������� ������ � ���
		delete [] tmp;
	}
	//����� ��� �������������� �������:
	void Edit(int id)
	{
		m_nID = id;				//����������� ���������� ����� ��������
		cin.get();
		cout << "������� ��� ��������: ";
//		cin.getline(m_pszName, 65);
		char *tmp = new char[65];		//��������� ��������� ������
		cin.getline(tmp, 65);			//��������� ��������� ������
//		int len = strlen(tmp);			//���������� ����� ����. ������
//		m_pszName = new char[len+1];	//�������� ������ ��� ����� ��������
		strcpy(m_pszName, tmp);			//�������� �� ��������� ������ � ���
		tmp = nullptr;					//�������� ����. ������

		cout << "������� �������� ������� ��������: ";
		tmp = new char[65];
		cin.getline(tmp, 65);
		int len = strlen(tmp);
		while(len > 9){
			cout << "������! ������� �� 9 ��������: ";
			tmp = nullptr;
			tmp = new char[65];
			cin.getline(tmp, 65);
			len = strlen(tmp);
		}
		strcpy(m_szHomePhone, tmp);
		tmp = nullptr;

		cout << "������� ������� ������� ��������: ";
		tmp = new char[65];
		cin.getline(tmp, 65);
		len = strlen(tmp);
		while(len > 9){
			cout << "������! ������� �� 9 ��������: ";
			tmp = nullptr;
			tmp = new char[65];
			cin.getline(tmp, 65);
			len = strlen(tmp);
		}
		strcpy(m_szOfficePhone, tmp);
		tmp = nullptr;

		cout << "������� ��������� ������� ��������: ";
		tmp = new char[65];
		cin.getline(tmp, 65);
		len = strlen(tmp);
		while(len > 16){
			cout << "������! ������� �� 16 ��������: ";
			tmp = nullptr;
			tmp = new char[65];
			cin.getline(tmp, 65);
			len = strlen(tmp);
		}		
		strcpy(m_szMobilePhone, tmp);
		tmp = nullptr;

		cout << "������� �������������� ���������� : ";
		tmp = new char[65];
		cin.getline(tmp, 500);			//��������� ��������� ������
		len = strlen(tmp);				//���������� ����� ����. ������
//		m_pszInfo = new char[len+1];	//�������� ������ ��� ����� ��������
		strcpy(m_pszInfo, tmp);			//�������� �� ��������� ������ � ���
		delete [] tmp;
	}

	void Display()
	{
		cout << "ID " << m_nID << endl;
		cout << "���:\t\t\t" << m_pszName << endl;
		cout << "�������� �������:\t" << m_szHomePhone << endl;
		cout << "������� �������:\t" << m_szOfficePhone << endl;
		cout << "��������� �������:\t" << m_szMobilePhone << endl;
		cout << "���. ����.:\t\t" << m_pszInfo << endl;
	}
	void DisplayList()
	{
		cout << m_nID << "  " << m_pszName << "\t\t" << m_szHomePhone << "\t" ;
		cout << m_szOfficePhone << "\t" << m_szMobilePhone << "\t" << m_pszInfo << endl;
	}

	int    GetID()    {return m_nID;}
	char * GetName()  {return m_pszName;}
	char * GetNumber(int menu)
	{
		//cout << "��������:";
		//cout << "1. ��������\n";
		//cout << "2. �������\n";
		//cout << "3. ���������\n";
		//int menu; 
		do{
			//cin >> menu;
			if (menu == 1) return m_szHomePhone;
			else if (menu == 2) return m_szOfficePhone;
			else if (menu == 3) return m_szMobilePhone;
			
		}while(menu < 1 || menu > 3);
	}
	char * GetInfo() {return m_pszInfo;}

	void SetID(char * id){int n = atoi(id); m_nID = n; }
	void SetID(int id)	 {m_nID = id;}
	void SetName(char *name){
//		char * tab = strchr(name, '\t');
//		int NameLen = tab - name;
//		strncat(m_pszName, name, NameLen);
		strcpy(m_pszName, name);
	}
	void SetNumber(char * number, int type){
		if(type == 1){strcpy(m_szHomePhone, number);}
		else if(type == 2){strcpy(m_szOfficePhone, number);}
		else if(type == 3){strcpy(m_szMobilePhone, number);}
	}
	void SetInfo(char * info){
		strcpy(m_pszInfo, info);
	}

};

//CAbonent Edit()
//	{
//		/*
//		m_nID = 0;
//		int len = strlen("�������");
//		m_pszName = new char[len+1];
//		strcpy(m_pszName, "�������");
//		strcpy(m_szHomePhone, "xxx-xx-xx");
//		strcpy(m_szOfficePhone, "xxx-xx-xx");
//		strcpy(m_szMobilePhone, "+7-xxx-xxx-xx-xx");
//		len = strlen("info");
//		m_pszInfo = new char[len+1];
//		strcpy(m_pszInfo, "info");
//		*/
//		m_nID = g_nID + 1;//����������� ���������� ����� ��������
//		g_nID++;
//		cin.get();
//		cout << "������� ��� ��������: ";
//		char *tmp = new char[65];			//��������� ��������� ������
//		cin.getline(tmp, 65);			//��������� ��������� ������
//		int len = strlen(tmp);			//���������� ����� ����. ������
//		m_pszName = new char[len+1];	//�������� ������ ��� ����� ��������
//		strcpy(m_pszName, tmp);			//�������� �� ��������� ������ � ���
//		tmp = nullptr;					//�������� ����. ������
//
//		cout << "������� �������� ������� ��������: ";
//		tmp = new char[65];
//		cin.getline(tmp, 65);
//		len = strlen(tmp);
//		while(len > 9){
//			cout << "������! ������� �� 9 ��������: ";
//			tmp = nullptr;
//			tmp = new char[65];
//			cin.getline(tmp, 65);
//			len = strlen(tmp);
//		}
//		strcpy(m_szHomePhone, tmp);
//		tmp = nullptr;
//
//		cout << "������� ������� ������� ��������: ";
//		tmp = new char[65];
//		cin.getline(tmp, 65);
//		len = strlen(tmp);
//		while(len > 9){
//			cout << "������! ������� �� 9 ��������: ";
//			tmp = nullptr;
//			tmp = new char[65];
//			cin.getline(tmp, 65);
//			len = strlen(tmp);
//		}
//		strcpy(m_szOfficePhone, tmp);
//		tmp = nullptr;
//
//		cout << "������� ��������� ������� ��������: ";
//		tmp = new char[65];
//		cin.getline(tmp, 65);
//		len = strlen(tmp);
//		while(len > 16){
//			cout << "������! ������� �� 16 ��������: ";
//			tmp = nullptr;
//			tmp = new char[65];
//			cin.getline(tmp, 65);
//			len = strlen(tmp);
//		}		
//		strcpy(m_szMobilePhone, tmp);
//		tmp = nullptr;
//
//		cout << "������� �������������� ���������� : ";
//		tmp = new char[65];
//		cin.getline(tmp, 500);			//��������� ��������� ������
//		len = strlen(tmp);				//���������� ����� ����. ������
//		m_pszInfo = new char[len+1];	//�������� ������ ��� ����� ��������
//		strcpy(m_pszInfo, tmp);			//�������� �� ��������� ������ � ���
//		delete [] tmp;
//	}

ifstream fin;
ofstream fout;

CAbonent * CreateAbonent(CAbonent * Abonent, int &size);
CAbonent * DeleteAbonent(CAbonent * Abonent, int &size);
void SearchID(CAbonent *Abonent, int size);
void SerchByName(CAbonent * Abonent, int size);
void SerchByNumber(CAbonent * Abonent, int size);
void EditAbonent(CAbonent * Abonent, int size);
void SaveToFile(CAbonent * Abonent, int size);
CAbonent * ReadFile(CAbonent * Abonent, int &size);

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	system("chcp 1251");
	system("cls");


	//CAbonent Abonent;
	//char *name = new char[5];
	//strcpy(name, "����");
	//CAbonent Abonent1(name, "287-33-44", "234-22-440", "+7-701-729-70-54", "--");
	//Abonent1.Display();
	//Abonent.Display();
	
	cout << endl;
	int size = 0;
	int menu;
	CAbonent *Abonent = nullptr;

	Abonent = ReadFile(Abonent, size);

	do {
		system("cls");
		SetColor(0xA);
		cout << "\n\t���������� �����\n\n";
		SetColor(0xE);
		cout << "1. �������� ��������\n";
		cout << "2. ����� ������ ���������\n";
		cout << "3. ����� �������� �� ID\n";
		cout << "4. ����� �������� �� �����\n";
		cout << "5. ����� �������� �� ������\n";
		cout << "6. ������� �������� �� ID\n";
		cout << "7. �������� �������� �� ID\n";
		cout << "8. ���������\n";
		cout << "0. �����\n";
		SetColor(0x7);
		cin >> menu;
		if (menu == 1){Abonent = CreateAbonent(Abonent, size);}
		else if (menu == 2){
			if (size == 0) cout << "������ ����.";
			else{
				cout << "�  ID  ���\t\t�.���\t���.���\t���.���.\t���. ����\n\n";
				for(int i = 0; i < size; i++){
					cout << i+1 << "  ";
					Abonent[i].DisplayList();
				}
			}
			cin.get();
		}
		else if (menu == 3){SearchID(Abonent, size);}
		else if (menu == 4){SerchByName(Abonent, size);}
		else if (menu == 5){SerchByNumber(Abonent, size);}
		else if (menu == 6){Abonent = DeleteAbonent(Abonent, size);}
		else if (menu == 7){EditAbonent(Abonent, size);}
		else if (menu == 8){SaveToFile(Abonent, size);}
		cin.get();
	} while (menu != 0);
}

//���������� ��������
CAbonent * CreateAbonent(CAbonent * Abonent, int &size){
	if(Abonent == nullptr) {
		Abonent = new CAbonent[1];
		Abonent[0].Edit();
		size++;
		return Abonent;
	}
	else {
		CAbonent * tmp = new CAbonent [size+1];
		for (int i = 0; i < size; i++){
			tmp[i] = Abonent[i];
		}
		tmp[size].Edit();
		size++;
		delete [] Abonent;
		return tmp;
	}
}

//�������� �������� �� ID
CAbonent * DeleteAbonent(CAbonent * Abonent, int &size){
	if(!Abonent) {
		cout << "��� ��������� � ��������. ������ ����.\n";
		cin.get();
	}
	else{
		cout << "������� ID �������� ��� ��������: ";
		int nID; cin >> nID;
		int ind = 0;
		bool isFound = false;
		for (int i = 0; i < size; i++){
			if (Abonent[i].GetID() == nID)
				isFound = true;
		}

		if(isFound){
			CAbonent * tmp = new CAbonent [size-1];
			for (int i = 0, j = 0; i < size-1; i++, j++){
				if (Abonent[j].GetID() != nID)
					tmp[i] = Abonent[j];
				else{
					tmp[i] = Abonent[++j];
					ind = i;
				}
			}
			size--;
			cout << "������� " << Abonent[ind].GetName() << " ������.";
			cin.get();
			if (size == 0) return nullptr;
			else {
				delete [] Abonent;
				return tmp;
			}
		}
		else {
			cout << "������� � ����� ID �� ������.";
			cin.get();
			return Abonent;
		}
	}
}

//����� �� ID
void SearchID(CAbonent *Abonent, int size){
	if(Abonent){
		cout << "������� ID ��������: ";
		int nID; cin >> nID;
		for(int i = 0; i < size; i++){
			if (Abonent[i].GetID() == nID)
				Abonent[i].Display(); 
		}
	}
	else cout << "������ ����.";
	cin.get();

}

//����� �� �����
void SerchByName(CAbonent * Abonent, int size){
	if(Abonent){
		cout << "������� ��� ��������: ";
		char * sName = new char[65];
		cin.get();
		cin.getline(sName, 64);
		bool bFound = false;
		for(int i = 0; i < size; i++){
			if (!stricmp(Abonent[i].GetName(), sName)){
				Abonent[i].Display();
				bFound = true;
			}
		}
		if(!bFound) cout << "������� �� ������.";
	}
	else cout << "������ ����.";
}

//����� �� ������
void SerchByNumber(CAbonent * Abonent, int size){
	if(Abonent){
		cout << "��������:\n";
		cout << "1. ��������\n";
		cout << "2. �������\n";
		cout << "3. ���������\n";
		int menu = 1;
		char * sNumber = new char[17];
		do{
			cin >> menu;
			if (menu >= 1 && menu <= 3){
				cout << "������� �����: "; cin.get();
				cin.getline(sNumber, 17);
			}
			else cout << "������! ������� �� 1 �� 3\n";
		}while (menu < 1 || menu > 3);
		bool bFound = false;
		for(int i = 0; i < size; i++){
			if (!stricmp(Abonent[i].GetNumber(menu), sNumber)){
				Abonent[i].Display();
				bFound = true;
			}
		}
		if(!bFound) cout << "\n������� �� ������.";
	}
	else cout << "������ ����.";
	cin.get();
}

//�������������� ��������
void EditAbonent(CAbonent * Abonent, int size){
	if(Abonent){
		cout << "������� ID ��������: ";
		int nID; cin >> nID;
		for(int i = 0; i < size; i++){
			if (Abonent[i].GetID() == nID)
				Abonent[i].Edit(nID); 
		}
	}
	else cout << "������ ����.";
}

//������� ������ � �����
CAbonent * ReadFile(CAbonent * Abonent, int &size){
	fin.open("phonebook.txt");
	int nBlock = 10;
	if(fin.is_open()){
		char * bu = new char[nBlock];
		char * buf = new char[600];
		for (int i = 0; i < 600; i++) {buf[i] = 0;}

		//���������� ����� � ������ buf:
		do{
			for (int i = 0; i < nBlock; i++) {bu[i] = 0;}
			fin.read(bu, nBlock-1);
			for (int i = 0; i < nBlock-1; i++) {
				if (bu[i] == '\n') {size++;}
			}
			buf = strcat(buf, bu);
		}while(!fin.eof());
		size -= 2;

		//�������� ������� �������
		if(size > 0) {
//			Abonent = new CAbonent [size];
			CAbonent * tmp = new CAbonent[size]; 
			char * pStartOfLine = (strstr(buf, "\n\n")) + 2;
			char  pIdAdr[2]; 
			for (int j = 0; j < 2; j++) {pIdAdr[j] = 0;}//�������� pIdAdr
			char * pTmpLine;
			char  pName [65];
			for (int i = 0; i < 65; i++) {pName[i] = 0;}
			char  pNumber[17];
			for (int i = 0; i < 17; i++) {pNumber[i] = 0;}
			char pInfo[65];
			for (int i = 0; i < 65; i++) {pInfo[i] = 0;}
			char * tab = nullptr;

			for (int i = 0; i < size; i++){
				pTmpLine = pStartOfLine + 3;
				for (int j = 0; j < 2; j++) {pIdAdr[j] = 0;}//�������� pIdAdr
				strncat(pIdAdr, pTmpLine, 1);
				g_nID = atoi(pIdAdr);
				tmp[i].SetID(pIdAdr);

				pTmpLine = pStartOfLine + 6;
				tab = strchr(pTmpLine, '\t');
				int nLen = tab - pTmpLine;
				for (int j = 0; j < 65; j++) {pName[j] = 0;}//�������� pName
				strncat(pName, pTmpLine, nLen);
				tmp[i].SetName(pName);
			

				int t = strlen(tmp[i].GetName());
				pTmpLine = pTmpLine + t + 2;
				tab = strchr(pTmpLine, '\t');
				nLen = tab - pTmpLine;
				for (int j = 0; j < 17; j++) {pNumber[j] = 0;}//�������� pNumber
				strncat(pNumber, pTmpLine, nLen);
				tmp[i].SetNumber(pNumber, 1);
				

				pTmpLine = pTmpLine + (strlen(tmp[i].GetNumber(1))) + 1;
				tab = strchr(pTmpLine, '\t');
				nLen = tab - pTmpLine;
				for (int j = 0; j < 17; j++) {pNumber[j] = 0;}//�������� pNumber
				strncat(pNumber, pTmpLine, nLen);
				tmp[i].SetNumber(pNumber, 2);
				

				pTmpLine = pTmpLine + (strlen(tmp[i].GetNumber(2))) + 1;
				tab = strchr(pTmpLine, '\t');
				nLen = tab - pTmpLine;
				for (int j = 0; j < 17; j++) {pNumber[j] = 0;}//�������� pNumber
				strncat(pNumber, pTmpLine, nLen);
				tmp[i].SetNumber(pNumber, 3);

				pTmpLine = pTmpLine + (strlen(tmp[i].GetNumber(3))) + 1;
				tab = strchr(pTmpLine, '\n');
				nLen = tab - pTmpLine;
				for (int j = 0; j < 65; j++) {pInfo[j] = 0;}//�������� pInfo
				strncat(pInfo, pTmpLine, nLen);
				tmp[i].SetInfo(pInfo);


				if(i < (size-1)) {pStartOfLine = (strchr(pTmpLine, '\n')) + 1;}
			}
//			delete [] pStartOfLine;
//			delete [] pIdAdr;
//			delete [] pTmpLine;
//			delete [] pName;
//			delete [] pNumber;
			return tmp;
		}
		return Abonent;
	}

	else{
		cout << "������: ���� �� ������!";
		return Abonent;
		cin.get();
	}
	fin.close();
}

//������� ���������� � ����
void SaveToFile(CAbonent * Abonent, int size){
	
	fout.open("phonebook.txt");
	cin.ignore();
	if(Abonent){
		fout << "�  ID  ���\t\t�.���\t���.���\t���.���.\t���. ����\n\n";
		for(int i = 0; i < size; i++){
			fout << i+1 <<"  " << Abonent[i].GetID() << "  " << Abonent[i].GetName() 
				<< "\t\t" << Abonent[i].GetNumber(1) << "\t" << Abonent[i].GetNumber(2)
				<< "\t" << Abonent[i].GetNumber(3) << "\t" << Abonent[i].GetInfo() << "\n";
		}
		fout.close();
		cout << "��������� � ���� phonebook.txt";
	}
	else{
	fout << "�  ID  ���\t\t�.���\t���.���\t���.���.\t���. ����\n\n";
	fout.close();
	cout << "������ ����.";
	}
}