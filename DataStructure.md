# C++ 자료 구조 정리

## 목차
1. [vector](#Vector)
2. [stack](#Stack)

## Vector
배열과 구현이 거의 비슷. capa doubling 전략
```cpp
vector<int> v;
vector<int> v(size);
vector<int> v(size, init);
v.push_back(elem); // v.push_back(customclass(3));
v.emplace_back(init); // v.emplace_back(3); (if vector<customclass>)
v.pop_back();
v.resize(n);
v.clear(); // all clear
v.begin();
v.end(); // iterators.
v.erase(iter1,iter2) // iter1부터 iter2-1까지 전부삭제
v.erase(iter) // iter 원소 삭제
v.size()
v.empty()
```


## Stack
위로 넣고 위로 뺀다. FIFO
```cpp
stack<int> st;
st.push(elem); // emplace(init)
st.pop();
st.top();
st.size();
st.empty();
```

## Queue
뒤로 넣고 앞으로 뺀다. in:back, out:front
```cpp
queue<int> q;
q.push(elem); // emplace(init)
q.pop();
q.front();
q.back();
q.size();
q.empty();
```

## Deque
앞뒤로 넣고 뺀다.
```cpp
deque<int> q;
q.push_back(elem); // emplace(init)
q.push_front(elem);
q.pop_back();
q.pop_front();
q.front();
q.back();
q.size();
q.empty();

q.begin();
q.end();
q.erase(iter);
q.insert(idx, elem);
```

## Set
Balanced BST : 연산 n개 데이터 연산 시 O(n log n)
```cpp
set<int> s;
s.insert(elem);
s.find(elem); // 못 찾으면 s.end() O(log n)
s.count(elem); // 0이면 없는거. 개수 센다 (O(log n))
s.clear()
s.size();
s.begin();
s.end();
iter = s.lower_bound(elem); // elem보다 작지 않은 첫번째 원소 iterator
iter = s.upper_bound(elem); // elem보다 큰 원소 iterator
```

## Pair
```cpp
pair<int,int> p;
p.first;
p.second;

v.push_back({3,5});
```

## Map
RB Tree
```cpp
map<int, int> mp;
mp[4]=5; // data planted
if(mp[3]) // this doesn't plant data in map.
mp.clear(); 
m.erase(x or iter);
```

## Unordered Map
defined in `unordered_map`

THIS IS HASHED MAP.

## Priority Queue
Implemented with Heap structure. defined in `queue`

`i1 > i2` = 오름차순

```cpp
priority_queue<int> pq; // max pq
priority_queue<int,vector<int>,greater<int>> pq; // min pq
pq.push(elem);
pq.pop();
pq.top();
pq.empty();
pq.size();
while(!pq.empty()){
    // some logic
    pq.pop();
}


--- custom comparator (min PQ)
class Comparator{
    public:
    bool operator()(int i1, int i2){
        return i1>i2;
    }
};
```

## Union-Find
원소 key값이 겹치지 않는다고 가정
```cpp
// key range: 0~MAX_SIZE-1

//initialization
int root[MAX_SIZE];
int rank[MAX_SIZE];
for(int i=0;i<MAX_SIZE;i++){
    root[i]=i;
    rank[i]=0;
}

int find(int x){
    if(root[x]==x){
        return x;
    }else{
        return root[x]=find(root[x]); // path compression.
    }
}

void union(int x, int y){
    x=find(x);
    y=find(y);

    if(x==y){
        return; // union 필요 없음
    }

    if(rank[x] < rank[y]){ // 작은 놈이 큰 놈에 붙는다.
        root[x]=y;
    }else{
        root[y]=x;
    }

    if(rank[x]==rank[y]){
        rank[x]++; // y를 x에 붙였다 이말입니다.
    }
}
```



## 공통

```cpp
sort(iter1, iter2); // O(n log n) QUICKSORT.
iter = find(begin,end,val); // O(n)
reverse(begin,end); // 실제 데이터가 뒤집힌다. O(n) (exactly n/2)
lower_bound(begin,end,val) // 정렬 필요. val보다 작지 않은 첫번째 원소 iter, 즉 val 자기 자신도 포함될 수 있다.
upper_bound(begin,end,val) // val보다 큰 첫번째 원소 iter

do{
    // something with 조합
}while(next_permutation(begin,end));
```