int icode = [
    imen_eroor : INOP;
    1 : imem_icode;
];

int ifun = [
    imem_error : FNONE;
    1 : imem_ifun;
];

bool need_valc = icode in { 
    IIRMOVQ, IRMMOVQ, IMRMOVQ, IJXX, ICALL
};

bool need_regids = icode in {
    IRRMOVQ, IOPQ, IPUSHQ, IPOPQ, IIRMOVQ, IRMMOVQ, IMRMOVQ
};

bool instr_valid = icode in {
    INOP, IHALT, IRRMOVQ, IIRMOVQ, IRMMOVQ, IMRMOVQ,
    IOPQ, IJXX, ICALL, IRET, IPUSHQ, IPOPQ
};

