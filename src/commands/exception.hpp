#ifndef MYEXCEPTION_HPP
#define MYEXCEPTION_HPP

#include <exception>
using namespace std;

struct TidakAdaMakananException : public exception  {
	const char* what() const throw() {
		return R"(Tidak ada makanan dalam penyimpanan.

		██╗     ███╗   ███╗ █████╗  ██████╗ 
		██║     ████╗ ████║██╔══██╗██╔═══██╗
		██║     ██╔████╔██║███████║██║   ██║
		██║     ██║╚██╔╝██║██╔══██║██║   ██║
		███████╗██║ ╚═╝ ██║██║  ██║╚██████╔╝
		╚══════╝╚═╝     ╚═╝╚═╝  ╚═╝ ╚═════╝        
										)";
	}
};


#endif