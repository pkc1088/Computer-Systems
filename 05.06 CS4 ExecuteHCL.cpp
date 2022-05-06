int aluA = [
    icode in {IRRMOVQ, IOPQ} : valA;
    icode in {IIRMOVQ, IRMMOVQ, IMRMOVQ} : valC;
    icode in {ICALL, IPUSHQ} : -8;
    icode in {IRET, IPOPQ} : 8;
];

int aluB = [
    icode in {IRMMOVQ, IMRMOVQ, IOPQ, ICALL, IPUSHQ, IRET, IPOPQ} : valB;
    icode in {IRRMOVQ, IIRMOVQ} : 0;
];

int alufun = [
    iocde == IOPQ : ifun;
    1 : ALUADD;
];
 
bool set_CC = icode in {IOPQ};
