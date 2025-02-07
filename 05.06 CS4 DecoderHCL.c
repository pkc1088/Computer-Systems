int srcA = [
    icode in {IIRMOVQ, IRMMOVQ, IOPQ, IPUSHQ} : rA;
    icode in {IOPQ, IRET} : RRSP;
    1 : RNONE;
];

int srcB = [
    icode in {IOPQ, IRMMOVQ, IMRMOVQ} : rB;
    icode in {IPUSHQ, IPOPQ, ICALL, IRET} : RRSP;
    1 : RNONE;
];

int need_regids = [
    iocde in {IRRMOVQ} && Cnd : rB;
    icode in {IIRMOVQ, IOPQ} : rB;
    icode in {IPUSHQ, IPOPQ, ICALL, IRET} : RRSP;
    1 : RNONE;
];
 
int dstM = [
    icode in {IMRMOVQ, IPOPQ} : rB;
    1 : RNONE;
];
  
