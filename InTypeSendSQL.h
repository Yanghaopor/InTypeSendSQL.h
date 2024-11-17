#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <stack> //ջ
#include <map>

namespace ICSQL{

class Var {
std::stack<std::string>T_DEX;//���ƴ洢ջ

public:
	//���Ͷ���
	int Int;
	double Double;
	bool Bool;
	std::wstring Wstring;
	std::string String;
	char Char;

	//ָ������
	int *Int_f;
	double *Double_f;
	bool *Bool_f;
	std::wstring *Wstring_f;
	std::string *String_f;
	char* Char_f;

public:
	//ָ������ָ���Լ�
	void Fpont_Self() { 
		this->Int_f = &this->Int;
		this->Double_f = &this->Double;
		this->Bool_f = &this->Bool;
		this->String_f = &this->String;
		this->Wstring_f = &this->Wstring;
		this->Char_f = &this->Char;
	}

	//��ʼ��;
	void InitVar() { 
		this->Int = NULL;
		this->Int_f = NULL;
		this->Double = NULL;
		this->Double_f = NULL;
		this->Bool = NULL;
		this->Bool_f = NULL;
		this->Wstring = L"";
		this->Wstring_f = NULL;
		this->String = "";
		this->String_f = NULL;
		this->Char = NULL;
		this->Char_f = NULL;
	}

	//�鿴��������
	void D_bug() {

		Var *myP  = this; //��ȡ��ǰ��ַ
		double Menu = sizeof(this);//��ȡ���ʹ�С
		std::cout << "address:	" << myP << std::endl;
		std::cout << "storage:	" << Menu << std::endl;
		std::cout << std::endl;
		std::cout << "Data ALL Data To Ther" << std::endl;
		if (this->Int != NULL) {
			std::cout << "Int:" << "\t\t" << this->Int << std::endl;
		}
		else { std::cout << "Int:" << "\t\t" << "NULL" << std::endl; }

		if (this->Double != NULL) {
			std::cout << "Double:" << "\t\t" << this->Double << std::endl;
		}
		else { std::cout << "Double:" << "\t\t" << "NULL" << std::endl; }

		if (this->Bool != NULL) {
			std::cout << "Bool:" << "\t\t" << this->Bool << std::endl;
		}
		else { std::cout << "Bool:" << "\t\t" << "NULL" << std::endl; }

		if (this->Wstring != L"") {
			std::wcout << "Wstring:" << "\t" << this->Wstring << std::endl;
		}
		else { std::wcout << "Wstring:" << "\t" << "NULL" << std::endl; }

		if (this->String != "") {
			std::cout << "String:" << "\t\t" << this->String << std::endl;
		}
		else { std::cout << "String:" << "\t\t" << "NULL" << std::endl; }

		if (this->Char != NULL) {
			std::cout << "Char:" << "\t\t" << this->Char << std::endl;
		}
		else { std::cout << "Char:" << "\t\t" << "NULL" << std::endl; }

		std::cout << std::endl; //��ַ��ʾ
		
		std::cout << "Data address" << std::endl;

		if (this->Int_f != NULL) {
			std::cout << "Int_f:" << "\t\t" << this->Int_f << std::endl;
		}
		else { std::cout << "Int_f:" << "\t\t" << "NULL" << std::endl; }

		if (this->Double_f != NULL) {
			std::cout << "Double_f:" << "\t" << this->Double_f << std::endl;
		}
		else { std::cout << "Double_f:" << "\t" << "NULL" << std::endl; }

		if (this->Bool_f != NULL) {
			std::cout << "Bool_f:" << "\t\t" << this->Bool_f << std::endl;
		}
		else { std::cout << "Bool_f:" << "\t\t" << "NULL" << std::endl; }

		if (this->Wstring_f != NULL) {
			std::wcout << "Wstring:" << "\t" << this->Wstring_f << std::endl;
		}
		else { std::wcout << "Wstring_f:" << "\t" << "NULL" << std::endl; }

		if (this->String_f != NULL) {
			std::cout << "String_f:" << "\t" << this->String_f << std::endl;
		}
		else { std::cout << "String_f:" << "\t" << "NULL" << std::endl; }

		if (this->Char_f != NULL) {
			std::cout << "Char_f:" << "\t" << this->Char_f << std::endl;
		}
		else { std::cout << "Char_f:" << "\t" << "NULL" << std::endl; }

	}

	//�㷨�Ż�
	private:
		//ջ��ʼ��
		void InitStack() {

			while (!this->T_DEX.empty()) {
				this->T_DEX.pop();

			}
		}

	public:
		//������ת����ת�������洢����������С��
		void Turn_binary(int tobe,std::string *Mube) {
			this->InitStack();//ջ��ʼ��

			while (true) {
				this->T_DEX.push(std::to_string(tobe % 2)); //�������͵Ķ�����ת��
				tobe = tobe / 2;
				if (tobe == 1) {
					this->T_DEX.push(std::to_string(1));
					break;
				}
			}
			while (!this->T_DEX.empty()) {
				*Mube = *Mube + this->T_DEX.top();
				this->T_DEX.pop();
			}
			this->InitStack();//ջ��ʼ��
		}

		//�Զ�������Ҫ���������trun����false����,��С����֧����������
		void Automatic_sorting(double A[],bool Be,int Nme) {
			int LinesMin = 0;//�ڲ�����
			int LinesMax = Nme-1;

			std::map<double,std::string>MAsp; //ʹ�ú����
			for (int i = 0; i < Nme; i++) {		//��������
				MAsp.insert(std::pair<double, std::string>(A[i], ""));
			}

			//ȷ�ϵ���
			if (Be) {
				for (const auto & pair:MAsp) {
					A[LinesMin] = pair.first;
					LinesMin++;

				}
			}
			else
			{
				for (const auto& pair : MAsp) {
					A[LinesMax] = pair.first;
					LinesMax--;
				}
			}
			MAsp.clear();
		}
	


		///�ڶ�����
};
	


}