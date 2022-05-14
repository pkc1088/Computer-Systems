/*
write-through 
즉시 w의 캐시 블록 전체를 다음 하위 레벨로 써주는것
매 쓰기 작업마다 버스 트랙픽을 발생시킴

write-back
가능한 한 갱신을 지연시켜 이 블록이 블록 교체 알고리즘에 의해 
캐시에서 축출될 때에만 갱신된 블록을 하위 레벨에 써줌
버스 트래픽을 줄일 수 있지만 복잡함
캐시는 캐시 블록이 수정되었느지 여부를 나타내는 dirty bit 를 각 라인마다
추가로 유지해야함

write-allocate
해당 블록을 다음 하위레벨에서 가져온 뒤 캐시 블록을 갱신함

write back은 write allocate방식이고 write through는 no wirte allocate 방식

요즘은 write back을 주로 사용함. 지역성을 활용할 수 있기때문 
*/
