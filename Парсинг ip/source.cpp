#include <fstream>
#include <iostream>
#include <string>
#include <set>

int main(int argc, char* argv[]) {
	std::string path = "in.txt";
	std::fstream ifile(path);
	if (!ifile.is_open()) {
		std::cout << "unknown where is infile\n";
		std::cout << path;
	}
	std::string line;
	std::string ans = "";
	std::set<std::string> s;
	while (std::getline(ifile,line) && !ifile.eof()) {
		std::string ip;
		for (int i = 0; i < line.size(); ++i) {
			if (line[i] == '-') {
				i += 2;
				while (line[i] != ')') {
					ip.push_back(line[i]);
					i++;
				}
				break;
			}
		}
		if (ip.size() == 0) break;
		s.insert(ip);
	}
	for (auto i : s) {
		ans += (i + "/24\n" + i + "/443\n");
	}
	ifile.close();
	ifile.open("out.txt");
	if (!ifile.is_open()) {
		std::cout << "unknown where is outfile\n";
	}
	ifile.clear();
	ifile << ans;
	ifile.close();
}