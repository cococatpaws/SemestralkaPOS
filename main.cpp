#include "utility/heap_monitor.h"
#include "socket/my_socket.h"
#include "hra/hra.h"
using namespace std;


int main() {
    initHeapMonitor();
    Hra hra;
    hra.hraj();

    return 0;
}
