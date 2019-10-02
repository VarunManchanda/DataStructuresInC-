#include<iostream>
#include<vector>
using namespace std;


class Heap{
    private:
    vector<int> heap;
    int currentPos = -1;
    public:
    void insert(int data){
        heap.push_back(data);
        currentPos+=1;
        heapifyUp(currentPos);
    }
    void heapifyUp(int index){
        int parent = (index-1)/2;
        while(parent >=0 && (heap[parent] > heap[index])){
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            index = parent;
            parent = (index-1)/2;
        }
    }
    void poll(){
        heap[0] = heap.back();
        heap.pop_back();
        currentPos -= 1;
        heapifyDown(0);
    }
    void remove(int data){
    	int index = findIndex(data);
    	if(index==-1){
    		cout<<"Element not present"<<endl;
    		return;
    	}
        heap[index] = heap.back();
        heap.pop_back();
        currentPos -= 1;
        heapifyDown(index);
        heapifyUp(index);
    }
    
    int findIndex(int key){
    	for(int i=0; i<heap.size(); i++){
    		if(heap[i]==key){
    			return i;
    		}
    	}
    	return -1;
    }
    
   void heapifyDown(int start){
       int left = 2*start + 1;
       int right = 2*start + 2;
       int smallest = start;
       if(left < heap.size() && heap[left] < heap[smallest]){
           smallest = left;
       }
       if(right < heap.size() && heap[right] < heap[smallest]){
           smallest = right;
       }
       if(smallest!=start){
           int temp = heap[smallest];
           heap[smallest] = heap[start];
           heap[start] = temp;
           heapifyDown(smallest);
       }
   }

    
    void traverse(){
        int i = 0;
        for(i=0; i<heap.size(); i++){
            cout<<heap[i]<<" ";
        }
    }
    int peek(){
        if(currentPos==-1){
            return -1;
        }
        return heap[0];
    }


    int size(){
        return heap.size();
    }
};

int main(){
    //btw you can use priority_queue<int, vector<int>, greater<int>> heap;
    //.top(), .pop(), push(), .size()
    Heap *h = new Heap();
    h->insert(1);
    h->insert(3);
    h->insert(2);
    h->insert(5);
    h->insert(6);
    h->insert(4);
    h->insert(7);
    h->poll();
    h->traverse();

    return 0;
}
