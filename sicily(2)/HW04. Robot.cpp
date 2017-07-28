#include <iostream>
#include <map>

using namespace std;

class Position {

public:
         int x;
         int y;
};

/*******************************************/
class Robot {
public:
         Robot();                 /* default constructor, initialize at (0,0) */
         Robot(Position pos);     /* initialize at pos */
         void Move(char Dir);     /* Dir could be 'N', 'E', 'S', 'W', for other characters, the robot don¡¯t move */
         Position GetPosition();  /* return current position */
private:
         Position currentPos;
};

Robot::Robot() {
	currentPos.x = 0;
	currentPos.y = 0;
}

Robot::Robot(Position pos) {
	currentPos.x = pos.x;
	currentPos.y = pos.y;
}

void Robot::Move(char Dir) {
	if(Dir == 'N') {                      // ÉÏ 
		currentPos.x += 0;
		currentPos.y += 1;
	}
	else if(Dir == 'E') {                 // ÓÒ 
		currentPos.x += 1;
		currentPos.y += 0;
	}
	else if(Dir == 'S') {                 // ÏÂ 
		currentPos.x += 0;
		currentPos.y -= 1;
	}
	else if(Dir == 'W') {                 // ×ó 
		currentPos.x -= 1;
		currentPos.y += 0;
	}
}
	
Position Robot::GetPosition() {
	return currentPos;
}
/*******************************************/

int main() {
    Position c;
    c.x = 0;
    c.y = 1;
    Robot a;
    cout << a.GetPosition().x << ' ' << a.GetPosition().y << endl;
    Robot b( c );
    cout << b.GetPosition().x << ' ' << b.GetPosition().y << endl;
    b.Move('E');
    cout << b.GetPosition().x << ' ' << b.GetPosition().y << endl;
    b.Move('N');
    cout << b.GetPosition().x << ' ' << b.GetPosition().y << endl;
    b.Move('W');
    cout << b.GetPosition().x << ' ' << b.GetPosition().y << endl;
    b.Move('S');
    cout << b.GetPosition().x << ' ' << b.GetPosition().y << endl;

    b.Move('s');
    cout << b.GetPosition().x << ' ' << b.GetPosition().y << endl;
    return 0;
}

