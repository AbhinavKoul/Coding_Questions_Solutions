#include<iostream>
#include<vector>
using namespace std;
#define v vector
/*
    Not exacrt corrrect as still need to handle edge cases such as element no tin arr and all, bubt just a geenral idea
*/
class maxHeap
{
    //to store heap elements in their order
    v<int> arr;
    int capacity;
    int currentHeapSize;
    //constructor to initialize
    int parent(int idx)
    {
        return idx/2;
    } 
    //given 2 indices, swap the values
    void swap(int i,int j)
    {
        int temp = arr[j];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    maxHeap(int n)
    {
        capacity = n;
        arr.clear();
        arr.resize(capacity + 1);   //cause 0th index we dont store anything
        currentHeapSize = 0;
    }

    void insert(int val)
    {
        if(currentHeapSize == capacity) //if vector is completely full, need to extend it
        {
            capacity++;
            arr.push_back(-1);  //insert dummy for now
        }

        //now inserting element at the end of vector 1st
        currentHeapSize++;
        arr[currentHeapSize] = val;

        //heapify now
        int i = currentHeapSize;
        while(i > 0)
        {
            int parent = i/2;
            //bubbling max element to the top
            if(arr[parent] < arr[i])
            {
                swap(parent,i);
                i = parent;
            }
            else
                break;    
        }
    }

    void delElement()
    {
        //swap the root to the last node
        swap(1,currentHeapSize);
        arr[currentHeapSize] = -1;  //delete
        currentHeapSize--;
        
        //heapify
        int i = 1;

        while(i<=currentHeapSize)
        {
            int left = arr[2*i];
            int right = arr[2*i + 1];

            int largerIdx = left > right?(2*i):(2*i + 1);
        
            //bubbling min element to the bottom
            if(arr[i] < arr[largerIdx])
            {
                swap(i,largerIdx);
                i = largerIdx;
            }
            else
                break;
        }

    }
};