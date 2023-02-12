//
// Created by lkapi on 12.02.2023.
//

#pragma once

#include <string>
#include <fstream>
#include <filesystem>
#include <minwindef.h>
#include <processenv.h>

#ifndef RAYGAME_SAVEMANAGER_H
#define RAYGAME_SAVEMANAGER_H

namespace Saves {

    class SaveManager {
    private:
        class SaveHelper {
        public:
            // Saves data to a file
            static void Save(const std::string& fileName, const void* data, int dataSize) {
                std::ofstream file(fileName, std::ios::binary);
                file.write((const char*)data, dataSize);
                file.close();
            }

            // Loads data from a file
            static void Load(const std::string& fileName, void* data, int dataSize) {
                std::ifstream file(fileName, std::ios::binary);
                file.read((char*)data, dataSize);
                file.close();
            }
        };

    private:
        std::string saveFolder;

    public:
        explicit SaveManager(const std::string& folderName) {
            // Get the AppData folder path
            char appDataPath[MAX_PATH];
            GetEnvironmentVariable("APPDATA", appDataPath, MAX_PATH);
            saveFolder = std::string(appDataPath) + "\\" + folderName + "\\saves\\";

            // Create the saves folder if it doesn't exist
            if (!std::filesystem::exists(saveFolder)) {
                std::filesystem::create_directory(saveFolder);
            }
        }

        // Saves data to the saves folder
        void Save(const std::string& fileName, const void* data, int dataSize) {
            Saves::SaveManager::SaveHelper::Save(saveFolder + fileName, data, dataSize);
        }

        // Loads data from the saves folder
        void Load(const std::string& fileName, void* data, int dataSize) {
            Saves::SaveManager::SaveHelper::Load(saveFolder + fileName, data, dataSize);
        }
    };

} // Saves

#endif //RAYGAME_SAVEMANAGER_H
