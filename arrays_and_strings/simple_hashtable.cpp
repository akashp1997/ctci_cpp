#include <iostream>
#include <vector>

using namespace std;

class HashTable {
    private:
        vector<int> table;
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
            table.at(hash) = item;
        }
        void pop(int item) {
            int hash = get_hash(item);
            table.erase(hash);
        }
        int get(int hash) {
            return table.at(hash);
        }
        int exists(int item) {
            int hash = get_hash(item);
            if(get(hash)==item) {
                return 1;
            }
            else {
                return 0;
            }
        }
        void print_table() {
            for(auto i=table.begin();i!=table.end();i++) {
                cout<<*i<<" ";
            }
            cout<<"\n";
        }
};

int main() {
    HashTable t1(10);
    t1.put(18);
    t1.put(34);
    t1.put(55);
    t1.print_table();
    cout<<t1.exists(55)<<"\n";
    return 0;
}
