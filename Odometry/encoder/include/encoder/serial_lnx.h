#ifndef SERIALPORT_H_
#define SERIALPORT_H_
 
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

//<ENUM> for setting the PARITY argument.Parity can be 0 <NONE> , 1 <ODD> and 2 <EVEN>
enum serial_parity  { spNONE,  spODD, spEVEN };

//Class for serial communication.
class Tserial {
	private:
		int fd_serialport;
		char              port[10];                      // port name "com1",...//dev//ttyS0
		int               rate;                          // baudrate
		serial_parity     parityMode;
		bool v;
	        //HANDLE            serial_handle;                 // ...
	public:
	        Tserial();
            	~Tserial();
//I believe there is no use of below 2 <connect> functions as <encoder.cpp> uses only the 3rd connect function in the publishiing the data from the encoder.
		int connect ();
		int connect (char * device);
		int  connect  (char *device, int rate_arg, serial_parity parity_arg,bool verbose=false);
		void disconnect(void);
		
		 
		int sendArray(char *buffer, int len);
		int getArray (char *buffer, int len);
		 
		int bytesToRead();
		void clear();

		void  sendChar(char c);
		char  getChar(void);

};
 
#endif /* SERIALPORT_H_ */
