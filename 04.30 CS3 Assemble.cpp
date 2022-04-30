/*
어셈블리 코드(.s)는 어셈블러에 의해 
오브젝트 파일(.o)로 번역이 된다. 

(%rax) : %rax가 가리키는 메모리 주소에서 시작하는 연속적인 8개의 바이트

gcc -Og -S test.c
vi test.s 
하면 어셈블리어 코드 볼 수 있다. 

gcc -Og -o prog test.c
objdump -d prog
는 역어셈블이고 test.c 뒤에 test1.c이렇게 하면 합쳐서 보여줌 






*/
