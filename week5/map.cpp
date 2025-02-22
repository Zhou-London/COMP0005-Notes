#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){

    //declaration
    unordered_map<string, string> m;

    //put data
    m.insert(make_pair("Apple", "I love Apple."));
    m.emplace("Banana", "I hate Banana.");

    //get data
    try{
        cout << m.at("Apple") << endl;
    }catch( const out_of_range& e){
        cout << "Map access error: " << e.what() << endl;
    }
    cout << m["Banana"] << endl;

    //Searching data
    auto it = m.find("Apple");
    if(it != m.end()){ cout << it->second << endl; }

    if(m.count("Apple") > 0) { cout<<"Apple Exists"<<endl; }
    if(m.contains("Apple")) { cout<<"Apple Exists"<<endl; }

    //Erasing data
    m.erase("Banana");
    auto it_ = m.find("Banana");
    if(it_ != m.end()){ m.erase(it_); }

    //Iteration
    for(const auto &pair: m) cout << pair.first << ": " << pair.second << endl;

}
