#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
void* thread_routine(void *arg){
        int i = 1;
        
        printf("tid2 : %x\n", (unsigned int) pthread_self());

        while(i < 10000000) {
            printf("t2 : %d\n", i++);
        }
}
 
int main() {
        int i = 1;
        pthread_t t2, t3;
        pthread_create(&t2, NULL, thread_routine, NULL);
        
        printf("tid1 : %x\n", (unsigned int) pthread_self());
        sleep(2);
        pthread_detach(t2);
        while(i < 10) {
            printf("t1 : %d\n", i++);
        }
        i = 0;

}
/*
t2�� ����� thread_routine�Լ��� ���� sleep 2���� t2�� detach������ �߰��� detach�ع���
�̶� �� �����尡 ����Ǹ鼭 �ý��ۿ� ���� �ڵ����� ��ȯ�� �������� i�� 364279�϶� �뿡 �����
�� �� t1�� �˾Ƽ� ����� 
�� ���� �������� ���� ���¸� �� �����忡�� Ȯ���� �ʿ䰡 ���ų�
�߰����� �������� �������� �ý��ۿ��� �ڵ������� �ϱ⸦ ���� ���� 
�����带 detach�� ���ؼ� �и��Ѵ�.



*/    



