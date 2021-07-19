#pragma once

#include <iostream>
#include <cstddef>
#include <bitset>
#include <vector>


using namespace std;

typedef unsigned char byte;


class CPU
{
private:
    byte a_reg; // Accumulator Register
    byte b_reg; // B register
    byte o_reg; // Output Register
    byte PC : 4; // Prgramme Counter
    byte ir;    // Instruction Register
    byte MAR; // Memory addr

    void ResetCPU()
    {
        a_reg = 0; // Accumulator Register
        b_reg = 0; // B register
        o_reg = 0; // Output Register
        ir = 0;    // Instruction Register
        PC = 0; // Prgramme Counter
        MAR = 0; // Memory addr
    }
    void doLDA(const vector<byte>& RAM)
    {
        MAR = RAM[PC] & 0x0F;
        a_reg = RAM[MAR];
        PC++;
    }
    void doADD(const vector<byte>& RAM)
    {
        MAR = RAM[PC] & 0x0F;

        b_reg = RAM[MAR];
        a_reg = b_reg + a_reg;
        PC++;
    }
    void doSUB(const vector<byte>& RAM)
    {
        MAR = RAM[PC] & 0x0F;

        b_reg = RAM[MAR];
        a_reg = a_reg - b_reg;
        PC++;
    }
    void doOUT()
    {
        o_reg = a_reg;
        cout << "The Output is 0b" << bitset<8>(o_reg) << '\t' << (int)o_reg << endl;
        PC++;
    }
    void doHLT()
    {
        cout << "Programme Halted" << endl;
        cout << "Exiting" << endl;


    }
public:
    CPU()
    {
        ResetCPU();
    }
    enum InstructionSet
    {
        LDA = 0b0000,    //Load Accumalator = 0000
        ADD = 0b0001,    // Add             = 0001
        SUB = 0b0010,    // Subtract        = 0010
        OUT = 0b1110,    // Print Output    = 1110
        HLT = 0b1111    // Halt            = 1111
    };
    void Execute(vector<byte>& RAM)
    {

        if (RAM.size() > 16)
        {
            cout << "Ram Size Greater than 16" << endl;
        }
        else
        {
            while (PC < RAM.size() && ir != HLT)
            {
                ir = (RAM[PC] & 0xF0) >> 4;
                switch (ir)
                {
                case LDA:
                    doLDA(RAM);
                    break;
                case ADD:
                    doADD(RAM);
                    break;
                case SUB:
                    doSUB(RAM);
                    break;
                case OUT:
                    doOUT();
                    break;
                case HLT:
                    doHLT();
                    break;
                default:
                    cout << "Invalid Instructions" << endl;
                    break;
                }
            }

        }
    }
};
