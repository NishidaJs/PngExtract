#include <iostream> 
#include <fstream>
#include <filesystem>
#include <vector>
#include <iterator>
namespace fs = std::experimental::filesystem;

int main() {
	std::string path = "C:/Users/user/Pictures/source/ziye"; //解压后的文件夹名字
	for (const auto & entry : fs::directory_iterator(path)) {
		//std::string filename = entry.path();
		std::ifstream f(entry.path(), std::ios::binary);
		char c, d;
		f.seekg(0x18);
		f.get(c);
		f.get(d);
		if (c == (char)0xff && d == (char)0xd8) {
			//f.close();
			std::ofstream of(entry.path().string() + ".png", std::ios::binary);
			f.seekg(0x20, std::ios::beg);
			of.put(char(0x89));
			of.put(char(0x50));
			of.put(char(0x4E));
			of.put(char(0x47));
			of.put(char(0x0D));
			of.put(char(0x0A));
			of.put(char(0x1A));
			of.put(char(0x0A));
			while (!f.eof()) {
				char in;
				f.get(in);
				of<<in;
			}
			of.close();
		}
		else {
		if ((c == (char)0x89 && d == (char)0x50)) {
				std::ofstream of(entry.path().string() + ".png", std::ios::binary);
				f.seekg(0x20, std::ios::beg);
				of.put(char(0x89));
				of.put(char(0x50));
				of.put(char(0x4E));
				of.put(char(0x47));
				of.put(char(0x0D));
				of.put(char(0x0A));
				of.put(char(0x1A));
				of.put(char(0x0A));
				while (!f.eof()) {
					char in;
					f.get(in);
					of << in;
				}
				of.close();
			}
			else {
				f.close();
				std::cout << "PNG";
			}
		std::cout << "";
	}
	system("PAUSE");
	}
