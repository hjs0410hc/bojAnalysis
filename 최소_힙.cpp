#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Heap{
    private:
    vector<int> v;
    int heap_size;
    int root_index;
    public:
    Heap(){
        v.push_back(-1);
        this->heap_size=0;
        this->root_index=1;
    }
    void swap(int idx1,int idx2){
        v[0] = v[idx1];
        v[idx1] = v[idx2];
        v[idx2] = v[0];
    }
    void upHeap(int idx){
        if(idx == root_index) return;
        else{
            int parent = idx/2;
            if(v[parent] > v[idx]){
                swap(parent,idx);
                upHeap(parent);
            }
        }
    }
    void downHeap(int idx){
        int left = idx*2;
        int right = idx*2+1;
        if(right <= heap_size){
            if(v[left] <= v[right]){ // right이 더 크면
                if(v[left]<v[idx]){ // left랑 한다
                    swap(left,idx);
                    downHeap(left);
                }else{
                    return;
                }
            }else{
                if(v[right]<v[idx]){
                    swap(right,idx);
                    downHeap(right);
                }else{
                    return;
                }
            }
        }else if(left <=heap_size){
            if(v[left] < v[idx]){
                swap(left,idx);
                downHeap(left);
            }else{
                return;
            }
        }else{
            return;
        }
    }
    void insert(int e){
        v.push_back(e);
        heap_size++;
        upHeap(heap_size);
    }
    int pop(){
        int top = v[root_index];
        v[root_index]=v[heap_size];
        heap_size--;
        v.pop_back();
        downHeap(root_index);
        return top;
    }
    int top(){
        return v[root_index];
    }
    int size(){
        return heap_size;
    }
    bool isEmpty(){
        return heap_size==0;
    }
    void print(){
        if(!isEmpty()){
            for(int i=root_index;i<heap_size;i++){
                cout << v[i] << " ";
            }
            cout << v[heap_size] << "\n";
        }else{
            cout << "-1" << "\n";
        }
    }
    int find(int x){
        if(!isEmpty()){
            return v.at(x);
        }else{
            return 0;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    Heap PQ;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x==0){
            if(PQ.isEmpty()){
                cout << 0 << "\n";
            }else{
                cout << PQ.top() << "\n";
                PQ.pop();
            }
        }else{
            PQ.insert(x);
        }
    }
}