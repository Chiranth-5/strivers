#include "Stl.h"
using namespace std;

void Stl::pairDatatype()
{
    //

    pair<int,int> p;
    p  = {1,2};

}

void Stl::displayVector( vector<int> v)
{
    cout << "Display Vector" << endl;
    for( int i=0; i<v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void Stl::displayMap( std::map<int,int> mp)
{
    // 1,3
    // 2,2

    // key value
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->second << " ";
    }
}

void Stl::vectorContainer()
{
    //single linkedlist

    //push_back(value)
    //insert(location, value)
    //pop_back()
    //size()
    //erase(location)
    //erase( start, end) = range , [start,end)
    //clear()
    //empty()

    //begin()
    //end()


    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    
    displayVector(v);


    cout << "iterator" <<endl;
    vector<int>::iterator it1 = v.begin();
    cout << *it1 << endl;
    it1++;
    cout << "it1++ " << *it1 << endl;

    displayVector(v);


    vector<int>::iterator it2 = v.end();
    it2--;
    cout << "Display v in desecnding order" << endl;
    for ( ; it2 != v.begin() ; it2--)
    {
        cout << *it2 << endl;
    }
    cout << *it2 << endl;

    // vector<int>::iterator it3 = v.rbegin();

    v.erase(v.begin());
    
    displayVector(v);

    //2 3 4
    v.erase( v.begin()+1, v.end()-1); // [start,end)

    displayVector(v);

    v.insert(v.begin(),300);
    displayVector(v);
    cout << v.size() << endl;
    v.pop_back();
    displayVector(v);

    cout << v.empty() << endl; // check empty




}

void Stl::listContainer( )
{
    // double linked list

    // similar to vector gives front operations as well.

    // push_front(value);

    // push_back(value);
    // insert(location, value);
    // pop_back()
    // size()
    // erase(location)
    // erase( start, end) = range , [start,end)

    // begin()
    // end()
    
    
    // insert to front is cheap .
    // because it uses double linkedlist.
    // vector uses single linked list .
    list<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    cout << "Display lsit" << endl;
    for( std::list<int>::iterator it  = list.begin(); it!=list.end() ; it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    list.push_front(10);
    // this is cheap

    cout << "Display lsit" << endl;
    for( std::list<int>::iterator it  = list.begin(); it!=list.end() ; it++)
    {
        cout << *it << " ";
    }
    cout << endl;

}

void Stl::deque()
{
    std::deque<int> deq;
    // similar to vector


}

void Stl::stack()
{

}

void Stl::Queuue()
{

}

void Stl::priorityQueue()
{
    //priority_queue<T, c, comp> pq;
    
    // T = Datatype of the priority Queue
    // c = underliny container ie vector.
    // comp = comparator function to define the pririty order.

    //By default it creates max heap using vector container

    priority_queue<int> pq; // max-heap ( int type and vecor container)

    priority_queue<int, vector<int>, greater<int> > pqmin;

    vector<int> vec  = {10,20,30,50,40};
    // Pass the iterators to initialize it as a max-heap priority queue
    // O(n)
    std::priority_queue<int> pqHeapify(vec.begin(), vec.end());

    // O(log(n))
    pq.push(10);
    pq.push(11);
    pq.push(8);

    // O(log(n));
    pq.pop();

    // O(1);
    pq.top();

    pq.size();

    // to traverse do it in reverse order.


    

}

void Stl::set()
{
    // key
    // its not key value pair. its just key
    // look up time is O(1);
}

void Stl::mutliSet()
{
    
}

void Stl::UnorderedSet()
{

}

void Stl::map()
{
    //how its implemented?
    //redblack tree.
    // ordered map
    


    //push_back(value)
    //insert(location, value)
    //pop_back()
    //size()
    //erase(location)
    //erase( start, end) = range , [start,end)
    //clear()
    //empty()

    //begin()
    //end()

    std::map<int,int> mpp;

    mpp.insert({2, 2});
    mpp[1] = 3;

    displayMap(mpp);
    cout << endl;

    std::map<int,int>::iterator it = mpp.find(2);
    cout << "Key value of find 2 :" << (*it).first << endl; // 2
    cout << "Value of the key of find 2 :" << it->second << endl; // 2

    auto it1 = mpp.lower_bound(2); // return lower bound to that element
    cout << " Lower bound to 2 :" << it1->second <<  endl;
    auto it2 = mpp.upper_bound(2); // returns iterator to upper bound to that element.if nothing then points to gost buffer that is 0 in this case.
    cout << " Upper bound to 2 :" << it2->second <<  endl;

    // erase
    // swap
    // empty
    // size 
    

}

void Stl::multiMap()
{

}

void Stl::unorderedMap()
{

}

void Stl::extra()
{

}

