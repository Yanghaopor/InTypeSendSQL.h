#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <stack> //栈
#include <map>

namespace ICSQL{

class Var {
std::stack<std::string>T_DEX;//进制存储栈

public:
	//类型定义
	int Int;
	double Double;
	bool Bool;
	std::wstring Wstring;
	std::string String;
	char Char;

	//指针类型
	int *Int_f;
	double *Double_f;
	bool *Bool_f;
	std::wstring *Wstring_f;
	std::string *String_f;
	char* Char_f;

public:
	//指针类型指向自己
	void Fpont_Self() { 
		this->Int_f = &this->Int;
		this->Double_f = &this->Double;
		this->Bool_f = &this->Bool;
		this->String_f = &this->String;
		this->Wstring_f = &this->Wstring;
		this->Char_f = &this->Char;
	}

	//初始化;
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

	//查看所有设置
	void D_bug() {

		Var *myP  = this; //获取当前地址
		double Menu = sizeof(this);//获取类型大小
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

		std::cout << std::endl; //地址显示
		
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

	//算法优化
	private:
		//栈初始化
		void InitStack() {

			while (!this->T_DEX.empty()) {
				this->T_DEX.pop();

			}
		}

	public:
		//二进制转换（转换数，存储数）不包含小数
		void Turn_binary(int tobe,std::string *Mube) {
			this->InitStack();//栈初始化

			while (true) {
				this->T_DEX.push(std::to_string(tobe % 2)); //整数类型的二进制转换
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
			this->InitStack();//栈初始化
		}

		//自动排序（需要排序的数，trun正序false倒序,大小）仅支持数字类型
		void Automatic_sorting(double A[],bool Be,int Nme) {
			int LinesMin = 0;//内部赋予
			int LinesMax = Nme-1;

			std::map<double,std::string>MAsp; //使用红黑数
			for (int i = 0; i < Nme; i++) {		//进行排序
				MAsp.insert(std::pair<double, std::string>(A[i], ""));
			}

			//确认倒序
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
	


		///第二部分
};
	


}