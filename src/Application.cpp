#include <iostream>
#include "FileManager.h"
#include <system_error>

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "�������� ��������:" << "\n"
		"1 �������� ���������� �����.\n"
		"2 ������� �����.\n"
		"3 ������� ����.\n"
		"4 ������� �����.\n"
		"5 ������� ����.\n"
		"6 ������������� �����.\n"
		"7 ������������� ����.\n"
		"8 ����������� �����.\n"
		"9 ����������� ����.\n"
		"10 ��������� ������ �����.\n"
		"11 ��������� ������ �����.\n"
		"12 ���������� ����� �� �����\n"
		"������ - �����\n";

	std::cout << "\n������� ����� ����: ";
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
		std::cout << "�������� ���������� �����:\n";
		std::cout << "������� ���� � �����:\n";
		std::getline(std::cin, path);
		fileManager.showContentsOfTheDisc(path);
		break;

	case 2:
		std::cout << "������� �����:\n";
		std::cout << "������� ���� � ����������� �����:\n";
		std::getline(std::cin, path);
		fileManager.createFolder(path);
		break;

	case 3:
		std::cout << "������� ����:\n";
		std::cout << "������� ���� � ������������ �����:\n";
		std::getline(std::cin, path);
		fileManager.createFile(path);
		break;

	case 4:
		std::cout << "������� �����:\n";
		std::cout << "������� ���� � ��������� �����:\n";
		std::getline(std::cin, path);
		fileManager.deleteFolder(path);
		break;

	case 5:
		std::cout << "������� ����:\n";
		std::cout << "������� ���� � ���������� �����:\n";
		std::getline(std::cin, path);
		fileManager.deleteFile(path);
		break;

	case 6:
		std::cout << "������������� �����:\n";
		std::cout << "������� ���� � �����, ������� ������ �������������:\n";
		std::getline(std::cin, path);
		std::cout << "������� ����� ��� �����:\n";
		std::getline(std::cin, newNameFolderOrFile);
		fileManager.renameFolder(path, newNameFolderOrFile);
		break;

	case 7:
		std::cout << "������������� ����:\n";
		std::cout << "������� ���� � �����, ������� ������ �������������:\n";
		std::getline(std::cin, path);
		std::cout << "������� ����� ��� �����:\n";
		std::getline(std::cin, newNameFolderOrFile);
		fileManager.renameFile(path, newNameFolderOrFile);
		break;

	case 8:
		std::cout << "����������� �����:\n";
		std::cout << "������� ���� ������ ���������� �����:\n";
		std::getline(std::cin, path);
		std::cout << "������� ���� ���� ���������� �����:\n";
		std::getline(std::cin, newPath);
		fileManager.copyFolder(path, newPath);
		break;

	case 9:
		std::cout << "����������� ����:\n";
		std::cout << "������� ���� ������ ���������� ����:\n";
		std::getline(std::cin, path);
		std::cout << "������� ���� ���� ���������� ����:\n";
		std::getline(std::cin, newPath);
		fileManager.copyFile(path, newPath);
		break;

	case 10:
		std::cout << "��������� ������ �����:\n";
		std::cout << "������� ���� � ����� ������ ������� ������ ������:\n";
		std::getline(std::cin, path);
		std::cout <<  fileManager.getFolderSize(path);
		break;

	case 11:
		std::cout << "��������� ������ �����:\n";
		std::cout << "������� ���� � ����� ������ �������� ������ ������:\n";
		std::getline(std::cin, path);
		std::cout << fileManager.getFileSize(path);
		break;

	case 12:
		std::cout << "���������� ����� �� �����:\n";
		std::cout << "������� ���� ��� ������ ����� �����:\n";
		std::getline(std::cin, path);
		std::cout << "������� ����� �� ������� ������ ����� �����:\n";
		std::getline(std::cin, mask);
		fileManager.searchByMask(path, mask);
		break;

	default:
		std::cout << "����� �� ���������:\n";
		break;
	}

	/*std::string path = "C:\\Users\\tanya\\OneDrive\\������� ����\\text.txt";
	FileManager fileManager;
	fileManager.showContentsOfTheDisc("C:");
	fileManager.createFolder(path);
	fileManager.createFile("C:\\Users\\tanya\\OneDrive\\������� ����\\FILE.txt");
	fileManager.deleteFolder("C:\\Users\\tanya\\OneDrive\\������� ����\\TEST");
	fileManager.deleteFile("C:\\Users\\tanya\\OneDrive\\������� ����\\FILE.txt");
	size_t size = fileManager.getFileSize(path);
	std::cout << "SIZE_FILE: " << size << '\n';
	size_t sizeFolder = fileManager.getFolderSize("C:\\Users\\tanya\\OneDrive\\������� ����\\Examination");
	std::cout << "SIZE_FOLDER: " << sizeFolder << std::endl;
	fileManager.searchByMask("C:\\Users\\tanya\\OneDrive\\������� ����", ".*\\.txt");*/

}

