#include "BluetoothSocket.h"
using namespace std;

int main() {
	BluetoothServerSocket serversock(2, 1);
	cout << "listening" << endl;
	while(true) {
		BluetoothSocket* clientsock = serversock.accept();
		cout << "accepted from " << clientsock->getForeignAddress().getAddress() << endl;
		iostream& sockstream = clientsock->getStream();
		try {
			
			
			string input;
			while(sockstream >> input) {
				cout << "recieved: " << input << endl;
			}
			
		}
		catch(BluetoothException& be) {
			cout << "connection lost" << endl;
		}
			
	}
}
		
		
			