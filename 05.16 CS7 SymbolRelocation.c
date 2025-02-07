for each section s {
	 for each relocation entry r {
	 	
	 	refptr = s + r.offset;
	 	
	 	if(r.type == R_X_86_64_PC32) {
	 		refaddr = ADDR(s) + r.offset;
	 		//32��Ʈ pc-relative �ּҹ�� 
	 		*refptr = (unsigned) (ADDR(r.symbol) + r.addend - refaddr);
		}
		
		//32��Ʈ ���� �ּ� ��� 
		if(r.type == R_X86_64_32)
			*refptr = (unsigned) (ADDR(r.symbol) + r.addend);
	}
}
