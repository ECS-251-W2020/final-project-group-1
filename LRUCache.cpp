#include <iostream>
#include <map>
using namespace std;
class Node {
	public:
	int key, value;
	Node *prev, *next;
	Node(int k, int v): key(k), value(v), prev(NULL), next(NULL) {}
};

class DLList {
	Node *start, *end;
	
	bool isEmpty() {
		return end == NULL;
	}

	public:
	DLList(): start(NULL), end(NULL) {}
	
	Node* add_page_to_head(int key, int value) {
		Node *page = new Node(key, value);
		if(!start && !end) {
			start = end = page;
		}
		else {
			page->next = start;
			start->prev = page;
			start = page;
		}
		return page;
	}

	void move_page_to_head(Node *page) {
		if(page==start) {
			return;
		}
		if(page == end) {
			end = end->prev;
			end->next = NULL;
		}
		else {
			page->prev->next = page->next;
			page->next->prev = page->prev;
		}

		page->next = start;
		page->prev = NULL;
		start->prev = page;
		start = page;
	}

	void remove_rear_page() {
		if(isEmpty()) {
			return;
		}
		if(start == end) {
			delete end;
			start = end = NULL;
		}
		else {
			Node *temp = end;
			end = end->prev;
			end->next = NULL;
			delete temp;
		}
	}
	Node* get_rear_page() {
		return end;
	}
	
};

class LRUCache{
	int capacity, size;
	DLList *pageList;
	map<int, Node*> pageMap;

	public:
    LRUCache(int capacity) {
    	this->capacity = capacity;
    	size = 0;
        pageList = new DLList();
        pageMap = map<int, Node*>();
    }
    
    int get(int key) {
        if(pageMap.find(key)==pageMap.end()) {
        	return -1;
        }
        int val = pageMap[key]->value;

        // move the page to front
        pageList->move_page_to_head(pageMap[key]);
        return val;
    }
    
    void put(int key, int value) {
    	if(pageMap.find(key)!=pageMap.end()) {
    		// if key already present, update value and move page to head
    		pageMap[key]->value = value;
    		pageList->move_page_to_head(pageMap[key]);
    		return;
    	}

        if(size == capacity) {
        	// remove end page
        	int k = pageList->get_rear_page()->key;
        	pageMap.erase(k);
        	pageList->remove_rear_page();
        	size--;
        }

        // add new page to head to Queue
        Node *page = pageList->add_page_to_head(key, value);
        size++;
        pageMap[key] = page;
    }

    ~LRUCache() {
    	map<int, Node*>::iterator i1;
    	for(i1=pageMap.begin();i1!=pageMap.end();i1++) {
    		delete i1->second;
    	}
    	delete pageList;
    }
};