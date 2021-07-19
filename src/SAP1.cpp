#include <iostream>
#include <vector>
#include "cpu.h"

using namespace std;


int main()
{
    CPU* cpu = new CPU();

    // Load RAM here 

    vector<byte> inst;
    inst.push_back(0x09);
    inst.push_back(0x1A);
    inst.push_back(0xEF);
    inst.push_back(0XFF);
    inst.push_back(0xFF);
    inst.push_back(0XFF);
    inst.push_back(0xFF);
    inst.push_back(0XFF);
    inst.push_back(0xFF);
    // 9 and A
    inst.push_back(0X04);
    inst.push_back(0x05);

    inst.push_back(0XFF);
    inst.push_back(0xFF);
    inst.push_back(0XFF);
    inst.push_back(0XFF);
    inst.push_back(0xFF);


    cout << "CPU & Instructions Ready" << endl;
    cpu->Execute(inst);

    cout << "Execution Completed" << endl;
    delete cpu;

    CPU* cpu1 = new CPU();
    vector<byte> inst1;
    inst1.push_back(0x09);
    inst1.push_back(0x1A);
    inst1.push_back(0x1C);
    inst1.push_back(0X2B);
    inst1.push_back(0xEF);
    inst1.push_back(0XFF);

    inst1.push_back(0xFF);
    inst1.push_back(0XFF);
    inst1.push_back(0xFF);
    // 9, A, B, C
    inst1.push_back(0X10);
    inst1.push_back(0x18);
    inst1.push_back(0X14);
    inst1.push_back(0x20);

    inst1.push_back(0XFF);
    inst1.push_back(0XFF);
    inst1.push_back(0xFF);

    cout << "CPU & Instructions Ready" << endl;

    cpu1->Execute(inst1);
    cout << "Execution Completed" << endl;

    delete cpu1;
    cin.get();
    return 0;
}
