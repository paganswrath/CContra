#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem> 
#include <cstdlib> 

using namespace std;


bool IsFolderEmpty(const std::string& folderPath) {
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            return false;
        }
    }
    return true;
}

string ReadValue(string Data, int Start,
                 int End) { // Reads Value from (Start to End)
    string Out;
    for (int i = Start; i <= End; i++) {
        Out += Data[i];
    }
    return Out;
}

string SplitValue(string Data, int Place) {
    string Out;
    int PlaceCounter = 0;

    int Start = 0;
    int End = 0;

    if (Place == 0) {
        for (int i = 0; i <= Data.size(); i++) {
            if (Data[i] == ' ' || i == Data.size()) {
                End = i - 1;
                break;
            }
        }
    } else {
        Place = Place;
        PlaceCounter = 1;
        for (int i = 0; i <= Data.size(); i++) {
            if (PlaceCounter == Place) {
                Start = i + 1;
                for (int x = i + 1; x <= Data.size(); x++) {
                    if (Data[x] == ' ' || x == Data.size()) {
                        End = x - 1;
                        break;
                    }
                }
            }
            if (Data[i] == ' ') {
                PlaceCounter++;
            }
        }
    }

    Out = ReadValue(Data, Start, End);

    return Out;
}


int stringToInt(const string& str) {
    return atoi(str.c_str());
}

void extractBytes(const string& romFile, int start, int length, const string& outputFile) {
    ifstream romStream(romFile, ios::binary);
    ofstream outputStream(outputFile, ios::binary);
    romStream.seekg(start); // Move to the starting position
    char buffer[length];
    romStream.read(buffer, length); // Read 'length' bytes
    outputStream.write(buffer, length); // Write to output file
}


void DumpAssets() {
    string romFile = "baserom.nes";
    string assetsFile = "Runtime/AssetsList.txt";

    // Open the NES ROM file
    ifstream romStream(romFile);
    if (!romStream) {
        cout << "Failed to open " << romFile << ". This is needed to run the game." << endl;
        return; // Exit the function if the ROM file cannot be opened
    }

    // Open the assets list file
    ifstream assetsStream(assetsFile);
    if (!assetsStream) {
        cout << "Failed to open " << assetsFile << ". Please check the file path." << endl;
        return; // Exit the function if the assets list file cannot be opened
    }

    string line;
    while (getline(assetsStream, line)) {
        cout << "Processing line: " << line << endl; // Debug output

        string FilePath = SplitValue(line , 0);
        int start = stringToInt(SplitValue(line , 1));
        int length = stringToInt(SplitValue(line , 2));

        extractBytes(romFile, start, length, FilePath);
    }

    cout << "Asset dumping completed." << endl;
}