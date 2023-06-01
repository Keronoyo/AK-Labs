#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

int main() {
    setlocale(0, "");
    // �������� ��������
    string inputs;
    fs::path filesPath;
    fs::path dest;
    do {
        cout << "Input your files' destination\nFormat: <<C:\\users\\you>>" << endl;
        cin >> inputs;
        filesPath = fs::path(inputs);
    } while (!fs::exists(filesPath) || !fs::is_directory(filesPath));

    cout << "\nWhich type of files do you wanna move?\nFormat: <<.png>>" << endl;
    string type;
    cin >> type;

    // ������� �������
    do {
        cout << "\nInput destination folder\nFormat: <<C:\\users\\you>>" << endl;
        cin >> inputs;
        dest = fs::path(inputs);
    } while (!fs::exists(filesPath) || !fs::is_directory(filesPath));

    int i{};
    // ������� ������
    for (const auto& entry : fs::directory_iterator(filesPath)) {
        fs::path filePath = entry.path();
        if (filePath.extension() == type) {

            //�������
            fs::path destinationPath = dest / filePath.filename();
            try {
                fs::copy_file(filePath, destinationPath, fs::copy_options::overwrite_existing);
                std::cout << "Succesfully copied " << filePath << std::endl;
                fs::remove(filePath);
            }
            catch (const std::exception& e) {
                std::cout << "Error copying " << filePath << ": " << e.what() << std::endl;
            }
            i++;
        }
    }
    if (i == 0) cout << "\nThere were no matching files!" << endl;
    return 0;
}