#include <encoder/encoder.h>
 
//The File Opens a Serial Port and Reads Data. The Data Received is in form of ASCII characters.
//The Data is the Reading of the ENCODERS. The  2 Encoder values are separated by " ".

namespace encoder {
//The Constructor opens the port for communication.
//It takes the arguments of ROBOTEQ port and BAUDRATE.
//**Note: The taken arguments are not passed while opening the port.CHECK the 3rd line below.
//The <BOT_COM_PORT> and <BOT_BAUD_RATE> are defined in <DEVICES.h>

	Encoder::Encoder(char *port, int baudRate) {
		serialConnection = new Tserial();
        	serialConnection->connect(BOT_COM_PORT, BOT_BAUD_RATE, spNONE);
        	usleep(100);
		}
	
//The Function manupulated the read data and calculates to find the encoder left and right readings and returns the calculated value.

	EncoderData Encoder::fetchEncoderData() {	
		EncoderData returnValue;
		char input = ' ';
		
		returnValue.leftCount = 0;
		returnValue.rightCount = 0;
		
		do {
			input = serialConnection->getChar();
			if (input < 58 && input > 47) {
				returnValue.leftCount *= 10;
				returnValue.leftCount += input - 48;
			}
		} while (input != ' ');
		
		do {
			input = serialConnection->getChar();
			if (input < 58 && input > 47) {
				returnValue.rightCount *= 10;
				returnValue.rightCount += input - 48;
			}
		} while (input != ' ');
		
		return returnValue;
		
	}

}
