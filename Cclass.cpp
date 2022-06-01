//���� ������ �����ε�
 

//�Ű������� �޴� Ÿ�� 
Point operator*(const Point& p){
		Point res(xpos*p.xpos,ypos*p.ypos);
		return res;
	}

//���� ������ �޴� Ÿ�� 

Point operator*(const Point& p){
		Point res(xpos*p.xpos,ypos*p.ypos);
		return res;
	}

//���������� ������ �񱳿�����  

    friend bool operator==(const Point& p1, const Point& p2);
    friend bool operator!=(const Point& p1, const Point& p2);
    


bool operator==(const Point& p1, const Point& p2) {
    return p1.xpos == p2.xpos && p1.ypos == p2.ypos;
}

bool operator!=(const Point& p1, const Point& p2) {
    return !(p1 == p2);
}



//���� ���� �Ǵ� ���� ������ 
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


Point& operator++(Point& p1){ //�ڱ��ڽ��� �ٲٴ� & ����
	p1.xpos+=1;
	p1.ypos+=1;
	return p1;
}
Point& operator--(Point& p2){ //�ڱ��ڽ��� �ٲٴ� & ����
	p2.xpos-=1;
	p2.ypos-=1;
	return p2;
}
int main(void)
{
    cout << "���� ���� ������" << endl;
    Point p1(1, 2);
    Point& p2 = ++p1;
    p1.ShowPosition();
    p2.ShowPosition();
    ++(++p2);
    p1.ShowPosition();
    p2.ShowPosition();
    
    cout << endl << "���� ���� ������" << endl;
    Point p3(11, 22);
    Point& p4 = --p3;
    p3.ShowPosition();
    p4.ShowPosition();
    --(--p4);
    p3.ShowPosition();
    p4.ShowPosition();
    
    return 0;
}

//���θ��� Point ��ȣ �ݴ�� �����ϱ�  
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

//���θ��� Point �ڸ� �ݴ�� �����ϱ� 
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
