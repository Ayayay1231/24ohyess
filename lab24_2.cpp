#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void printList(list<string> s){
	list<string>::iterator i;
	for( i = s.begin(); i != s.end(); i++){
		cout << *i << " ";
	}		
	cout << "\n";	
}

int main(){
	
	list<string> line_up;
	list<string>::iterator loc;
	
	line_up.push_back("Alice");
	line_up.push_back("Bob");
	
	loc = find(line_up.begin(),line_up.end(),"Bob");
	line_up.insert(loc,"Oscar");
	
	// 1. Luffy, Sanji, Nami มาต่อแถวด้านหลังตามลำดับ
    line_up.push_back("Luffy");
    line_up.push_back("Sanji");
    line_up.push_back("Nami");
    
    // 2. 2 คนที่หัวแถวได้เข้าไปในส้วมแล้ว (เอาออกจากหัวแถว 2 คน)
    line_up.pop_front();
    line_up.pop_front();
    
    // 3. Narutu มาแทรกแถวหลัง Luffy
    loc = find(line_up.begin(), line_up.end(), "Luffy");
    loc++; // ขยับ Iterator ไปอยู่ด้านหลัง Luffy
    line_up.insert(loc, "Narutu"); // สังเกตว่าโจทย์พิมพ์ชื่อ Narutu
    
    // 4. Prayath ท้องเสียสุดๆ มาแทรกคิวหน้าสุด
    line_up.push_front("Prayath");
    
    // 5. Tony ยอมไม่ได้เลยมาแทรกด้านหลัง Prayath
    loc = find(line_up.begin(), line_up.end(), "Prayath");
    loc++; // ขยับ Iterator ไปอยู่ด้านหลัง Prayath
    line_up.insert(loc, "Tony");
    
    // 6. Bob ทนไม่ไหว ออกไปที่อื่น (ลบ Bob ออกจาก List)
    line_up.remove("Bob");
    
    // 7. 3 คนที่หัวแถวได้เข้าไปในส้วมแล้ว
    line_up.pop_front();
    line_up.pop_front();
    line_up.pop_front();
	
	printList(line_up);
		
	return 0;
}
