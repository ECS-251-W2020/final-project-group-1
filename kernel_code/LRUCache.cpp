#include <iostream>
#include <map>
using namespace std;
class DLinkedNode {
	public:
	int key;
    int value;
	DLinkedNode *prev, *next;
	DLinkedNode(int k, int v): key(k), value(v), prev(NULL), next(NULL) {}
};

class DLList {
	DLinkedNode *start, *end;
	
    //check if cache has no page in it
	bool isEmpty() {
		return end == NULL;
	}

	public:
	DLList(): start(NULL), end(NULL) {}
	
	DLinkedNode* add_current_page_to_start(int key, int value) {
		DLinkedNode *page = new DLinkedNode(key, value);
       
		if(start && end) {
             //add page to the start and point the previous first page to the current one and vice versa
            page->next = start;
			start->prev = page;
			start = page;
		}
		else {
             //if the page being added is the first page and cache is empty
			start = end = page;
		}
		return page;
	}

	void push_page_to_start(DLinkedNode *page) {
		if(page==start) {
            //if there is no page in cache
			return;
		}
		if(page == end) {
            //if there is only one page in cache
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
        //check if the cache is empty
		if(isEmpty()) {
			return;
		}
		if(start == end) {
            //if there is only one page in the cache, free the page
			delete end;
			start = end = NULL;
		}
		else {
			DLinkedNode *temp = end;
			end = end->prev;
			end->next = NULL;
			delete temp;
		}
	}
	DLinkedNode* get_rear_page() {
		return end;
	}
	
};

class LRUCache{
	int capacity, cacheSize;
	DLList *pageList;
	map<int, DLinkedNode*> cacheMap;

	public:
    LRUCache(int capacity) {
    	this->capacity = capacity;
    	cacheSize = 0;
        pageList = new DLList();
        cacheMap = map<int, DLinkedNode*>();
    }
    
    //code to get the value of the key that exists in the cache
    int get(int key) {
        if(cacheMap.find(key)==cacheMap.end()) {
            //if key is not present in the memory
        	return -1;
        }
        int val = cacheMap[key]->value;

        // This code pushed the page to the head or the start
        pageList->push_page_to_start(cacheMap[key]);
        return val;
    }
    
    void put(int key, int value) {
        // If cache already has the key, then the given value is updated and page is moved to the start
    	if(cacheMap.find(key)!=cacheMap.end()) {
    		cacheMap[key]->value = value;
    		pageList->push_page_to_start(cacheMap[key]);
    		return;
    	}

        if(cacheSize == capacity) {
        	// if the cache is full then remove end page
        	int k = pageList->get_rear_page()->key;
        	cacheMap.erase(k);
        	pageList->remove_rear_page();
        	cacheSize--;
        }

        // insert a new page to the start of the queue if cache is not full
        DLinkedNode *page = pageList->add_current_page_to_start(key, value);
        cacheSize++;
        cacheMap[key] = page;
    }

    ~LRUCache() {
    	map<int, DLinkedNode*>::iterator iNew;
    	for(iNew=cacheMap.begin();iNew!=cacheMap.end();iNew++) {
    		delete iNew->second;
    	}
    	delete pageList;
    }
};

