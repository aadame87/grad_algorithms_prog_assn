//ALAN ADAME CSE202 8FEB17
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;
using std::cout;

struct Query {
    string type, name;
    //string name;
    int number;
};

struct Ph_Book {
  string name;
  int number;

};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    //string type;
    //long long phnum;
    //string name;
    //vector<Query> queries(9999999);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        //cin >> type;
        if (queries[i].type == "add")
        //if (type =="add")
            //cin >> phnum >> name;
            cin >> queries[i].number >> queries[i].name;
            //queries[phnum].number = phnum;
            //queries[phnum].name =name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    //vector<Query> contacts;
    int phnum;
    string name;
    //vector<Query> contacts(9999999);
    vector<Ph_Book> contacts(9999999);
    for (size_t i = 0; i < queries.size(); ++i) {
        phnum=queries[i].number;
        if (queries[i].type == "add") {
            bool was_founded = false;
            // if we already have contact with such number,
            // we should rewrite contact's name
            //for (size_t j = 0; j < contacts.size(); ++j)

                   name=queries[i].name;
                if (contacts[phnum].number == phnum) {
                    contacts[phnum].name = queries[i].name;
                    was_founded = true;
                    //break;
                }
            // otherwise, just add it
            if (!was_founded)
                //contacts.push_back(queries[i]);
                {contacts[phnum].number=phnum;
                contacts[phnum].name=name;}
                //cout << "added correctly";
        } else if (queries[i].type == "del") {
            //for (size_t j = 0; j < contacts.size(); ++j)
                //phnum=queries[i].number;
                if (contacts[phnum].number == phnum) {
                    //contacts.erase(contacts.begin() + phnum);
                    contacts[phnum].number=0;
                    contacts[phnum].name="";
                    //break;
                }
        } else {
            string response = "not found";
            //for (size_t j = 0; j < contacts.size(); ++j)
                //phnum=queries[i].number;
                if (contacts[phnum].name != "") {
                    response = contacts[phnum].name;
                    //break;
                }
            result.push_back(response);
        }
      }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
