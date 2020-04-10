#include <iostream>
#include <fstream>
#include <dirent.h>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

void decode(char str[256]);
void findFile(const char *curDir, const char *firstFileName, const char *secondFileName);
bool mycmp(const char *firstString, const char *secondString);
char* getPath(const char *dir, const char *myFileName);

vector<char*> paths1;
vector<char*> paths2;

int main() {

    string startDir = "/Users/newboba/Desktop/";
    string firstFileName;
    string secondFileName;

//    cin >> startDir;
    cout << "input first file name" << endl;
    cin >> firstFileName;
    cout << "input second file name" << endl;
    cin >> secondFileName;

    findFile(startDir.c_str(), firstFileName.c_str(), secondFileName.c_str());

    if (paths1.empty()) {
        cout << "File is not find" << endl;
        return 0;
    } else {
        char *pathResultFile;
        if (paths2.empty()) {
            pathResultFile = getPath(startDir.c_str(), secondFileName.c_str());
        } else {
            cout << "WARNING!! The contents of the file will be overwritten." << endl;
            pathResultFile = paths2[0];
        }
        FILE *oFile = fopen(pathResultFile,"w");
        for (auto it : paths1) {
            ifstream iFile(it);
            while(iFile.eof() == false) {
                char tempString[256];
                int i = 0;
                for (; i < 256; ++i){
                    if (iFile.eof()) break;
                    tempString[i] = iFile.get();
                }
                decode(tempString);
//                decode(tempString);
                if (iFile.eof()) {
                    for (int j = 0; j < i - 1; ++j){
                        fputc(tempString[j], oFile);
                    }
                } else {
                    fputs(tempString, oFile);
                }
            }
            break;
        }
    }
    return 0;
}

void decode(char str[256]) {
    const char *codeWord = "Bobr";
    size_t len = strlen(codeWord);
    int j = 0;
    for (size_t i = 0;  i < 256; ++i) {
        str[i] = (char)((unsigned int)(str[i]) ^ (unsigned int)codeWord[j]);
        j++;
        if (j == len) j = 0;
    }
}

void findFile(const char *curDir, const char *firstFileName, const char *secondFileName) {
    cout << curDir << endl;
    DIR *dir = opendir(curDir);
    if(dir) {
        struct dirent *ent;
        while((ent = readdir(dir)) != nullptr) {
            if (mycmp(ent->d_name, firstFileName)) {
                char *path = getPath(curDir, firstFileName);
                paths1.push_back(path);
            } else if (mycmp(ent->d_name, secondFileName)) {
                char *path = getPath(curDir, secondFileName);
                paths2.push_back(path);
            } else if (ent->d_name[0] != '.') {
                char *newDir = getPath(getPath(curDir, ent->d_name), "/");
                findFile(newDir, firstFileName, secondFileName);
            }
        }
    }
    if (dir != nullptr)
        closedir(dir);
}

bool mycmp(const char *firstString, const char *secondString) {
    size_t len1 = strlen(firstString);
    size_t len2 = strlen(secondString);
    if (len1 != len2)
        return false;
    for (size_t i = 0; i < len1; ++i){
        if (firstString[i] != secondString[i])
            return false;
    }
    return true;
}

char* getPath(const char *dir, const char *myFileName) {
    size_t len1 = strlen(dir);
    size_t len2 = strlen(myFileName);
    char *path = (char*)malloc(len1 + len2 + 1);

    memcpy(path, dir, len1);
    memcpy(path + len1, myFileName, len2 + 1);

    return path;
}