# BOJ 12891 DNA 비밀번호 S2

## 문제

책에선 S5로 나와있는데 어느새 S2로 승급했는지 난이도가 다르다.

임의의 DNA 문자열을 만들고 그것의 부분문자열을 비밀번호로 쓴다고 한다.

부분문자열의 길이가 입력으로 주어진다.

부분문자열에서 A C G T 가 각각 몇번씩 출현해야 하는 조건이 주어진다.

## 유형 파악

크기가 입력으로 주어지는 슬라이딩 윈도우다. A C G T의 카운트를 저장해야 한다.

## 시간복잡도

문자열의 길이가 1백만이다. 제곱을 허용하지 않는다

## 풀이

```cpp
bool check(){
    for(int i=0;i<4;i++){
        if(counts[i] < cond[i]){
            return false;
        }
    }
    return true;
}
```

check 함수를 이상하게 생각했다. 카운터 배열을 만들어 놓고 왜 배열에서 카운트를 직접 세려고 했는지...

# 슬라이딩 윈도우 기법

정확히 현재 시점만 판단하는게 좋다. 굳이 범위 생각하지 말고 (틀리니까) 그냥 처음부터 끝까지 탐색해서 한 점만 유지시키는 것이 좋다.
