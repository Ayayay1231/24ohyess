#include<iostream>
using namespace std;


class Node{
    public:
    	int data;
    	Node *next;
    	~Node();
};

class List{
	public:
		Node *root;
		int size;
		void show();
		void append(int);
		void insert(int,int);
		void remove(int);
};

Node::~Node(){
    cout << data << " was deleted.\n";
}

void List::insert(int d,int idx){	
	Node *n = new Node;
	n->data = d;
	
	if(idx == 0){
		n->next = root;
		root = n;
		return;
	}
	Node *current = root;
	for(int i = 0; i < idx-1;i++){
		current = current->next;
	}
	n->next = current->next;
	current->next = n;		
}

void List::show(){
	Node *current = root;
	cout << current->data << " ";	
	while(current->next){
		current = current->next;
		cout << current->data << " ";
	}	
}

void List::append(int d){	
	Node *n = new Node;
	n->data = d; n->next = NULL;
	if(root == NULL) root = n;
	else{
		Node *current = root;
		while(current->next){
			current = current->next;
		}
		current->next = n;
	}
	size++;
}

void List::remove(int idx){
    
    if(root == NULL) return;

    Node *temp;

    
    if(idx == 0){
        temp = root;         // เก็บตัวแรกไว้ใน temp
        root = root->next;   // ขยับ root ไปชี้ที่ Node ตัวที่สองแทน
        delete temp;         // ลบ temp ทิ้ง (ตรงนี้จะปริ้น ... was deleted.)
        size--;
        return;
    }

    // 3. กรณีที่ต้องการลบ Node ตำแหน่งอื่นๆ
    Node *current = root;
    // วนลูปไปหา Node ตำแหน่ง "ก่อนหน้า" ตัวที่เราจะลบ (idx - 1)
    for(int i = 0; i < idx - 1; i++){
        
        if(current->next == NULL) return; 
        current = current->next;
    }

    temp = current->next; // temp คือ Node ตัวที่เราต้องการจะลบ
    if(temp == NULL) return;

    
    current->next = temp->next; 
    delete temp; 
    size--;
}

