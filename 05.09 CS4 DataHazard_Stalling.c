/*
파이프라인 방식에서는 앞선 명령어의 실행이 완전히 끝나기도 전에 
다음 명령어의 실행이 시작된다. 따라서 Decode 단계에서 읽어 들이는 
레지스터의 값이 정확하다고 보장할 수 없다. 
이를 해결하는 가장 기본적인 방법은 직전 명령어가 레지스터에 값을 
제대로 저장할 때까지 버블을 삽입하면서 현재 단계에서 기다리는 것이다.

자신보다 앞선 3개의 명령어에 대해서, 목적지 레지스터 번호가 자신의 
소스 레지스터 번호와 매칭 된다면 Fetch와 Decode 단계의 명령어는 그 
자리에서 한 사이클 동안 가만히 기다려야 하고(Stall) Execute 단계에는 
버블을 삽입해줘야 한다. 3개의 명령어만 검사하는 이유는 앞선 명령어 
중에 Write Back 단계를 아직 끝내지 못한 명령어가 3개 존재하기 때문이다. 
따라서 버블은 최대 3개까지 연속으로 삽입할 수 있다. 
*/

//https://it-eldorado.tistory.com/45?category=761782
