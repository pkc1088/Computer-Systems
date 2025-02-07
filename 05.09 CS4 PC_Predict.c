
word f_pc = [
    M_icode == IJXX && !M_Cnd : M_valA;
    W_icode == IRET : W_valM;
    1 : F_predPC;
]

/*
<선택로직> 
잘못예측한 분기가 메모리 단계에 진입시 valp값은 레지M에 읽힘
인스트럭션이 재기록 단계진입시 리턴주소는 레지W에 읽힘
다른 경우 레지F에 저장된 PC의 예측값을 사용
*/

word f_predPC = [
	f_icode in {IJXX, ICALL} : f_valC;
	1 : f_valP;
]

/*
<예측로직>
선입된 인스트럭션이 call이나 점프일때 valC 다른경우  valP 
*/
