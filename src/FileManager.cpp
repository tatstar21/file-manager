
#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <system_error>
#include <regex>
#include "FileManager.h"

namespace fs = std::filesystem;

void FileManager::showContentsOfTheDisc(std::string path)
{
    std::error_code ec;

    for (const auto& entry : fs::directory_iterator(path, ec)) {
        std::cout << entry.path() << std::endl;

        if (ec) 
            std::cout << "Error in directory_iterator: " << ec.message();
    }
}

void FileManager::createFolder(const std::string& nameFolder)
{
    try
    {
        if (fs::create_directory(nameFolder))
            std::cout << "The folder " << nameFolder << " was successfully created!\n";
        else
            std::cout << "The folder " << nameFolder << " was not created!\n";
    }
    catch (std::filesystem::filesystem_error const& ex)
    {
        std::cout << ex.what();
    }
}

void FileManager::createFile(const std::string& fileName)
{
    std::ofstream file;

    try
    {
        file.open(fileName);
        std::cout << "The file " << fileName << " was successfully created!\n";
    }
    catch (const std::ios_base::failure& error)
    {
        std::cerr << "\033[31mError opened file" << fileName
            << "!!!\n\a" << error.what() << "\033[0m\n";
    }

    try
    {
        file.close();
    }
    catch (const std::ios_base::failure& error)
    {
        std::cerr << "\033[31mError cloused file" << fileName
            << "!!!\n\a" << error.what() << "\033[0m\n";
    }
}

void FileManager::deleteFolder(const std::string& nameFolder) 
{
    try
    {
        if (fs::remove_all(nameFolder))
            std::cout << "The folder " << nameFolder << " was successfully deleted!\n";
        else
            std::cout << "The folder " << nameFolder << " was not exist!\n";
    }
    catch (std::filesystem::filesystem_error const& ex)
    {
        std::cout << ex.what();
    }
}

void FileManager::deleteFile(const std::string& fileName)
{
    try
    {
        if (fs::remove(fileName))
            std::cout << "The file " << fileName << " was successfully deleted!\n";
        else
            std::cout << "The file " << fileName << " was not exist!\n";
    }
    catch (std::filesystem::filesystem_error const& ex)
    {
        std::cout << ex.what();
    }
}

void FileManager::renameFolder(const std::string& nameFolder,
    const std::string& newNameFolder)
{
    try
    {
        fs::rename(nameFolder, newNameFolder); 
    }
    catch (std::filesystem::filesystem_error const& ex)
    {
        std::cout << ex.what();
    }
}

void FileManager::renameFile(const std::string& fileName,
    const std::string& newFileName)
{
    try
    {
        fs::rename(fileName, newFileName);
    }
    catch (std::filesystem::filesystem_error const& ex)
    {
        std::cout << ex.what();
    }
}

void FileManager::copyFolder(const std::string sourceFolder, const std::string targetFolder)
{
    try
    {
        fs::copy(sourceFolder, targetFolder);
    }
    catch (std::filesystem::filesystem_error const& ex)
    {
        std::cout << ex.what();
    }
}

void FileManager::copyFile(const std::string sourceFile, const std::string targetFile)
{
    try
    {
        fs::copy(sourceFile, targetFile);
    }
    catch (std::filesystem::filesystem_error const& ex)
    {
        std::cout << ex.what();
    }
} 

size_t FileManager::getFileSize(const std::string& fileName)
{
    try
    {
        return fs::file_size(fileName);
    }
    catch (std::filesystem::filesystem_error const& ex)
    {
        std::cout << ex.what();
    }
}

size_t FileManager::getFolderSize(const std::string& nameFolder)
{
     size_t resultSize = 0;

    return *getIntermediateFolderSize(nameFolder, &resultSize);
}

size_t* FileManager::getIntermediateFolderSize(const std::string& nameFolder, size_t* resultSize)
{
    try
    {
        for (const auto& entry : fs::directory_iterator(nameFolder))
        {
            const fs::path newPath(entry.path());

            if (fs::is_directory(newPath)) {
                getIntermediateFolderSize(newPath.string(), resultSize);
            }
            if (fs::is_regular_file(newPath)) {
                *resultSize += fs::file_size(newPath);
            }
        }
        return resultSize;
    }
    catch (std::filesystem::filesystem_error const& ex)
    {
        std::cout << ex.what();
    }
}

void FileManager::searchByMask(const std::string& nameFolder, const std::string& mask)
{
    try
    {
        const std::regex maskFilter(mask);

        std::filesystem::directory_iterator endIterator;

        for (std::filesystem::directory_iterator ii(nameFolder); ii != endIterator; ++ii)
        {
            const fs::path newPath(ii->path());

            if (fs::is_directory(newPath)) {
                searchByMask(newPath.string(), mask);
            }
            if (std::filesystem::is_regular_file(ii->status())
                && std::regex_match(ii->path().filename().string(), maskFilter))
            {
                std::cout << ii->path().filename().string() << '\n';
            }
        }
    }
    catch (std::filesystem::filesystem_error const& ex)
    {
        std::cout << ex.what();
    }
   
}