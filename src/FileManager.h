#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;

class FileManager
{
public:
	void showContentsOfTheDisc(std::string path);
	void createFolder(const std::string& nameFolder);
	void createFile(const std::string& fileName);
	void deleteFolder(const std::string& nameFolder);
	void deleteFile(const std::string& fileName);
	void renameFolder(const std::string& nameFolder,
		const std::string& newNameFolder);
	void renameFile(const std::string& fileName,
		const std::string& newFileName);
	void copyFolder(const std::string sourceFolder, const std::string destination);
	void copyFile(const std::string sourceFile, const std::string destination);
	size_t getFileSize(const std::string& fileName);
	size_t getFolderSize(const std::string& nameFolder);
	void searchByMask(const std::string& nameFolder, const std::string& mask);
private:
	size_t* getIntermediateFolderSize(const std::string& nameFolder, size_t* resultSize);
};

