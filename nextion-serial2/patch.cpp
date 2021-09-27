// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/WaylandM/EasyNextionLibraryXOD"

//Include C++ libraries
#include <EasyNextionLibraryXOD.h>

node {
    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = EasyNex*;
    }

    // Create an object of class EasyNex
    EasyNex eznex = EasyNex(Serial2);

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        // Initialize the EasyNex object with user specified Baud rate
        eznex.begin(getValue<input_BAUD>(ctx));
        emitValue<output_DEV>(ctx, &eznex);
    }
}
