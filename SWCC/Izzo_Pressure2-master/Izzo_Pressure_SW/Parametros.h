#pragma once
#include <iostream>
#include <fstream>

namespace Parametros {
	//double zero = 0, constante = 1;
	System::Double zero = 190, constante = 1.13;
	//System::String write = "A";

	double ColAgua(int val) {
		return (val - zero) * (constante);
	}

	class teste {
	public:
		int x = 0, y = 1, z = 3;
		float f = 0.2345;
		//System::String teste = "arv";
	};

	//template <typename  T>
	//void SaveData(System::String^ filename, T data) {
	//	FILE *fout = fopen(filename, "w");
	//	fwrite(&data, sizeof(T), 1, fout);
	//	fclose(fout);

	//	/*std::ofstream file(filename);
	//	file << data;
	//	file.close();*/
	//}
	//template <typename  T>
	//T LoadData(System::String^ filename) {
	//	T* read_data = new T;
	//	FILE* fin = fopen(filename, "r");
	//	fread(&read_data, sizeof(T), 1, fin);
	//	fclose(fin);
	//	//void* data;
	//	//std::ifstream file(filename->ToCharArray());
	//	////std::ifstream file(filename);
	//	//file >> data;
	//	return data;
	//}
}