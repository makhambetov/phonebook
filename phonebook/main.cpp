/*Создать приложение "Телефонная книга". Необходимо
хранить данные об абоненте (ФИО, домашний телефон,
рабочий телефон, мобильный телефон, дополнительная
информация о контакте) внутри соответствующего клас-
са. Наполните класс переменными-членами, функция-
ми-членами, конструкторами, inline-функциями-членами,
используйте инициализаторы, реализуйте деструктор.
Обязательно необходимо выделять динамически память
под ФИО. Предоставьте пользователю возможность до-
бавлять новых абонентов, удалять абонентов, искать або-
нентов по ФИО, показывать всех абонентов, сохранять
информацию в файл и загружать из файла.*/

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;
void SetColor(WORD wAttributes){// функция для смена цвета
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
	//метод для создания объекта:
	void Edit()
	{
		/*
		m_nID = 0;
		int len = strlen("Абонент");
		m_pszName = new char[len+1];
		strcpy(m_pszName, "Абонент");
		strcpy(m_szHomePhone, "xxx-xx-xx");
		strcpy(m_szOfficePhone, "xxx-xx-xx");
		strcpy(m_szMobilePhone, "+7-xxx-xxx-xx-xx");
		len = strlen("info");
		m_pszInfo = new char[len+1];
		strcpy(m_pszInfo, "info");
		*/
		m_nID = g_nID + 1;				//присваиваем уникальный номер абоненту
		g_nID++;
		cin.get();
		cout << "Введите имя абонента: ";
//		cin.getline(m_pszName, 65);
		char *tmp = new char[65];		//объявляем временную строку
		cin.getline(tmp, 65);			//сохраняем временную строку
//		int len = strlen(tmp);			//определяем длину врем. строки
//		m_pszName = new char[len+1];	//выделяем память для ИМЕНИ абонента
		strcpy(m_pszName, tmp);			//копируем из временной строки в ИМЯ
		tmp = nullptr;					//обнуляем врем. строку

		cout << "Введите домашний телефон абонента: ";
		tmp = new char[65];
		cin.getline(tmp, 65);
		int len = strlen(tmp);
		while(len > 9){
			cout << "Ошибка! Введите до 9 символов: ";
			tmp = nullptr;
			tmp = new char[65];
			cin.getline(tmp, 65);
			len = strlen(tmp);
		}
		strcpy(m_szHomePhone, tmp);
		tmp = nullptr;

		cout << "Введите рабочий телефон абонента: ";
		tmp = new char[65];
		cin.getline(tmp, 65);
		len = strlen(tmp);
		while(len > 9){
			cout << "Ошибка! Введите до 9 символов: ";
			tmp = nullptr;
			tmp = new char[65];
			cin.getline(tmp, 65);
			len = strlen(tmp);
		}
		strcpy(m_szOfficePhone, tmp);
		tmp = nullptr;

		cout << "Введите мобильный телефон абонента: ";
		tmp = new char[65];
		cin.getline(tmp, 65);
		len = strlen(tmp);
		while(len > 16){
			cout << "Ошибка! Введите до 16 символов: ";
			tmp = nullptr;
			tmp = new char[65];
			cin.getline(tmp, 65);
			len = strlen(tmp);
		}		
		strcpy(m_szMobilePhone, tmp);
		tmp = nullptr;

		cout << "Введите дополнительную информацию : ";
		tmp = new char[65];
		cin.getline(tmp, 500);			//сохраняем временную строку
		len = strlen(tmp);				//определяем длину врем. строки
//		m_pszInfo = new char[len+1];	//выделяем память для ИМЕНИ абонента
		strcpy(m_pszInfo, tmp);			//копируем из временной строки в ИМЯ
		delete [] tmp;
	}
	//метод для редактирования объекта:
	void Edit(int id)
	{
		m_nID = id;				//присваиваем уникальный номер абоненту
		cin.get();
		cout << "Введите имя абонента: ";
//		cin.getline(m_pszName, 65);
		char *tmp = new char[65];		//объявляем временную строку
		cin.getline(tmp, 65);			//сохраняем временную строку
//		int len = strlen(tmp);			//определяем длину врем. строки
//		m_pszName = new char[len+1];	//выделяем память для ИМЕНИ абонента
		strcpy(m_pszName, tmp);			//копируем из временной строки в ИМЯ
		tmp = nullptr;					//обнуляем врем. строку

		cout << "Введите домашний телефон абонента: ";
		tmp = new char[65];
		cin.getline(tmp, 65);
		int len = strlen(tmp);
		while(len > 9){
			cout << "Ошибка! Введите до 9 символов: ";
			tmp = nullptr;
			tmp = new char[65];
			cin.getline(tmp, 65);
			len = strlen(tmp);
		}
		strcpy(m_szHomePhone, tmp);
		tmp = nullptr;

		cout << "Введите рабочий телефон абонента: ";
		tmp = new char[65];
		cin.getline(tmp, 65);
		len = strlen(tmp);
		while(len > 9){
			cout << "Ошибка! Введите до 9 символов: ";
			tmp = nullptr;
			tmp = new char[65];
			cin.getline(tmp, 65);
			len = strlen(tmp);
		}
		strcpy(m_szOfficePhone, tmp);
		tmp = nullptr;

		cout << "Введите мобильный телефон абонента: ";
		tmp = new char[65];
		cin.getline(tmp, 65);
		len = strlen(tmp);
		while(len > 16){
			cout << "Ошибка! Введите до 16 символов: ";
			tmp = nullptr;
			tmp = new char[65];
			cin.getline(tmp, 65);
			len = strlen(tmp);
		}		
		strcpy(m_szMobilePhone, tmp);
		tmp = nullptr;

		cout << "Введите дополнительную информацию : ";
		tmp = new char[65];
		cin.getline(tmp, 500);			//сохраняем временную строку
		len = strlen(tmp);				//определяем длину врем. строки
//		m_pszInfo = new char[len+1];	//выделяем память для ИМЕНИ абонента
		strcpy(m_pszInfo, tmp);			//копируем из временной строки в ИМЯ
		delete [] tmp;
	}

	void Display()
	{
		cout << "ID " << m_nID << endl;
		cout << "Имя:\t\t\t" << m_pszName << endl;
		cout << "Домашний телефон:\t" << m_szHomePhone << endl;
		cout << "Рабочий телефон:\t" << m_szOfficePhone << endl;
		cout << "Мобильный телефон:\t" << m_szMobilePhone << endl;
		cout << "Доп. инфо.:\t\t" << m_pszInfo << endl;
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
		//cout << "Выберите:";
		//cout << "1. Домашний\n";
		//cout << "2. Рабочий\n";
		//cout << "3. Мобильный\n";
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
//		int len = strlen("Абонент");
//		m_pszName = new char[len+1];
//		strcpy(m_pszName, "Абонент");
//		strcpy(m_szHomePhone, "xxx-xx-xx");
//		strcpy(m_szOfficePhone, "xxx-xx-xx");
//		strcpy(m_szMobilePhone, "+7-xxx-xxx-xx-xx");
//		len = strlen("info");
//		m_pszInfo = new char[len+1];
//		strcpy(m_pszInfo, "info");
//		*/
//		m_nID = g_nID + 1;//присваиваем порядковый номер абоненту
//		g_nID++;
//		cin.get();
//		cout << "Введите имя абонента: ";
//		char *tmp = new char[65];			//объявляем временную строку
//		cin.getline(tmp, 65);			//сохраняем временную строку
//		int len = strlen(tmp);			//определяем длину врем. строки
//		m_pszName = new char[len+1];	//выделяем память для ИМЕНИ абонента
//		strcpy(m_pszName, tmp);			//копируем из временной строки в ИМЯ
//		tmp = nullptr;					//обнуляем врем. строку
//
//		cout << "Введите домашний телефон абонента: ";
//		tmp = new char[65];
//		cin.getline(tmp, 65);
//		len = strlen(tmp);
//		while(len > 9){
//			cout << "Ошибка! Введите до 9 символов: ";
//			tmp = nullptr;
//			tmp = new char[65];
//			cin.getline(tmp, 65);
//			len = strlen(tmp);
//		}
//		strcpy(m_szHomePhone, tmp);
//		tmp = nullptr;
//
//		cout << "Введите рабочий телефон абонента: ";
//		tmp = new char[65];
//		cin.getline(tmp, 65);
//		len = strlen(tmp);
//		while(len > 9){
//			cout << "Ошибка! Введите до 9 символов: ";
//			tmp = nullptr;
//			tmp = new char[65];
//			cin.getline(tmp, 65);
//			len = strlen(tmp);
//		}
//		strcpy(m_szOfficePhone, tmp);
//		tmp = nullptr;
//
//		cout << "Введите мобильный телефон абонента: ";
//		tmp = new char[65];
//		cin.getline(tmp, 65);
//		len = strlen(tmp);
//		while(len > 16){
//			cout << "Ошибка! Введите до 16 символов: ";
//			tmp = nullptr;
//			tmp = new char[65];
//			cin.getline(tmp, 65);
//			len = strlen(tmp);
//		}		
//		strcpy(m_szMobilePhone, tmp);
//		tmp = nullptr;
//
//		cout << "Введите дополнительную информацию : ";
//		tmp = new char[65];
//		cin.getline(tmp, 500);			//сохраняем временную строку
//		len = strlen(tmp);				//определяем длину врем. строки
//		m_pszInfo = new char[len+1];	//выделяем память для ИМЕНИ абонента
//		strcpy(m_pszInfo, tmp);			//копируем из временной строки в ИМЯ
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
	//strcpy(name, "Иван");
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
		cout << "\n\tТЕЛЕФОННАЯ КНИГА\n\n";
		SetColor(0xE);
		cout << "1. Добавить абонента\n";
		cout << "2. Вывод списка абонентов\n";
		cout << "3. Поиск абонента по ID\n";
		cout << "4. Поиск абонента по Имени\n";
		cout << "5. Поиск абонента по номеру\n";
		cout << "6. Удалить абонента по ID\n";
		cout << "7. Изменить абонента по ID\n";
		cout << "8. Сохранить\n";
		cout << "0. Выход\n";
		SetColor(0x7);
		cin >> menu;
		if (menu == 1){Abonent = CreateAbonent(Abonent, size);}
		else if (menu == 2){
			if (size == 0) cout << "Список пуст.";
			else{
				cout << "№  ID  Имя\t\tД.Тел\tРаб.Тел\tМоб.Тел.\tДоп. Инфо\n\n";
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

//добавление аюонента
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

//удаление абонента по ID
CAbonent * DeleteAbonent(CAbonent * Abonent, int &size){
	if(!Abonent) {
		cout << "Нет абонентов к удалению. Список пуст.\n";
		cin.get();
	}
	else{
		cout << "Введите ID абонента для удаления: ";
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
			cout << "Абонент " << Abonent[ind].GetName() << " удален.";
			cin.get();
			if (size == 0) return nullptr;
			else {
				delete [] Abonent;
				return tmp;
			}
		}
		else {
			cout << "Абонент с таким ID не найден.";
			cin.get();
			return Abonent;
		}
	}
}

//поиск по ID
void SearchID(CAbonent *Abonent, int size){
	if(Abonent){
		cout << "Введите ID абонента: ";
		int nID; cin >> nID;
		for(int i = 0; i < size; i++){
			if (Abonent[i].GetID() == nID)
				Abonent[i].Display(); 
		}
	}
	else cout << "Список пуст.";
	cin.get();

}

//поиск по имени
void SerchByName(CAbonent * Abonent, int size){
	if(Abonent){
		cout << "Введите Имя абонента: ";
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
		if(!bFound) cout << "Абонент не найден.";
	}
	else cout << "Список пуст.";
}

//поиск по номеру
void SerchByNumber(CAbonent * Abonent, int size){
	if(Abonent){
		cout << "Выберите:\n";
		cout << "1. Домашний\n";
		cout << "2. Рабочий\n";
		cout << "3. Мобильный\n";
		int menu = 1;
		char * sNumber = new char[17];
		do{
			cin >> menu;
			if (menu >= 1 && menu <= 3){
				cout << "Введите номер: "; cin.get();
				cin.getline(sNumber, 17);
			}
			else cout << "Ошибка! Введите от 1 до 3\n";
		}while (menu < 1 || menu > 3);
		bool bFound = false;
		for(int i = 0; i < size; i++){
			if (!stricmp(Abonent[i].GetNumber(menu), sNumber)){
				Abonent[i].Display();
				bFound = true;
			}
		}
		if(!bFound) cout << "\nАбонент не найден.";
	}
	else cout << "Список пуст.";
	cin.get();
}

//редактирование абонента
void EditAbonent(CAbonent * Abonent, int size){
	if(Abonent){
		cout << "Введите ID абонента: ";
		int nID; cin >> nID;
		for(int i = 0; i < size; i++){
			if (Abonent[i].GetID() == nID)
				Abonent[i].Edit(nID); 
		}
	}
	else cout << "Список пуст.";
}

//функция чтения с файла
CAbonent * ReadFile(CAbonent * Abonent, int &size){
	fin.open("phonebook.txt");
	int nBlock = 10;
	if(fin.is_open()){
		char * bu = new char[nBlock];
		char * buf = new char[600];
		for (int i = 0; i < 600; i++) {buf[i] = 0;}

		//считывание файла в массив buf:
		do{
			for (int i = 0; i < nBlock; i++) {bu[i] = 0;}
			fin.read(bu, nBlock-1);
			for (int i = 0; i < nBlock-1; i++) {
				if (bu[i] == '\n') {size++;}
			}
			buf = strcat(buf, bu);
		}while(!fin.eof());
		size -= 2;

		//проверка наличия записей
		if(size > 0) {
//			Abonent = new CAbonent [size];
			CAbonent * tmp = new CAbonent[size]; 
			char * pStartOfLine = (strstr(buf, "\n\n")) + 2;
			char  pIdAdr[2]; 
			for (int j = 0; j < 2; j++) {pIdAdr[j] = 0;}//обнуляем pIdAdr
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
				for (int j = 0; j < 2; j++) {pIdAdr[j] = 0;}//обнуляем pIdAdr
				strncat(pIdAdr, pTmpLine, 1);
				g_nID = atoi(pIdAdr);
				tmp[i].SetID(pIdAdr);

				pTmpLine = pStartOfLine + 6;
				tab = strchr(pTmpLine, '\t');
				int nLen = tab - pTmpLine;
				for (int j = 0; j < 65; j++) {pName[j] = 0;}//обнуляем pName
				strncat(pName, pTmpLine, nLen);
				tmp[i].SetName(pName);
			

				int t = strlen(tmp[i].GetName());
				pTmpLine = pTmpLine + t + 2;
				tab = strchr(pTmpLine, '\t');
				nLen = tab - pTmpLine;
				for (int j = 0; j < 17; j++) {pNumber[j] = 0;}//обнуляем pNumber
				strncat(pNumber, pTmpLine, nLen);
				tmp[i].SetNumber(pNumber, 1);
				

				pTmpLine = pTmpLine + (strlen(tmp[i].GetNumber(1))) + 1;
				tab = strchr(pTmpLine, '\t');
				nLen = tab - pTmpLine;
				for (int j = 0; j < 17; j++) {pNumber[j] = 0;}//обнуляем pNumber
				strncat(pNumber, pTmpLine, nLen);
				tmp[i].SetNumber(pNumber, 2);
				

				pTmpLine = pTmpLine + (strlen(tmp[i].GetNumber(2))) + 1;
				tab = strchr(pTmpLine, '\t');
				nLen = tab - pTmpLine;
				for (int j = 0; j < 17; j++) {pNumber[j] = 0;}//обнуляем pNumber
				strncat(pNumber, pTmpLine, nLen);
				tmp[i].SetNumber(pNumber, 3);

				pTmpLine = pTmpLine + (strlen(tmp[i].GetNumber(3))) + 1;
				tab = strchr(pTmpLine, '\n');
				nLen = tab - pTmpLine;
				for (int j = 0; j < 65; j++) {pInfo[j] = 0;}//обнуляем pInfo
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
		cout << "Ошибка: Файл не найден!";
		return Abonent;
		cin.get();
	}
	fin.close();
}

//функция сохранения в файл
void SaveToFile(CAbonent * Abonent, int size){
	
	fout.open("phonebook.txt");
	cin.ignore();
	if(Abonent){
		fout << "№  ID  Имя\t\tД.Тел\tРаб.Тел\tМоб.Тел.\tДоп. Инфо\n\n";
		for(int i = 0; i < size; i++){
			fout << i+1 <<"  " << Abonent[i].GetID() << "  " << Abonent[i].GetName() 
				<< "\t\t" << Abonent[i].GetNumber(1) << "\t" << Abonent[i].GetNumber(2)
				<< "\t" << Abonent[i].GetNumber(3) << "\t" << Abonent[i].GetInfo() << "\n";
		}
		fout.close();
		cout << "Сохранено в файл phonebook.txt";
	}
	else{
	fout << "№  ID  Имя\t\tД.Тел\tРаб.Тел\tМоб.Тел.\tДоп. Инфо\n\n";
	fout.close();
	cout << "Список пуст.";
	}
}