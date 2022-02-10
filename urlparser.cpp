#include <iostream>
#include <string>

enum class State {
	Scheme,
	Authority1,
	Authority2,
	Path,
};

int main()
{
	std::string buf;
	std::string scheme;
	std::string authority;
	std::string path;
	State state = State::Scheme;
	// prompt user the URL
	std::cout << "Please enter a URL: ";
	getline(std::cin, buf);
	// analyzer
	for (auto &ch : buf) {
		if (state == State::Scheme) {
			if (ch == '/') {
				state = State::Authority1;
				authority += ch;
			} else {
				scheme += ch;
			}
		} else if (state == State::Authority1) {
			state = State::Authority2;
			authority += ch;
		} else if (state == State::Authority2) {
			if (ch == '/') {
				state = State::Path;
				path += ch;
			} else {
				authority += ch;
			}
		} else if (state == State::Path) {
			path += ch;
		}
	}
	// output result
	std::cout << "scheme = " << scheme << '\n';
	std::cout << "authority = " << authority << '\n';
	std::cout << "path = " << path << '\n';
	return 0;
}
