#include "BluetoothSocket.h"
#include <unistd.h>
using namespace std;

void forward(int8_t& motorspeed){
	BP.set_motor_power(PORT_C, motorspeed);
	BP.set_motor_power(PORT_B, motorspeed);
}

void left(int8_t& speed, int8_t& motorspeed){
	BP.set_motor_power(PORT_C, -speed);
	BP.set_motor_power(PORT_B, motorspeed);
}

void right(int8_t& speed, int8_t& motorspeed){
	BP.set_motor_power(PORT_C, motorspeed);
	BP.set_motor_power(PORT_B, -speed);
}

void brake(){
	BP.set_motor_power(PORT_C, 0);
	BP.set_motor_power(PORT_B, 0);
}



int main() {
	BluetoothServerSocket serversock(2, 1);  //2 is het channel-number
	cout << "listening" << endl;
	while(true) {
		BluetoothSocket* clientsock = serversock.accept();
		cout << "accepted from " << clientsock->getForeignAddress().getAddress() << endl;
		MessageBox& mb = clientsock->getMessageBox();

		//motor settings
		int speed = 10;


		string input;
		while(mb.isRunning()) {
			input = mb.readMessage();  //blokkeert niet
			//if(input != "") cout << endl << input << endl;
			//doe andere dingen.
			if(input == "UP"){
				forward(speed);
			}else if(input == "DOWN"){

			}else if(input == "LEFT"){
				left(speed);
			}else if(input == "RIGHT"){
				right(speed);
			}else if(input == "FIRE"){
				brake();
			}else if(input == "A"){

			}else if(input == "B"){

			}else if(input == "C"){

			}

			//
			//cout << ".";
			//cout.flush();
			usleep(500000); // wacht 500 ms
		}

		clientsock->close();

	}
}
