#include <iostream>
#include <string>
#include <vector>
#include "function.h"

using namespace std;

Node::Node(std::string id, u32 time)
{
    this->id = id;
    this->time = time;
}

u32 Node::get_time()
{
    return time;
}

void Node::set_time(u32 time)
{
    this->time = time;
}

std::string Node::get_id()
{
    return id;
}


// Operator Overloading
bool operator== (Node& node1, Node& node2)
{
    return node1.get_time() == node2.get_time();
}

bool operator== (Node& node1, u32 time)
{
    return node1.get_time() == time;
}

bool operator!= (Node& node1, Node& node2)
{
    return node1.get_time() != node2.get_time();
}

bool operator!= (Node& node1, u32 time)
{
    return node1.get_time() != time;
}

bool operator< (Node& node1, Node& node2)
{
    if(node1.get_time() == node2.get_time())
    {
        return node1.get_id() < node2.get_id();
    }
    return node1.get_time() < node2.get_time();
}

bool operator< (Node& node1, u32 time)
{
    return node1.get_time() < time;
}

bool operator> (Node& node1, Node& node2)
{
    if(node1.get_time() == node2.get_time())
    {
        return node1.get_id() > node2.get_id();
    }
    return node1.get_time() > node2.get_time();
}

bool operator> (Node& node1, u32 time)
{
    return node1.get_time() > time;
}

bool operator<= (Node& node1, Node& node2)
{
    return node1.get_time() <= node2.get_time();
}

bool operator<= (Node& node1, u32 time)
{
    return node1.get_time() <= time;
}

bool operator>= (Node& node1, Node& node2)
{
    return node1.get_time() >= node2.get_time();
}

bool operator>= (Node& node1, u32 time)
{
    return node1.get_time() >= time;
}

void operator+= (Node& node1,u32 time)
{
    node1.set_time(node1.get_time() + time);
}

ostream& operator<<(ostream& os, Node& n)
{
    os << n.id << " AT " << n.time;
    return os;
}

template <class T>
unsigned int BinaryHeap<T>::parent_idx(unsigned int idx)
{
    //the index of parent
    if(idx%2==0 && idx>0)
    {
        return (idx-2)/2;
    }
    return (idx-1)/2;
}

template <class T>
unsigned int BinaryHeap<T>::left_idx(unsigned int idx)
{
    //the index of left child
    return 2*idx+1;
}

template <class T>
unsigned int BinaryHeap<T>::right_idx(unsigned int idx)
{
    //the index of right child
    return 2*idx+2;
}

template <class T>
void BinaryHeap<T>::heapify_up(int idx)
{
    while(idx)
    {
        if( heap[idx] > heap[parent_idx(idx)] )
        {
            break;
        }
        if( heap[idx] < heap[parent_idx(idx)] )
        {
            T temp1=heap[idx];
            heap[idx]=heap[parent_idx(idx)];
            heap[parent_idx(idx)]=temp1;
            idx=parent_idx(idx);
        }
    }
}

template <class T>
void BinaryHeap<T>::heapify_down(int idx)
{
    //if do not have a left child
    if(left_idx(idx) >= heap.size())
    {
        //cout << 1 << endl;
        return;
    }
    //if only have a left child and the left child is smaller than itself
    if(left_idx(idx) < heap.size() && right_idx(idx) >= heap.size() && heap[idx] > heap[left_idx(idx)])
    {
        //cout << 2 << endl;
        T temp2 = heap[idx];
        heap[idx] = heap[left_idx(idx)];
        heap[left_idx(idx)] = temp2;
        return;
    }
    //if only have a left child and the left child is bigger than itself
    if(left_idx(idx) < heap.size() && right_idx(idx) >= heap.size() && heap[idx] < heap[left_idx(idx)])
    {
        //cout << 3 << endl;
        return;
    }
    //if have both left and right children
    if(right_idx(idx) < heap.size())
    {
        //if itself is smaller than both its left child and right child
        if(heap[idx] < heap[left_idx(idx)] && heap[idx] < heap[right_idx(idx)])
        {
            //cout << 4 << endl;
            return;
        }
        //if(heap[idx] > heap[left_idx(idx)] || heap[idx] > heap[right_idx(idx)])
        else
        {
            //cout << 2 << endl;
            if(heap[left_idx(idx)] < heap[right_idx(idx)])
            {
                //cout << 5 << endl;
                T temp3 = heap[idx];
                heap[idx] = heap[left_idx(idx)];
                heap[left_idx(idx)] = temp3;
                //cout << heap[0];
                heapify_down(left_idx(idx));
                return;
            }
            if(heap[right_idx(idx)] < heap[left_idx(idx)])
            {
                T temp4 = heap[idx];
                heap[idx] = heap[right_idx(idx)];
                heap[right_idx(idx)] = temp4;
                heapify_down(right_idx(idx));
                return;
            }
        }
    }
}

template <class T>
u32 BinaryHeap<T>::size()
{
    //the size of the vector
    return (u32)heap.size();
}

template <class T>
void BinaryHeap<T>::insert(T element)
{
    if(heap.size()>0) //if the vector is not empty
    {
        heap.push_back(element);//insert at the back of vector
        //cout << (u32)heap.size()-1;
        int index=(int)heap.size()-1;
        heapify_up(index);
        return;
        //cout << heap[0];
    }
    else if(heap.size()==0)//if the vector is empty
    {
        heap.push_back(element);//insert at the begin
        return;
        //cout << heap[0];
    }
    
    /*while (newelement != 1 && heap[newelement/2] > element)
    {
        heap[newelement] = heap[newelement/2];
        newelement = newelement/2;
    }
    heap[newelement] = element;*/
}

