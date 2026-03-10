#include<iostream>
#include <set>
using namespace std;

int count(int arr[], int size) {
    set<int> uniqueNumbers; // สร้าง set สำหรับเก็บตัวเลขจำนวนเต็ม
    
    // วนลูปนำข้อมูลจาก Array มาใส่ใน Set
    for(int i = 0; i < size; i++) {
        uniqueNumbers.insert(arr[i]); // ตัวที่ซ้ำ set จะจัดการข้ามให้เอง
    }
    
    return uniqueNumbers.size(); // ส่งคืนจำนวนสมาชิกใน set (ซึ่งก็คือจำนวนตัวเลขที่ไม่ซ้ำ)
}


int main(){	
	int data[] = {1,2,4,5,4,8,2,1,2,4,6,1,4,4,4,2,1,0,12}; 
	
	cout << "There are " << count(data,sizeof(data)/sizeof(int)); 
	cout << " different numbers in data.";
	
	return 0;
}
