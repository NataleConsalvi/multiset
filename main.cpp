#include <iostream>
#include <unordered_map>
#include "MultiSet.h"
#include "Matrix.h"

#include <stdexcept>
#include <string>
#include <sstream>
 
#include <tuple>
#include <vector>

using std::cout;
using std::endl;

void conversions_example(){
   cout << endl;
   cout << "---- Conversions" << endl;
   cout << "pair2str(12,345): " << pair2str({12,345}) << endl;
   cout << "str2pair(\"12,345\"): " << pair2str(str2pair("12,345")) << endl;
   cout << "triplets2str<int>({{1,3,2}, {6,3,5}, {9,2,5}, {1,5,3}})"
        << triplets2str<int>({{1,3,2}, {6,3,5}, {9,2,5}, {1,5,3}}) << endl;
}

void main_multiset(){
        cout << endl;
    cout << " ----- MULTISET" << endl;
    MultiSet<char> m = MultiSet<char>();
    m.add('a');
    m.add('a');
    m.add('b');   
    cout << "a: " << m.get('a') << endl;  // a: 2
    cout << "b: " << m.get('b') << endl;  // b: 1
    cout << "c: " << m.get('c') << endl;  // c: 0
    cout << m.size() << endl; // 3
    cout << m.as_string() << endl;    

    m.removen('a', 2);
    cout << m.as_string() << endl;         
    // b: 1     // note no a:0 should be present

    m.removen('a',0);
    cout << m.as_string() << endl;        
    // b: 1     
    m.removen('b', 1);
    cout << m.as_string() << endl;     // empty

    m.removen('c',0);  // no problem
    cout << m.as_string() << endl;     // empty

    m.add('c');
    m.add('c');
    m.add('c');
    cout << m.as_string() << endl;    
    // c: 3
    try {
        m.removen('c',5);  // too many
    } catch (std::out_of_range& ex) {
        cout << "something bad happened!" << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    };
    cout << m.as_string() << endl;   

    // c: 3   
}


int main(){
    
    //main_multiset();
    conversions_example();
    return 0;
}
