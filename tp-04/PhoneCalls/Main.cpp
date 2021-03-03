#include "Person.h"
#include "Phone.h"

int main()
{
    // Person paul{"Paul", 3};
    // Phone phone{paul};
    // paul.set_position(8);
    // phone.ring();
    // std::cout << "Position : " << paul.get_position() << std::endl;

    /*Person paul{"Paul", 3};

    HomePhone close_phone{paul, 3};
    close_phone.ring(); // Hi! Paul on the phone.

    HomePhone far_phone{paul, -10};
    far_phone.ring(); // This is the voicemail of Paul. Please leave a message.
    */

    /*Person paul{"Paul", 3};
    HomePhone far_phone{paul, -10};

    const Phone &normal_phone = far_phone;
    normal_phone.ring(); // This is the voicemail of Paul. Please leave a message.

    Person georges{"Georges", 3};
    MobilePhone mobile_phone{georges};

    const Phone &normal_phone_2 = mobile_phone;
    normal_phone_2.ring(); // Hi! Georges on the phone.

    Person james{"James", 3};
    Phone normal_phone_3{james}; // Doesn't compile!
    */

    Person paul{"Paul", 3};
    /*HomePhone far_phone{paul, -10};

    const Phone normal_phone = far_phone;
    normal_phone.ring();*/
    MobilePhone mobile_phone { paul };
    return 0;
}

// Réponse à l'exercice 1