#include "project.h"

int main()
{
    Psystem();
    DoctorList dl;
    dl.insertDoctor("Dr. Smith", "Cardiology");
    dl.insertDoctor("Dr. Johnson", "Neurology");
    dl.insertDoctor("Dr. Lee", "Oncology");
    dl.displayDoctor();
    dl.deleteDoctor("Dr. Johnson");
    dl.displayDoctor();

    return 0;
}