template <class T>
T BinaryHeap<T>::get_min()
{
    return heap[0];
}

template <class T>
void BinaryHeap<T>::del_min()
{
    /*heap[1].clear();
    heap[1]=heap[(int)heap.size()-1];
    heapify_down(1);*/
    swap(heap[0],heap.back());
    heap.pop_back();
    heapify_down(0);
}

template <class T>
Manager<T>::Manager()
{
    //taQue.heap[0]=NULL;
    this->endTime=0;
}

template <class T>
int Manager<T>::finish_in_time(u32 costTime,u32 deadLine)
{
    u32 MIN_time= taQue.heap[0].get_time();
    if(MIN_time + costTime >= deadLine)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}

template <class T>
void Manager<T>::cmd_set_endTime(u32 endTime)
{
    if(taQue.size()!=0)
    {
        for(int i=0;i<taQue.size();i++)
        {
            if(taQue.heap[i] > endTime)
            {
                cout << "SET_ENDTIME FAIL" << endl;
                //cout << endTime;
                return;
            }
        }
        this->endTime=endTime;
        cout << "SET_ENDTIME SUCCESS" << endl;
        //cout << endTime;
        return;
        //cout << endTime;
    }
    else
    {
        this->endTime=endTime;
        cout << "SET_ENDTIME SUCCESS" << endl;
        //cout << endTime;
        //cout << "SET_ENDTIME FAIL" << endl;
        return;
        //cout << endTime;
    }
}
vector<string> TASKNAME;
template <class T>
void Manager<T>::cmd_add_task(string taskName,u32 costTime)
{
    if(taQue.size()!=0)
    {
        if(endTime==0)
        {
            taQue.heap[0] += costTime;
            //cout << taQue.heap[0].get_time() << endl ;
            cout << "ADD_TASK" << " " << taskName << ": " << taQue.heap[0] << endl;
            taQue.heapify_down(0);
            //cout << taQue.heap[0];
            return;
        }
        else
        {
            if((taQue.heap[0].get_time()+costTime) > endTime)
            {
                cout << "ADD_TASK" << " " << taskName << ": FAIL" << endl;
                return;
            }
            else
            {
                taQue.heap[0] += costTime;
                cout << "ADD_TASK" << " " << taskName << ": " << taQue.heap[0] << endl;
                taQue.heapify_down(0);
                return;
            }
        }
    }
    else
    {
        cout << "ADD_TASK" << " " << taskName << ": FAIL" << endl;
        return;
    }
}
template <class T>
void Manager<T>::cmd_add_ta(std::string id, u32 begin)
{
    //T newTA = * new T(id,begin);
    //taQue.insert(newTA);
    if(endTime==0)
    {
        taQue.insert(T(id,begin));
        cout << "ADD_TA SUCCESS" << endl;
        return;
        //cout << taQue.heap[0] <<endl;
        //cout << taQue.heap[1] <<endl;
        //cout << taQue.heap[2] <<endl;
        
    }
    else
    {
        if(begin > endTime)
        {
            cout << "ADD_TA FAIL" << endl;
            return;
        }
        else
        {
            taQue.insert(T(id,begin));
            cout << "ADD_TA SUCCESS" << endl;
            return;
            //cout << taQue.heap[0];
            //cout << taQue.heap.size() << endl;
            //cout << taQue.heap[0].get_id() << endl;
            //cout << taQue.heap[0].get_time() << endl;
            //cout << taQue.heap[1].get_id() << endl;
        }
    }
}

template <class T>
void Manager<T>::cmd_check_schedule(u32 costTime,u32 deadLine)
{
    if(endTime==0)
    {
        if(taQue.size() == 0)
        {
            cout << "CHECK_SCHEDULE: NO TA WARNING!" << endl;
            return;
        }
        else
        {
            if(finish_in_time(costTime, deadLine)==0)
            {
                cout << "CHECK_SCHEDULE: OVERTIME WARNING!" << endl;
                return;
            }
            if (finish_in_time(costTime, deadLine)==1)
            {
                //taQue.heap[0] += costTime;
                //taQue.heapify_down(0);
                cout << "CHECK_SCHEDULE: CAN FINISH!" << endl;
                return;
            }
        }
    }
    else
    {
        if(taQue.size() == 0)
        {
            cout << "CHECK_SCHEDULE: NO TA WARNING!" << endl;
            return;
        }
        else
        {
            if( finish_in_time(costTime, deadLine)==0|| finish_in_time(costTime, endTime)==0)
            {
                cout << "CHECK_SCHEDULE: OVERTIME WARNING!" << endl;
                return;
            }
            if( finish_in_time(costTime, deadLine)==1 && finish_in_time(costTime, endTime)==1)
            {
                //taQue.heap[0] += costTime;
                //taQue.heapify_down(0);
                cout << "CHECK_SCHEDULE: CAN FINISH!" << endl;
                return;
            }
        }
    }
}

template <class T>
void Manager<T>::result()
{
    cout << "NUMBER_TA: " << taQue.size() << endl;
    if( taQue.size() !=0)
    {
       cout << "EARLIEST FINISH TA: " << taQue.heap[0] << endl;
        return;
    }
        //cout << endTime;
        //cout << "EARLIEST FINISH TA: " << taQue.heap[0] << endl;
}

template Manager<Node>::Manager();
template void Manager<Node>::cmd_set_endTime(u32 endTime);
template void Manager<Node>::cmd_check_schedule(u32 costTime,u32 deadLine);
template void Manager<Node>::cmd_add_task(string taskName,u32 costTime);
template void Manager<Node>::cmd_add_ta(std::string id, u32 begin);
template void Manager<Node>::result();
