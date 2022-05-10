bool F_stall =
	// condition for a load/use hazard
	E_icode in {IMRMOVQ, IPOPQ} &&
	E_dstM in {d_srcA, d_srcB} ||
	// stalling at fetch while ret passes thru pipeline
	IRET in {D_icode, E_icode, M_icode};
