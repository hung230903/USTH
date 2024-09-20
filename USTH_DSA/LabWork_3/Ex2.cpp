#include <bits/stdc++.h>

using namespace std;

struct Website {
    string url;
    string title;
    Website* next;

    Website(string url, string title) {
        this->url = url;
        this->title = title;
        this->next = nullptr;
    }
};

struct Stack {
    Website* top;

    Stack() {
        top = nullptr;
    }

    void push(string url, string title) {
        Website* new_website = new Website(url, title);
        new_website->next = top;
        top = new_website;
    }

    void pop() {
        Website* temp = top;
        top = top->next;
        delete temp;
    }

    Website* peek() {
        return top;
    }
};

void display(Website* website) {
    cout << "URL: " << website->url << endl;
    cout << "Title: " << website->title << endl;
    cout << "---" << endl;
}

int main() {
    Stack Backward;
    Stack Foward;

    Backward.push("https://www.google.com", "Google");
    Backward.push("https://www.instagram.com", "Instagram");
    Backward.push("https://www.tiktok.com", "Tiktok");
    Backward.push("https://www.youtube.com", "YouTube");
    Backward.push("https://moodle.usth.edu.vn", "Moodle");

    Website* current_website = Backward.peek();
    cout << "Current website: " << endl;
    display(current_website);

    Foward.push(current_website->url, current_website->title);
    Backward.pop();

    current_website = Backward.peek();
    cout << "Current website after backward: " << endl;
    display(current_website);

    Backward.push(Foward.peek()->url, Foward.peek()->title);
    Foward.pop();

    current_website = Backward.peek();
    cout << "Current website after forward: " << endl;
    display(current_website);
}