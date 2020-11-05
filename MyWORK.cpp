#include <iostream>
#include <unistd.h>

using namespace std;

class Resources
{
public:
    ~Resources() { cout << "destroy object's\n"; }
};

Resources& getRes()
{
    static Resources r1;
    return r1;
}

void makeChild(const string& command)
{
    int pid = fork();
    switch (pid)
    {
    case -1:
        cout << "error!\n";
        return;
    case 0:
        cout << "\n";
        return;
    }
    cout << "Теперь мы Ребенок\n";
    throw command;
}

int main(int argc, char* argv[])
{
    try
    {
        Resources& ref = getRes();
        makeChild("ребенок");
    }
    catch (const string& command)
    {
        execl(command.c_str(), "");
    }
    return 0;
}


