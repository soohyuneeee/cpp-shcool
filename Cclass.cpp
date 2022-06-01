//단항 연산자 오버로딩
 

//매개변수를 받는 타입 
Point operator*(const Point& p){
		Point res(xpos*p.xpos,ypos*p.ypos);
		return res;
	}

//전역 변수를 받는 타입 

Point operator*(const Point& p){
		Point res(xpos*p.xpos,ypos*p.ypos);
		return res;
	}

//전역변수로 설정한 비교연산자  

    friend bool operator==(const Point& p1, const Point& p2);
    friend bool operator!=(const Point& p1, const Point& p2);
    


bool operator==(const Point& p1, const Point& p2) {
    return p1.xpos == p2.xpos && p1.ypos == p2.ypos;
}

bool operator!=(const Point& p1, const Point& p2) {
    return !(p1 == p2);
}



//전위 증가 또는 감소 연산자 
    Point& operator++(){
    	xpos+=1;
    	ypos+=1;
    	return *this;
	}
	Point& operator--(){
    	xpos-=1;
    	ypos-=1;
    	return *this;
	}
    
    friend Point& operator++(Point& p1);
    friend Point& operator--(Point& p2);
};


Point& operator++(Point& p1){ //자기자신을 바꾸니 & 붙임
	p1.xpos+=1;
	p1.ypos+=1;
	return p1;
}
Point& operator--(Point& p2){ //자기자신을 바꾸니 & 붙임
	p2.xpos-=1;
	p2.ypos-=1;
	return p2;
}
int main(void)
{
    cout << "전위 증가 연산자" << endl;
    Point p1(1, 2);
    Point& p2 = ++p1;
    p1.ShowPosition();
    p2.ShowPosition();
    ++(++p2);
    p1.ShowPosition();
    p2.ShowPosition();
    
    cout << endl << "전위 감소 연산자" << endl;
    Point p3(11, 22);
    Point& p4 = --p3;
    p3.ShowPosition();
    p4.ShowPosition();
    --(--p4);
    p3.ShowPosition();
    p4.ShowPosition();
    
    return 0;
}

//새로만든 Point 부호 반대로 저장하기  
#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0): xpos(x), ypos(y) {}
    void ShowPosition() const {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point operator-(){
		Point p(-xpos,-ypos);
		return p;
	}
    
   
    friend Point operator-(Point p);
};


Point operator-(const Point p){
	return Point(-p.xpos,-p.ypos);
}
int main(void)
{
	Point pos1(1, 2);
 	Point pos2= -pos1;
 	pos2.ShowPosition();
    return 0;
}

//새로만든 Point 자리 반대로 저장하기 
#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0): xpos(x), ypos(y) {}
    void ShowPosition() const {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    
    Point operator~(){
    	Point p(ypos,xpos);
    	return p;
	}
    
    friend Point operator~(Point p);
};


Point operator~(const Point p){
	return Point(p.ypos,p.xpos);
}



int main(void)
{
	Point pos1(1, 2);
 	Point pos2= ~pos1;
 	pos2.ShowPosition();
    return 0;
}
