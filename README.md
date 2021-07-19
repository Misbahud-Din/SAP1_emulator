# SAP 1 Emulator
##### _From Digital Computer Electonics By Albert Malvino_
---

### Description

SAP 1 (Simple As Possible)  is a very basic model of microprocessor. It has only 5 basic instructions. 
- 3 with 1 operand
- 2 with implicit operands

### Instruction Set
|Mnemonics|Operation|Op Code|Description|
|:---:|:---:|:---:|:---:|
|LDA|ACC 🠔 RAM[MAR]|0b0000|Load RAM data into accumulator|
|ADD|ACC 🠔 ACC + B|0b0001|Add RAM data to accumulator|
|SUB|ACC 🠔 ACC – B|0b0010|Subtract RAM data from accumulator|
|OUT|OUT 🠔 ACC|0b1100|Load accumulator data into output register|
|HLT|CLK 🠔 0|0b1111|Stop processing|

## Features

- Simple As Possible
- 16 Bytes Read Only Memory
- 8 Bit Bus
- 
##### Register
1. Accumulator
2. B Register
3. Out Register
4. Instruction Register (IR)
5. Memory Address Register (MAR)


## Architecture
![SAP Block Diagram]("https://i.imgur.com/4YeklTN.png")


## Usage
For now the RAM is hardcoded in SAP1.cpp in form of vectors. Those instructions can be changed and then compiled to get desired ouput. 

```cpp
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
    inst.push_back(0X04);
    inst.push_back(0x05);
    inst.push_back(0XFF);
    inst.push_back(0xFF);
    inst.push_back(0XFF);
    inst.push_back(0XFF);
    inst.push_back(0xFF);
```

#### To Do
- Adding More Comments ¯\\_( ͡° ͜ʖ ͡°)_/¯
- Loading RAM from external file in Inetl hex format.
- Add T- states
