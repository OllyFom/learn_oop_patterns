#include "classes.hpp"

int main() {
    Directory dir("dir1");
    File f1("file1"), f2("file2");
    dir.AddFile(std::move(f1));
    dir.AddFile(std::move(f2));
    dir.size();
}