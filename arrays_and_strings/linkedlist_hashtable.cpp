#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class HashTable {
    private:
        vector< forward_list<int> > table;
        int size;
        int get_hash(int item) {
            return item%size;
        }
    public:
        HashTable(int s) {
            size = s;
            table.resize(size);
        }
        void put(int item) {
            int hash = get_hash(item);
            table.at(hash).push_front(item);
        }
        void pop(int item) {
            int hash = get_hash(item);
            auto list = table.at(hash);
            list.remove(item);
        }
        int get(int hash) {
            return *table.at(hash).begin();
        }
        int exists(int item) {
            int hash = get_hash(item);
            auto list = table.at(hash);
            for(auto it=list.begin();it!=list.end();it++) {
                if(*it==item){
                    return 1;
                }
            }
            return 0;
        }

        void print_hash(int hash) {
            auto list = table.at(hash);
            for(auto it=list.begin();it!=list.end();it++) {
                cout<<*it<<" ";
            }
            cout<<"\n";
        }

        void print_table() {
            int i=0;
            for(auto hash=table.begin();hash!=table.end();hash++) {
                cout<<i<<": ";
                print_hash(i);
                i++;
            }
        }
};

int main() {
    HashTable t1(10);
    t1.put(18);
    t1.put(34);
    t1.put(55);
    t1.put(28);
    t1.put(58);
    t1.print_table();
    cout<<t1.exists(28)<<"\n";
    return 0;
}
