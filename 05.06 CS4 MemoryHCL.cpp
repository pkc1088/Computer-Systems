bool mem_read = icode in {IMRMOVQ, IPOPQ, IRET};
bool mem_write = icode in {IRMMOVQ, IPUSHQ, ICALL};

int mem_addr = [
    icode in {IRMMOVQ, IPUSHQ, ICALL, IMRMOVQ} : valE;
    icode in {IPOPQ, IRET} : valA;
];

int mem_data = [
    icode in {IRMMOVQ, IPUSHQ} : valA;
    icode == ICALL : valP;
];

int Stat = [
    imem_error || dmem_error : SADR;
    !instr_valid : SINS;
    iocde == IHALT : SHLT;
    1 : SAOK;
];  
