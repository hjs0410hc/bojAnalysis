# 코딩테스트 용 알고리즘

## 목록

1. 구간 합
2. 투 포인터
3. 슬라이딩 윈도우
4. 스택, 큐
5. 정렬
6. DFS
7. BFS
8. 이진 탐색
9. 그리디
10. 정수론
11. 그래프
12. 유니온 파인드
13. 위상 정렬
14. 다익스트라
15. 벨만-포드
16. 플로이드-워셜
17. 최소 신장 트리(MST)
18. 트리
19. 트라이
20. 이진 트리
21. 세그먼트 트리
22. 최소 공통 조상
23. 조합
24. 동적 계획법 (DP)
25. 기하

## 구간 합
0~i까지의 구간 합 S[i]

구간 합 생성 : `S[i] = S[i-1]+A[i]`

구간 합 추출(i~j) : `S[j]-S[i-1]`

## 투 포인터
i, j = 0

전제 조건: 정렬됨.

조건보다 작다 => 오른쪽 벽을 늘린다 j++

조건보다 커졌다 => 왼쪽 벽을 늘린다 i++

## 슬라이딩 윈도우
범위를 유지한 채로 이동 -> 두 개의 포인터가 동시에 이동.

두 개의 포인터에서 동시에 상태 변화를 일으켜 이 때 정답인 지 확인해야 한다.

ex: 왼쪽 벽은 카운트 감소, 오른쪽 벽은 카운트 증가

## 

## DFS
```cpp
bool visited[MAX_SIZE];
vector<int> graph[MAX_SIZE];

void DFS(int x){
    visited[v]= true; // 이 line 의 위치 기억하시오.
    // do something
    for(auto v: graph[x]){
        if(!visited[v]){
            DFS(v);
        }
    }
}
```

## BFS
```cpp
queue<int> q; // stack overflow를 방지하기 위해 전역에 선언 (또는 힙 영역)
bool visited[MAX_SIZE];

void BFS(int x){
    q.push(x);
    visited[x]=true;

    while(!q.empty()){
        int f = q.front();
        for(auto v: graph[f]){
            if(!visited[v]){
                q.push(v);
                visited[v]=true;
            }
        }
    }
}
```
## 정수론

유클리드 호제법

`gcd(a,b) = gcd(b, r)`

여기서 `r = a % b`

---
에라스토테네스의 체

```cpp
bool notPrime[n+1];

notPrime[1]=true;
notPrime[2]=false;

for(int i=2;i<=sqrt(n);i++){ // sqrt in <cmath>
    if(!notPrime[i]){
        for(int j=i*2;j<=n;j+=i){
            notPrime[j]=true;
        }
    }
}

cout << (!notPrime[q] ? "소수" : "소수 아님") << "\n";

```




## Dijkstra
BFS+DP with PQ(dp값 가장 작은것 (다음으론 key))

DP=시작점 A에서 모든 vertex로 가는 최단 cost를 저장

DP식 : `dist[q] = min(dist[q], dist[p]+cost[p->q])`

PQ(minHeap)를 이용한 BFS인 게 중요

```cpp
while(!q.empty()){
    edge current = q.top();
    q.pop();
    int current_dst = current.second;
    if(visited[current_dst]){
        continue;
    }
    visited[current_dst]=true;

    for(edge e:mlist[current_dst]){
        int next = e.first;
        int value = e.second;


        // update distance (dp)
        if(mdistance[next] > mdistance[current_dst]+value){
            mdistance[next] = mdistance[current_dst]+value;
            q.push({mdistance[next],next});
        }
    }
}
```


## Backtracking
아래 예제는 m개를 뽑는 모든 조합을 나타내게 된다.
```cpp
void bt(int cur){
    if(v.size() == m){
        for(int i=0;i<m;i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(i!=cur && !visited[i]){
            v.push_back(i);
            visited[i]=true;
            bt(i);
            v.pop_back();
            visited[i]=false;
        }
    }
}
```
