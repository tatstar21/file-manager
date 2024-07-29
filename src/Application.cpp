#include <iostream>
#include "FileManager.h"
#include <system_error>

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Файловый Менеджер:" << "\n"
		"1 Показать содержимое диска.\n"
		"2 Создать папку.\n"
		"3 Создать файл.\n"
		"4 Удалить папку.\n"
		"5 Удалить файл.\n"
		"6 Переименовать папку.\n"
		"7 Переименовать файл.\n"
		"8 Скопировать папку.\n"
		"9 Скопировать файл.\n"
		"10 Вычислить размер папки.\n"
		"11 Вычислить размер файла.\n"
		"12 Произвести поиск по маске\n"
		"Другое - Выход\n";

	std::cout << "\nВведите пункт меню: ";
	int menuItem;
	std::cin >> menuItem;
	std::cin.ignore();

	std::string path;
	std::string newNameFolderOrFile;
	std::string newPath;
	std::string mask;
	FileManager fileManager;

	switch (menuItem)
	{
	case 1:
		std::cout << "Показать содержимое диска:\n";
		std::cout << "Введите путь к диску:\n";
		std::getline(std::cin, path);
		fileManager.showContentsOfTheDisc(path);
		break;

	case 2:
		std::cout << "Создать папку:\n";
		std::cout << "Введите путь к создаваемой папке:\n";
		std::getline(std::cin, path);
		fileManager.createFolder(path);
		break;

	case 3:
		std::cout << "Создать файл:\n";
		std::cout << "Введите путь к создаваемому файлу:\n";
		std::getline(std::cin, path);
		fileManager.createFile(path);
		break;

	case 4:
		std::cout << "Удалить папку:\n";
		std::cout << "Введите путь к удаляемой папке:\n";
		std::getline(std::cin, path);
		fileManager.deleteFolder(path);
		break;

	case 5:
		std::cout << "Удалить файл:\n";
		std::cout << "Введите путь к удаляемому файлу:\n";
		std::getline(std::cin, path);
		fileManager.deleteFile(path);
		break;

	case 6:
		std::cout << "Переименовать папку:\n";
		std::cout << "Введите путь к папке, которую хотите переименовать:\n";
		std::getline(std::cin, path);
		std::cout << "Введите новое имя папки:\n";
		std::getline(std::cin, newNameFolderOrFile);
		fileManager.renameFolder(path, newNameFolderOrFile);
		break;

	case 7:
		std::cout << "Переименовать файл:\n";
		std::cout << "Введите путь к файлу, который хотите переименовать:\n";
		std::getline(std::cin, path);
		std::cout << "Введите новое имя файла:\n";
		std::getline(std::cin, newNameFolderOrFile);
		fileManager.renameFile(path, newNameFolderOrFile);
		break;

	case 8:
		std::cout << "Скопировать папку:\n";
		std::cout << "Введите путь откуда копировать папку:\n";
		std::getline(std::cin, path);
		std::cout << "Введите путь куда копировать папку:\n";
		std::getline(std::cin, newPath);
		fileManager.copyFolder(path, newPath);
		break;

	case 9:
		std::cout << "Скопировать файл:\n";
		std::cout << "Введите путь откуда копировать файл:\n";
		std::getline(std::cin, path);
		std::cout << "Введите путь куда копировать файл:\n";
		std::getline(std::cin, newPath);
		fileManager.copyFile(path, newPath);
		break;

	case 10:
		std::cout << "Вычислить размер папки:\n";
		std::cout << "Введите путь к папке размер которой хотите узнать:\n";
		std::getline(std::cin, path);
		std::cout <<  fileManager.getFolderSize(path);
		break;

	case 11:
		std::cout << "Вычислить размер файла:\n";
		std::cout << "Введите путь к файлу размер которого хотите узнать:\n";
		std::getline(std::cin, path);
		std::cout << fileManager.getFileSize(path);
		break;

	case 12:
		std::cout << "Произвести поиск по маске:\n";
		std::cout << "Введите путь где хотите найти файлы:\n";
		std::getline(std::cin, path);
		std::cout << "Введите маску по которой хотите найти файлы:\n";
		std::getline(std::cin, mask);
		fileManager.searchByMask(path, mask);
		break;

	default:
		std::cout << "Выход из программы:\n";
		break;
	}

	/*std::string path = "C:\\Users\\tanya\\OneDrive\\Рабочий стол\\text.txt";
	FileManager fileManager;
	fileManager.showContentsOfTheDisc("C:");
	fileManager.createFolder(path);
	fileManager.createFile("C:\\Users\\tanya\\OneDrive\\Рабочий стол\\FILE.txt");
	fileManager.deleteFolder("C:\\Users\\tanya\\OneDrive\\Рабочий стол\\TEST");
	fileManager.deleteFile("C:\\Users\\tanya\\OneDrive\\Рабочий стол\\FILE.txt");
	size_t size = fileManager.getFileSize(path);
	std::cout << "SIZE_FILE: " << size << '\n';
	size_t sizeFolder = fileManager.getFolderSize("C:\\Users\\tanya\\OneDrive\\Рабочий стол\\Examination");
	std::cout << "SIZE_FOLDER: " << sizeFolder << std::endl;
	fileManager.searchByMask("C:\\Users\\tanya\\OneDrive\\Рабочий стол", ".*\\.txt");*/

}

