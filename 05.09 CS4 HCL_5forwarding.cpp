word d_valA = [
	D_icode in {ICALL, IJXX} : D_valP;
	d_srcA == e_dstE : e_valE;	//forward valE from execute
	d_srcA == M_dstM : m_valM;  //forward valM from memory
	d_srcA == M_dstE : M_valE;  //forward vlaE from memory
	d_srcA == W_dstM : W_valM;	//forward valM from write back
	d_srcA == W_dstE : W_valE;  //forward valE from write back
	1 : d_rvalA;	//use value read from register file
] 
