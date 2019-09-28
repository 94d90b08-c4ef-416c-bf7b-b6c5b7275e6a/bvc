#include <iostream>
#include <filesystem>

int main()
{
    std::filesystem::path path{ "TestingFolder" }; //creates TestingFolder object on C:
    std::cout << path << "\n";
    path /= "my new file.txt"; //put something into there
    std::cout << path << "\n";
    std::filesystem::create_directories(path.parent_path()); //add directories based on the object path (without this line it will not work)

    std::ofstream ofs(path);
    ofs << "this is some text in the new file\n"; 
    ofs.close();
    std::filesystem::resize_file(path, 10244);

    return 0;
}