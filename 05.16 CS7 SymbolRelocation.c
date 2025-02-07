for each section s {
	 for each relocation entry r {
	 	
	 	refptr = s + r.offset;
	 	
	 	if(r.type == R_X_86_64_PC32) {
	 		refaddr = ADDR(s) + r.offset;
	 		//32비트 pc-relative 주소방식 
	 		*refptr = (unsigned) (ADDR(r.symbol) + r.addend - refaddr);
		}
		
		//32비트 절대 주소 방식 
		if(r.type == R_X86_64_32)
			*refptr = (unsigned) (ADDR(r.symbol) + r.addend);
	}
}
