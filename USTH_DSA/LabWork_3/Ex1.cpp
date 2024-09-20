#include <bits/stdc++.h>

using namespace std;

struct Item {
    string name;
    int quantity;
    string price;
};

void init(queue<Item> &stock) {
    stock.push({"Item 1", 9, "500.000 kVND" });
    stock.push({"Item 2", 5, "400.000 kVND"});
    stock.push({"Item 3", 7, "250.000 kVND"});
    stock.push({"Item 4", 0, "200.000 kVND"});
}

void display(const queue<Item> &stock){
    cout << "---" << endl;
    queue<Item> temp = stock;
    while (!temp.empty()){
        Item item = temp.front();
        cout << item.name << " - Quantity: " << item.quantity << ", Price: " << item.price << endl;
        temp.pop();
    }
    cout << "---" << endl;
}

void enqueue(queue<pair<int, int>> &customers, int id_customers, int items_to_buy){
    customers.push(make_pair(id_customers, items_to_buy));
}

void dequeue(queue<Item> &stock, queue<pair<int, int>> &customers){
    Item item = stock.front();
    stock.pop();

    pair<int, int> customer = customers.front();
    customers.pop();

    if (item.quantity < customer.second){
        cout << "WARNING!: All the items has been run out in " << item.name << endl;
        customers.push(customer);  
    } else {
        item.quantity -= customer.second;
        cout << "Customer " << customer.first << " successfully purchased " << customer.second << " items in " << item.name << endl;
        stock.push(item);  
    }
}

int main() {
    queue<Item> stock;
    queue<pair<int, int>> customers;

    init(stock);
    display(stock);

    enqueue(customers, 1, 8);
    enqueue(customers, 2, 5);
    enqueue(customers, 3, 2);
    enqueue(customers, 4, 1);

    dequeue(stock, customers);
    dequeue(stock, customers);
    dequeue(stock, customers);
    dequeue(stock, customers);

    display(stock);
}