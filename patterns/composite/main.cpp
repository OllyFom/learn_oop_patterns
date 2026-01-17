#include "classes.hpp"

int main() {
    std::vector<std::unique_ptr<IFileSysObject>> consist = {new File("file1"), new File("file2")};
    Directory dir("dir1", consist);
    dir.size();
}