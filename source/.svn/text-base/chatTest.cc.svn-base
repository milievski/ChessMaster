#include <iostream>
#include <vector>
#include <utility>
#include "Chat.h"
using namespace std;

void printMessages(Chat& room) {
system("clear");
for(auto m : room.getMessages()) {
	cout << m.first << ": " << m.second << endl << endl;

}
}

int main() {

Chat room("alice", "bob");

string user = "alice";

string message;

getline(cin, message);

while(message!="q") {

room.postMessage(user, message);
printMessages(room);

if(user=="alice")
user = "bob";
else 
user = "alice";


getline(cin, message);
}

	return 0;
}