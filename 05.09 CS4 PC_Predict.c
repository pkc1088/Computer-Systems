
word f_pc = [
    M_icode == IJXX && !M_Cnd : M_valA;
    W_icode == IRET : W_valM;
    1 : F_predPC;
]

/*
<���÷���> 
�߸������� �бⰡ �޸� �ܰ迡 ���Խ� valp���� ����M�� ����
�ν�Ʈ������ ���� �ܰ����Խ� �����ּҴ� ����W�� ����
�ٸ� ��� ����F�� ����� PC�� �������� ���
*/

word f_predPC = [
	f_icode in {IJXX, ICALL} : f_valC;
	1 : f_valP;
]

/*
<��������>
���Ե� �ν�Ʈ������ call�̳� �����϶� valC �ٸ����  valP 
*/
