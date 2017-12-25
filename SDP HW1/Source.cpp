#include <iostream>
#include "LinkedList.h"

const int COMMAND_BUFFER = 8;
const int URL_BUFFER = 50000;

int main() {
	LinkedList list;

	for (;;) {

		//COMMAND
		char buffer[COMMAND_BUFFER];
		std::cin >> buffer;
		int size = strlen(buffer);

		if (!strcmp(buffer, "PRINT")) {
			list.print();
			continue;

		} else if (!strcmp(buffer, "BACK")) {
			list.back();
			continue;

		} else if (!strcmp(buffer, "FORWARD")) {
			list.forward();
			continue;

		} else if (!strcmp(buffer, "REMOVE")) {
			list.remove();
			continue;

		} else if (!strcmp(buffer, "GO")) {

			//URL
			char urlBuffer[URL_BUFFER];
			std::cin.getline(urlBuffer, URL_BUFFER);
			size = strlen(urlBuffer) + 1;

			char* str = new char[size];
			for (int i = 0; i < size; ++i) {
				str[i] = urlBuffer[i];
			}

			list.go(str);
			continue;

		} else if (!strcmp(buffer, "INSERT")) {

			//URL
			char urlBuffer[URL_BUFFER];
			std::cin.getline(urlBuffer, URL_BUFFER);
			size = strlen(urlBuffer) + 1;

			char* str = new char[size];
			for (int i = 0; i < size; ++i) {
				str[i] = urlBuffer[i];
			}

			list.insert(str);
			continue;

		}  else if(!strcmp(buffer, "EXIT")) {
			break;
		}
	}
	
	return 0;

}